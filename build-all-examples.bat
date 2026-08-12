:: this batch file builds all of the C++ examples for klomble! It may take a while!

@echo off

if not exist bin mkdir bin

echo [1/2] compiling spinningShapes2D.cpp
g++ examples\spinningShapes2D.cpp -o bin\spinningShapes2D.exe -lopengl32 -lgdi32 -luser32

echo [2/2] compiling spinningShapes3D.cpp
g++ examples\spinningShapes3D.cpp -o bin\spinningShapes3D.exe -lopengl32 -lgdi32 -luser32

pause