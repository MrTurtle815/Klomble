#define KLOMBLE_IMPLEMENTATION // define the implementation (REQUIRED)

#include "../klomble.h" // main klomble header file

int main() {
    Klomble::KlombleWindow* window = klombleCreateWindow(800, 600, "Moveable Player 2D");  // create window

    Klomble::Vec2 playerPos(0.0f, 0.0f); // set initial position for player
    float playerSpeed = 1.5f;

    while (klombleUpdate(window)) { 
        // game loop

        klombleClearBackground(window, Klomble::Color(225, 225, 225)); // sets background colour to gray

        float dt = klombleGetDeltaTime(); // gets delta time

        if (klombleIsKeyDown(Klomble::W)) playerPos.y += playerSpeed * dt; // moves player forward
        if (klombleIsKeyDown(Klomble::S)) playerPos.y -= playerSpeed * dt; // moves player backward
        if (klombleIsKeyDown(Klomble::A)) playerPos.x -= playerSpeed * dt; // moves player to the left
        if (klombleIsKeyDown(Klomble::D)) playerPos.x += playerSpeed * dt; // moves player to the right

        Klomble::Vec2 leftLegPos(playerPos.x - 0.06f, playerPos.y - 0.19f);
        Klomble::Vec2 rightLegPos(playerPos.x + 0.06f, playerPos.y - 0.19f);
        klombleDrawSquare(window, leftLegPos, 0.08f, 0.0f, Klomble::Color(50, 50, 50)); // draw left leg
        klombleDrawSquare(window, rightLegPos, 0.08f, 0.0f, Klomble::Color(50, 50, 50)); // draw right leg

        klombleDrawSquare(window, playerPos, 0.3f, 0.0f, Klomble::Color(0, 255, 100)); // draw torso

        Klomble::Vec2 headPos(playerPos.x, playerPos.y + 0.22f);
        klombleDrawCircle(window, headPos, 0.13f, Klomble::Color(255, 200, 150)); // draw head
    }

    klombleCloseWindow(window); // closes window
    return 0;
}