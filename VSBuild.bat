@echo off
title Building Win32 Release ProjectChocolat...
SET COMPILER="%VS120COMNTOOLS%..\IDE\devenv"

echo Generate ProjectChocolat...
call GenerateProject.bat

echo Compile...
if not exist "ProjectChocolat.sln" goto error
%COMPILER% "ProjectChocolat.sln" /rebuild "Release"
if errorlevel 1 goto error
goto :eof

:error
echo "error"
exit /b 1

:end
echo "success"
exit /b 0
