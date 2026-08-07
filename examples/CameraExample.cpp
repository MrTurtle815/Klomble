#include "../Klomble.h" // main klomble header file
#include <stdio.h>

int main() {
    KlombleWindow* window = klombleCreateWindow(800, 600, "Camera Example");

    Klomble::Vec3 cubePos(0.0f, 0.0f, 0.0f); // starting cube position
    Klomble::Vec3 cubeRot(0.0f, 0.0f, 0.0f); // starting cube rotation
    
    Klomble::Camera3D camera;
    klombleSetActiveCamera(&camera);

    float speed = 3.0f;

    while (klombleUpdate(window)) {
        klombleUpdateFreeCamera(window, camera, speed, 0.15f);
        klombleClearBackground(window, Klomble::Color(0, 0, 255)); // sets background colour
        klombleDrawCube(window, cubePos, 1.0f, cubeRot, Klomble::Color(0, 255, 0));
    }

    klombleCloseWindow(window); // closes window
    return 0;
}
