// headers

#include "physics.h"
#include "../Scene/scene.h"
#include "../values.h"

void updateGravity(Brick& brick, float deltaTime)
{
    brick.velocity.y += -gravity * deltaTime;
    brick.position.y += brick.velocity.y * deltaTime;
}

void checkCollisions()
{

}

void updatePhysics(float deltaTime, World& mainWorld)
{
    const auto& bricks = mainWorld.getBricks();
    
    for (const auto& brickPtr : bricks) {
        updateGravity(*brickPtr, deltaTime);
    }
}