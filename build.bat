@echo off

md bin
g++ examples\WindowsExample.cpp -o bin\KlombleWindowsExample.exe -lopengl32 -lgdi32 -luser32

echo Build successful

pause