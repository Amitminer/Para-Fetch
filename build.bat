@echo off
setlocal

REM Define the generator variable
REM Visual Studio 17 2022 or MinGW Makefiles
set "generator=Visual Studio 17 2022"

REM Run CMake configuration for main project
echo Running CMake configuration for main project...
if not exist build (
    mkdir build
)
cd build

REM Choose desired generators
cmake .. -G "%generator%" -DCMAKE_TOOLCHAIN_FILE="toolchain file path here"
if %errorlevel% neq 0 (
    echo CMake configuration failed.
    cd ..
    goto :error
)
cd ..

REM Build the main project using CMake
echo Building the main project...
cmake --target clean
cmake --build build --config debug
if %errorlevel% neq 0 (
    echo Build failed.
    goto :error
)

echo Script completed successfully
goto :end

:error
echo An error occurred during script execution
:end
endlocal
