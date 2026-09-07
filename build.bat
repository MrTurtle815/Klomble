:: currently the only way to compile the project is to run this .bat file although i do plan to add cmake in the future!

if not exist bin mkdir bin
g++ src/Application/main.cpp src/Application/application.cpp src/Render/render.cpp src/Physics/physics.cpp ^
imgui-files/rlImGui.cpp imgui-files/imgui_demo.cpp imgui-files/imgui_draw.cpp imgui-files/imgui_tables.cpp imgui-files/imgui_widgets.cpp imgui-files/imgui.cpp ^
-o bin/Klomble -Ilibraries/include -Llibraries/lib ^
-lraylib -lopengl32 -lgdi32 -lwinmm
pause
