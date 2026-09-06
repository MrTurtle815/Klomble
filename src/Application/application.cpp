// headers

#include "../values.h"
#include "../Render/render.h"
#include "application.h"

// utils

#include <stdio.h>

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

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_FREE);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

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