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

* **Single-Header Simplicity:** Just drop `#include "Klomble.h"` into your project and you're ready to code.
* **Modern OpenGL Pipeline:** Klomble uses modern OpenGL for maximum performance on both new and old hardware.
* **2D & 3D Rendering:** Draw Squares, triangles, cubes with just a single function!
* **Simple Input API:** User friendly keyboard input system!

---

## Simple Example

A simple example on how to get a moveable player in under 20 lines of code:

```cpp
#include "Klomble.h" // main klomble header file
#include <stdio.h>

int main() {
    KlombleWindow* mainWindow = klombleCreateWindow(800, 600, "Klomble Game");  // create window

    Klomble::Vec2 playerPos(0.0f, 0.0f); // set initial position for player
    float playerSpeed = 1.0f;

    while (klombleUpdate(mainWindow)) { // game loop
        klombleClearBackground(mainWindow, Klomble::Color(30, 30, 30)); // sets background colour

        float dt = klombleGetDeltaTime(); // gets delta time

        if (klombleIsKeyDown(Klomble::Key::W)) playerPos.y += playerSpeed * dt; // moves player forward
        if (klombleIsKeyDown(Klomble::Key::S)) playerPos.y -= playerSpeed * dt; // moves player backward
        if (klombleIsKeyDown(Klomble::Key::A)) playerPos.x -= playerSpeed * dt; // moves player to the left
        if (klombleIsKeyDown(Klomble::Key::D)) playerPos.x += playerSpeed * dt; // moves player to the right

        klombleDrawSquare(mainWindow, playerPos, 0.3f, 0.0f, Klomble::Color(0, 255, 100)); // draws player with position
    }

    klombleCloseWindow(mainWindow); // closes window
    return 0;
}
```
It's that simple!

---

## Install & Setup

**1.** Download or copy the klomble.h file from this GitHub repo.

**2.** Place it in your C++ project

**3.** Include it using #include <klomble.h>

**4.** Start coding!

---

## Links

**Website:** http://klomble.com/

**Discord:** https://discord.com/invite/MfTXZWHvjq

**Documentation:** http://klomble.com/documentation

---

**Copyright © 2026 @MrTurtle815**

Under [Zlib License](http://klomble.com/license)