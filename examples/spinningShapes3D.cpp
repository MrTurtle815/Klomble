#define KLOMBLE_IMPLEMENTATION // define the implementation (REQUIRED)

#include "../klomble.h" // main klomble header file

int main()
{
    Klomble::KlombleWindow* window = klombleCreateWindow(800, 600, "Spinning Shapes 3D"); // window creation

    Klomble::Camera3D camera; // init camera
    camera.position = Klomble::Vec3(0.0f, 0.0f, 4.0f); // set inital position
    klombleSetActiveCamera(&camera); // set active camera

    float rotationSpeed = 90.0f; // degrees per second
    float rotation = 0.0f;

    while (klombleUpdate(window))
    {
        // loop

        float deltaTime = klombleGetDeltaTime(); // gets delta time
        rotation += rotationSpeed * deltaTime;
        
        klombleClearBackground(window, Klomble::Color(225, 225, 225)); // sets background to gray

        klombleUpdateFreeCamera(window, camera, 3.0f, 0.15f); // update free camera

        klombleDrawCube(window, Klomble::Vec3(-1.0f, 0.2f, 0.0f), 0.8f, Klomble::Vec3(rotation, rotation * 0.5f, 0.0f), Klomble::Color(255, 0, 0)); // draw red spinning cube

        klombleDrawSphere(window, Klomble::Vec3(1.0f, -0.2f, 0.0f), 0.6f, Klomble::Vec3(0.0f, rotation, 0.0f), Klomble::Color(0, 0, 255)); // draws blue spinning sphere
    }

    klombleCloseWindow(window); // closes window
    return 0;
}
