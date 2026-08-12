#define KLOMBLE_IMPLEMENTATION // define the implementation (REQUIRED)

#include "../klomble.h" // main klomble header file

int main()
{
    Klomble::KlombleWindow* window = klombleCreateWindow(800, 600, "Spinning Shapes 2D"); // window creation

    float rotationSpeed = 90.0f; // degrees per second
    float rotation = 0.0f;

    while (klombleUpdate(window))
    {
        // loop

        float deltaTime = klombleGetDeltaTime(); // gets delta time
        rotation += rotationSpeed * deltaTime;

        klombleClearBackground(window, Klomble::Color(225, 225, 225)); // sets background to gray

        klombleDrawSquare(window, Klomble::Vec2(-0.5f, 0.3f), 0.3f, rotation, Klomble::Color(255, 0, 0)); // draws red spinning square
        klombleDrawTriangle(window, Klomble::Vec2(0.5f, 0.2f), 0.5f, rotation, Klomble::Color(0, 255, 0)); // draws green spinning triangle
        klombleDrawCircle(window, Klomble::Vec2(0.0f, -0.3f), 0.7f, Klomble::Color(0, 0, 255)); // draws blue circle (circles cant rotate)
    }

    klombleCloseWindow(window); // closes window
    return 0;
}