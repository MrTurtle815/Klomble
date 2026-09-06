// headers

#include "../values.h"
#include "../Render/render.h"
#include "../Scene/scene.h"
#include "application.h"

// utils

#include <stdio.h>
#include <memory>

application::application()
{
    printf("Starting Program...");
    application::run();
}

void application::run()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

    Camera3D camera = { 0 };
    camera.position = (Vector3){0.0f, 0.0f, 10.0f};
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    auto brick = std::make_unique<Brick>(
    Vector3{0.0f, 0.0f, 0.0f}, 
    Vector3{2.0f, 1.0f, 4.0f}, 
    RED);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_FREE);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

            brick->draw();
            renderScene();

            EndMode3D();
        
        EndDrawing();
    }

    CloseWindow();
}

application::~application()
{
    printf("Closing Program...");
}