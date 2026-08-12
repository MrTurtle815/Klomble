:: this batch file builds all of the C++ examples for klomble! It may take a while!

@echo off

if not exist bin mkdir bin

echo [1/3] compiling spinningShapes2D.cpp
g++ examples\spinningShapes2D.cpp -o bin\spinningShapes2D.exe -lopengl32 -lgdi32 -luser32

echo [2/3] compiling spinningShapes3D.cpp
g++ examples\spinningShapes3D.cpp -o bin\spinningShapes3D.exe -lopengl32 -lgdi32 -luser32

echo [3/3] compiling moveablePlayer2D.cpp
g++ examples\moveablePlayer2D.cpp -o bin\moveablePlayer2D.exe -lopengl32 -lgdi32 -luser32

pause
