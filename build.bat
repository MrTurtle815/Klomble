:: currently the only way to compile the project is to run this .bat file although i do plan to add cmake in the future!

if not exist bin mkdir bin
g++ src/Application/main.cpp -o bin/Klomble -Ilibraries/include -Llibraries/lib -lraylib -lopengl32 -lgdi32 -lwinmm
pause
