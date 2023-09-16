@echo off

set "file_loc=%~1"
for %%F in ("%file_loc%") do (
    set "filename=%%~nF"
)
g++ "%file_loc%" -o "bin/%filename%.exe"

"bin/%filename%.exe" < input.in > output.out
echo Execution was successful!
pause