// headers

#include "../values.h"
#include "../Render/render.h"
#include "../Scene/scene.h"
#include "../Physics/physics.h"
#include "../UI/ui.h"
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
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); 
    SetTargetFPS(60);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

    Camera3D camera = { 0 };
    camera.position = (Vector3){0.0f, 0.0f, 10.0f};
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    World world;

    auto brick = std::make_unique<Brick>(
    Vector3{0.0f, 0.0f, 0.0f}, // pos
    Vector3{2.0f, 1.0f, 4.0f}, // size
    Vector3{0.0f, 0.0f, 0.0f}, // velocity
    Vector3{0.0f, 0.0f, 0.0f}, // force
    5.0f, // mass
    RED);

    world.addBrick(std::move(brick));

    DisableCursor();
    initImGui();
    
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_FREE);

        float deltaTime = GetFrameTime();
        updatePhysics(deltaTime, world);

        BeginDrawing();

            ClearBackground(SKYBLUE);

            BeginMode3D(camera);

            world.drawWorld();

            EndMode3D();

            rlImGuiBegin();

            drawUi();

            rlImGuiEnd();

        EndDrawing();
    }
}

application::~application()
{
    CloseWindow();
    rlImGuiShutdown();
    printf("Closing Program...");
}