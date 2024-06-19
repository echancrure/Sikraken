#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <io.h>

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
            //printf("DEBUG: found file \t%s\n", filename);
            if (filename[strlen(filename) - 2] == '.' && filename[strlen(filename) - 1] == 'c') {   //only adding .c files
                filenames[nbCFiles] = (char *)malloc(strlen(filename) + 1);
                strcpy_s(filenames[nbCFiles], strlen(filename) + 1, filename);
                filenames[nbCFiles][strlen(filenames[nbCFiles]) - 2] = '\0'; //cuting out .c
                //printf("DEBUG: added file \t%s\n", filenames[nbCFiles]);
                nbCFiles++;
            }
        }
    } while (FindNextFileW(file_handle, &file_data) != 0);
    FindClose(file_handle);
    return nbCFiles;
}

// Return a foldername which begins with the second parameter (Prefix)
char* find_folder_by_prefix(char* path, char* prefix) {
    HANDLE hFind;
    WIN32_FIND_DATAW FindData;
    wchar_t search_path[MAX_PATH];
    char* folder_name = NULL;
    wchar_t folder_name_w[MAX_PATH];
    int folder_name_len;

    // Convert the pathRegressionTests and prefix to wide character strings
    MultiByteToWideChar(CP_UTF8, 0, path, -1, search_path, MAX_PATH);
    MultiByteToWideChar(CP_UTF8, 0, prefix, -1, search_path + wcslen(search_path), MAX_PATH - wcslen(search_path));

    // Construct the search pathRegressionTests by appending the prefix to the pathRegressionTests
    //wcscat_s(search_path, MAX_PATH, L"\\");
    wcscat_s(search_path, MAX_PATH, L"*");

    // Find the first matching folder in the search pathRegressionTests
    hFind = FindFirstFileW(search_path, &FindData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                if (wcscmp(FindData.cFileName, L".") != 0 && wcscmp(FindData.cFileName, L"..") != 0) {// Found a non-hidden folder
                    wcscpy_s(folder_name_w, MAX_PATH, FindData.cFileName);
                    folder_name_len = WideCharToMultiByte(CP_UTF8, 0, folder_name_w, -1, NULL, 0, NULL, NULL);
                    folder_name = (char*)malloc(folder_name_len);
                    WideCharToMultiByte(CP_UTF8, 0, folder_name_w, -1, folder_name, folder_name_len, NULL, NULL);
                    break;
                }
            }
        } while (FindNextFileW(hFind, &FindData) != 0);
        FindClose(hFind);
    }
    return folder_name;
}

int main(int argc, char* argv[]) {
    char installPath[MAX_PATH] = "";
    int preserveRegressionRun = 1;
    int i;
    for (i = 1; i < argc; i++) { //processing switches
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
    sprintf_s(pathRegressionTests, "%s%s", installPath, "\\RegressionTests\\");
    char* C_Files[200];  

    int nbCFiles = get_filenames(pathRegressionTests, C_Files);
    if (nbCFiles == 0) {
        fprintf(stderr, "\nRegression Tester Error: no C files found in directory %s\n", pathRegressionTests);
        exit(1);
    }
    printf("Starting regression testing of Sikraken on %i files\n", nbCFiles);
    for (int i = 0; i < nbCFiles; i++) {
        printf("File:\t%s.c", C_Files[i]);
        char run_preprocessor[MAX_PATH*3];
        sprintf_s(run_preprocessor, "cd \"%s\" && CL /EP /P /nologo %s.c > nul", pathRegressionTests, C_Files[i]);
        int return_code = system(run_preprocessor);
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: preprocessor returned status code %d for %s.c\n", return_code, C_Files[i]);
            exit(1);
        }
        printf("Pre-processing OK");
        char run_parser[MAX_PATH * 3];
        sprintf_s(run_parser, "cd \"%s\" && .\\..\\bin\\sikraken_parser.exe %s.c", pathRegressionTests, C_Files[i]);
        return_code = system(run_parser);
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: parser returned status code %d for %s.c\n", return_code, C_Files[i]);
            exit(1);
        }
        printf(";Parsing OK");
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
        //Options for ECLiPSe command line: -f file: compile the file (main.pl); -e goal: execute the goal
        sprintf_s(run_eclipse, "cd \"%s\" && eclipse -f \"%s\" -e \"main(\\\"%s\\\", %s, \\\".\\\", yes_ov, yes_ts)\" > nul", pathRegressionTests, main_pl_path, C_Files[i], function_name);   //see diary 19/06/2024
        printf("ECLiPSe call is: %s\n", run_eclipse);
        return_code = system(run_eclipse);        // Run ECLiPSe Prolog
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: symbolic executor returned status code %d for %s\n", return_code, C_Files[i]);
            exit(1);
        }
        printf(";Test Suite Generation OK");
        char* test_folder_name = find_folder_by_prefix(pathRegressionTests, C_Files[i]);    //find the directory name where the test suite drivers are e.g. is_even_24_06_18__16_39_59
        if (test_folder_name == NULL) {
            fprintf(stderr, "\nRegression Tester Error: Folder-prefix search unable to find folder for %s\n", C_Files[i]);
            exit(1);
        }
        char test_folder_path[MAX_PATH*2];
        sprintf_s(test_folder_path, "%s%s", pathRegressionTests, test_folder_name);
        char compile_test_case[MAX_PATH*2];
        sprintf_s(compile_test_case, "cd \"%s\" && cl /nologo %s_tests_main.c /Fe:a.exe > nul", test_folder_path, C_Files[i]);
        return_code = system(compile_test_case);    // Compile the generated test-cases
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: Test Suite compilation returned %d for compilation of %s_tests_main.c\n", return_code, C_Files[i]);
            exit(1);
        }
        printf(";Test Suite compilation OK");
        char run_test_case[MAX_PATH*2];
        sprintf_s(run_test_case, "cd \"%s\" && a.exe", test_folder_path);
        return_code = system(run_test_case);        // Run the generated test-cases
        if (return_code != 0) {
            fprintf(stderr, "\nRegression Tester Error: Test Suite run returned %d failed tests for %s\n", return_code, C_Files[i]);
            exit(1);
        }
        printf(";Test Suite execution OK\n");
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
    printf("\n***SUCCESSFUL regression tests run\n");
    return 0;
}