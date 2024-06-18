@echo off
REM run_regression_tester.bat "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build" "C:\Users\Chris2\GoogleDrive\Sikraken"
REM Check if the correct number of arguments is provided
if "%~2"=="" (
    echo Usage: %0 ^<vcvarsall_path^> ^<installPath^>
    exit /b 1
)
REM Assign parameters to variables
set vcvarsall_path=%~1
set installPath=%~2

REM Navigate to the Visual Studio Build Directory
cd /d "%vcvarsall_path%"
if %ERRORLEVEL% NEQ 0 (
    echo REGRESSION TESTS RUN FAILURE!!!!!!!!!!!!: Failed to navigate to Visual Studio Build Directory "%vcvarsall_path%"
    exit /b 1
)

REM Call vcvarsall.bat if not already defined (causes DOS error "input line is too long"" if run again)
if not defined DevEnvDir (
    call vcvarsall.bat x86_x64
    if %ERRORLEVEL% NEQ 0 (
        echo REGRESSION TESTS RUN FAILURE!!!!!!!!!!!!: Failed to call vcvarsall.bat
        exit /b 1
    )
)

REM Navigate to the Regression Tool Directory
cd /d "%installPath%\RegressionTool"
if %ERRORLEVEL% NEQ 0 (
    echo REGRESSION TESTS RUN FAILURE!!!!!!!!!!!!: Failed to navigate to Regression Tool Directory "%installPath%\RegressionTool"
    exit /b 1
)

REM Run the regression testing tool in the correct directory and with the MSVSC environment setup
regression_tester.exe -M"%installPath%"
if %ERRORLEVEL% NEQ 0 (
    echo REGRESSION TESTS RUN FAILURE!!!!!!!!!!!!: Failed to execute regression_tester.exe
    exit /b 1
)