#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <io.h>
#include <time.h>

int const debugMode = 0;

// Return a count of the number of C files in a directory and an array of characters which each are C finenames without extensions
int get_filenames(char* directory_path, char** filenames) {
    WIN32_FIND_DATAW file_data;
    HANDLE file_handle;
    WCHAR full_path[MAX_PATH];
    int nbCFiles = 0;

    MultiByteToWideChar(CP_UTF8, 0, directory_path, -1, full_path, MAX_PATH);

    wcscat_s(full_path, MAX_PATH, L"\\*");

    file_handle = FindFirstFileW(full_path, &file_data);
    if (file_handle == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Regression Tester Error: %s not found\n", directory_path);
        exit(1);
    }
    do {
        if (!(file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            char filename[MAX_PATH];
            WideCharToMultiByte(CP_UTF8, 0, file_data.cFileName, -1, filename, MAX_PATH, NULL, NULL);
            if (debugMode) printf("DEBUG: found file \t%s\n", filename);
            if (filename[strlen(filename) - 2] == '.' && filename[strlen(filename) - 1] == 'c') {   //only adding .c files
                filenames[nbCFiles] = (char *)malloc(strlen(filename) + 1);
                strcpy_s(filenames[nbCFiles], strlen(filename) + 1, filename);
                filenames[nbCFiles][strlen(filenames[nbCFiles]) - 2] = '\0'; //cuting out .c
                if (debugMode) printf("DEBUG: added file \t%s\n", filenames[nbCFiles]);
                nbCFiles++;
            }
        }
    } while (FindNextFileW(file_handle, &file_data) != 0);
    FindClose(file_handle);
    return nbCFiles;
}

// Function to replace all backslashes with double backslashes
char* replace_backslashes(const char* input) {
    char* result = (char*)malloc((strlen(input) * 2 + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {// Copy and replace characters
        if (input[i] == '\\') {
            result[j++] = '\\';
            result[j++] = '\\';
        }
        else {
            result[j++] = input[i];
        }
    }
    result[j] = '\0';
    return result;
}

int main(int argc, char* argv[]) {
    clock_t start, end;
    start = clock(); 
    char installPath[MAX_PATH] = "";
    int preserveRegressionRun = 1;
    for (int i = 1; i < argc; i++) { //processing switches
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'M':  //specifies the install directory of Sikraken
                    if (_access(&argv[i][2], 0) == -1) {    //checks if &argv[i][2] is a valid directory
                        fprintf(stderr, "Regression Tester Error: indicated install directory (via -M switch): %s , cannot be accessed\n", &argv[i][2]);
                        exit(1);
                    }
                    strcpy_s(installPath, strlen(&argv[i][2])+1, &argv[i][2]);
                    break;
                case 'e':   //'erase' indicates that the regression test run folders should be deleted
                    preserveRegressionRun = 0;
                    break;
                default:
                    fprintf(stderr, "\nRegression Tester Warning: unknown option is ignored : %s\n", argv[i]);
            }
        }
    }
    if (!strcmp(installPath, "")) {
        fprintf(stderr, "\nRegression Tester Error: the installation directory of Sikraken has not been set: use -M switch on the command line\n");
        exit(1);
    }
    char main_pl_path[MAX_PATH];
    sprintf_s(main_pl_path, "%s%s", installPath, "\\SymbolicExecutor\\main.pl");
    char pathRegressionTests[MAX_PATH];
    sprintf_s(pathRegressionTests, "%s%s", installPath, "\\RegressionTests");
    ////create a new timestamped directory to store the results of this regression test run
    SYSTEMTIME st;
    GetLocalTime(&st);
    char timestamp[25];
    snprintf(timestamp, 25, "%02d_%02d_%02d__%02d_%02d_%02d", st.wYear % 100, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    char root_path_to_test_drivers[MAX_PATH];
    sprintf_s(root_path_to_test_drivers, "%s\\regression_test_run_%s", pathRegressionTests, timestamp);
    if (!CreateDirectoryA(root_path_to_test_drivers, NULL)) {
        fprintf(stderr, "\nRegression Tester Error: could not create the directory for this test run %s\n", root_path_to_test_drivers);
        exit(1);
    }
    ////retrieve all the C filenames from the regression folder 
    char* C_Files[200];  
    int nbCFiles = get_filenames(pathRegressionTests, C_Files);
    if (nbCFiles == 0) {
        fprintf(stderr, "\nRegression Tester Error: no C files found in directory %s\n", pathRegressionTests);
        exit(1);
    }
    ////iterate over all the filenames
    printf("Starting regression testing of Sikraken on %i files\n", nbCFiles);
    printf("File                       Preprocessing  |  Parsing  |  Test Suite Generation  |  Test Suite Compilation  |  Test Suite Execution\n");
    for (int i = 0; i < nbCFiles; i++) {
        const size_t filenameLen = strlen(C_Files[i]);
        const int maxPadding = 25;
        const int padding = (filenameLen < maxPadding) ? int(maxPadding - filenameLen) : 0;
        printf("%s.c%*s", C_Files[i], padding, " ");
        char run_preprocessor[MAX_PATH*3];
        sprintf_s(run_preprocessor, "cd \"%s\" && CL /EP /P /nologo %s.c > NUL 2>&1", pathRegressionTests, C_Files[i]);
        int return_code = system(run_preprocessor);
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: preprocessor returned status code %d for %s.c\n", return_code, C_Files[i]);
            exit(1);
        }
        printf("     OK        ");    //Preprocessing
        char run_parser[MAX_PATH * 3];
        sprintf_s(run_parser, "cd \"%s\" && .\\..\\bin\\sikraken_parser.exe %s.c > NUL 2>&1", pathRegressionTests, C_Files[i]);
        return_code = system(run_parser);
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: parser returned status code %d for %s.c\n", return_code, C_Files[i]);
            exit(1);
        }
        printf("     OK     ");   //Parsing
        char* function_name = NULL;
        char regressionSpecFilename[MAX_PATH];
        sprintf_s(regressionSpecFilename, "%s\\%s.sik", pathRegressionTests, C_Files[i]);
        FILE* regressionSpecFile;
        if (fopen_s(&regressionSpecFile, regressionSpecFilename, "r") == 0) {   //a Sikraken regression testing file exists for this C file
            char buffer[MAX_PATH];
            while (fgets(buffer, sizeof(buffer), regressionSpecFile) != NULL) {
                function_name = buffer;     //very basic for now: only considering the last line and can only contain the function name to test
            }
            fclose(regressionSpecFile);
        }
        else {
            function_name = C_Files[i]; //assume default: the function_name to generate tests for has the same name as the C file
        }
        char run_eclipse[MAX_PATH*2];
        char* eclipse_root_path_to_test_drivers = replace_backslashes(root_path_to_test_drivers);
        //Options for ECLiPSe command line: -f file: compile the file (main.pl); -e goal: execute the goal
        sprintf_s(run_eclipse, "cd \"%s\" && eclipse -f \"%s\" -e \"main(\\\"%s\\\", %s, \\\".\\\", \\\"%s\\\", yes_ov, no_ts)\" > nul", pathRegressionTests, main_pl_path, C_Files[i], function_name, eclipse_root_path_to_test_drivers);   //see diary 19/06/2024
        if (debugMode) printf("\nDEBUG ECLiPSe call is: %s\n", run_eclipse);
        return_code = system(run_eclipse);        // Run ECLiPSe Prolog
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: symbolic executor returned status code %d for %s\n", return_code, C_Files[i]);
            exit(1);
        }
        printf("            OK            ");    //Test Suite Generation
        char test_folder_path[MAX_PATH*2];
        sprintf_s(test_folder_path, "%s\\%s_tests", root_path_to_test_drivers, C_Files[i]);
        char compile_test_case[MAX_PATH*2];
        sprintf_s(compile_test_case, "cd \"%s\" && cl /nologo /I \"%s\" %s_tests_main.c /Fe:a.exe > nul", test_folder_path, pathRegressionTests, C_Files[i]);
        if (debugMode) printf("\nDEBUG compile_test_case call is %s\n", compile_test_case);
        return_code = system(compile_test_case);    // Compile the generated test-cases
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: Test Suite compilation returned %d for compilation of %s_tests_main.c\n", return_code, C_Files[i]);
            exit(1);
        }
        printf("            OK            ");   //Test Suite compilation
        char run_test_case[MAX_PATH*2];
        sprintf_s(run_test_case, "cd \"%s\" && a.exe > NUL 2>&1", test_folder_path);
        return_code = system(run_test_case);        // Run the generated test-cases
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: Test Suite run returned %d failed tests for %s\n", return_code, C_Files[i]);
            exit(1);
        }
        printf("          OK\n");   //Test Suite execution
        if (!preserveRegressionRun) {
            char delete_folder[MAX_PATH];
            sprintf_s(delete_folder, "rmdir /s /q \"%s\" > nul", test_folder_path); // Remove the generated tests and compiled executable
            Sleep(75);
            if (system(delete_folder) != 0) {
                Sleep(135);
                system(delete_folder);  //try again
            }
        }
    }
    printf("\n***SUCCESSFUL regression tests run***\n");
    end = clock();
    double const cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU runtime: %u'%u''\n", (int)cpu_time_used / 60, (int)cpu_time_used % 60);
    return 0;
}