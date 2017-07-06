@echo off
REM Author: JVKetchup

echo Building your project...
cd %cd%
(
echo MAINICON ICON "Icon.ico"
) > Icon.rc
windres Icon.rc Icon.o
g++ *.cpp Icon.o -std=c++11 -o "App.exe"
echo Build complete.
pause
exit