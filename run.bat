@echo off

for /F "delims=#" %%E in ('"prompt #$E# & for %%E in (1) do rem"') do set "ESCchar=%%E"
set "green=%ESCchar%[92m"
set "red=%ESCchar%[91m"

set "file_loc=%~1"
for %%F in ("%file_loc%") do (
    set "filename=%%~nF"
)
g++ "%file_loc%" -o "bin/%filename%.exe"

if %errorlevel% neq 0 (
    echo %red%Compilation failed.
    pause
    exit /b 1
) else (
    echo %green%32m Compilation was successful!!
)
echo Running %filename%.exe.... 
"bin/%filename%.exe" < input.in > output.out
echo Execution was successful!
pause