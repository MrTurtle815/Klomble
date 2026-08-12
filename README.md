# Klomble

<p align="center">
  <img src="https://github.com/MrTurtle815/Klomble/blob/main/images/Klomble.png" alt="Klomble Logo" width="700">
</p>

<p align="center">
  <a href="https://github.com/MrTurtle815/Klomble/blob/main/LICENSE"><img src="https://img.shields.io/badge/license-Zlib-blue.svg" alt="License"></a>
  <a href="https://klomble.com/"><img src="https://img.shields.io/badge/website-klomble.com%20-blue.svg" alt="Website"></a>
  <a href="https://discord.com/invite/MfTXZWHvjq"><img src="https://img.shields.io/badge/discord-klomble-blue?logo=discord" alt="Discord"></a>
</p>

**Klomble** is an open-source, single-header, multimedia library designed for simple graphics development without a steep learning curve!

---

## Features

* **Single-Header Simplicity:** Just drop `#define KLOMBLE_IMPLEMENTATION and #include "Klomble.h"` into your project and you're ready to code.
* **Modern OpenGL Pipeline:** Klomble uses modern OpenGL for maximum performance on both new and old hardware.
* **2D & 3D Rendering:** Draw Squares, triangles, cubes with just a single function!
* **Simple Input API:** User friendly keyboard input system!

---

## Simple Example

A simple example on how to get a moveable player in under 25 lines of code:

```cpp
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
```
It's that simple!

---

## Install & Setup

**1.** Download or copy the klomble.h file from this GitHub repo.

**2.** Place it in your C++ project

**3.** Include it using #define KLOMBLE_IMPLEMENTATION, then add #include <klomble.h>

**4.** Start coding!

---

## Links

**Website:** http://klomble.com/

**Discord:** https://discord.com/invite/MfTXZWHvjq

**Documentation:** http://klomble.com/documentation

---

**Copyright © 2026 @MrTurtle815**

Under [Zlib License](http://klomble.com/license)
