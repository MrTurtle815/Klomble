#include "../Klomble.h" // main klomble header file
#include <stdio.h>

int main() {
    KlombleWindow* window = klombleCreateWindow(800, 600, "Spinning cube");

    Klomble::Vec3 cubePos(0.0f, 0.0f, -4.0f); // starting cube position
    Klomble::Vec3 cubeRot(0.0f, 0.0f, 0.0f); // starting cube rotation
    
    float rotationSpeed = 90.0f; 

    while (klombleUpdate(window)) {
        klombleClearBackground(window, Klomble::Color(0, 0, 255)); // sets background colour
        float dt = klombleGetDeltaTime(); // gets delta time

        cubeRot.x += rotationSpeed * dt; // rotates on x axis
        cubeRot.y += rotationSpeed * 0.5f * dt; // rotates slower on y axis

        klombleDrawCube(window, cubePos, 1.0f, cubeRot, Klomble::Color(0, 255, 0)); // draws the cube!
    }

    klombleCloseWindow(window); // closes window
    return 0;
}