#pragma once

// libraries

#include <raylib/raylib.h>

// utils

#include <vector>
#include <memory>

struct Instance
{
    // physics

    Vector3 position;
    Vector3 size;
    Vector3 velocity;
    Vector3 force;
    float mass;

    // looks

    Color color; 

    int identification;

    Instance(Vector3 pos, Vector3 sz, Vector3 vel, Vector3 frce, float mas, Color col, int id) : position(pos), size(sz), velocity(vel), force(frce), mass(mas), color(col), identification(id) {} 
};

class Brick : public Instance
{
public: 
    Brick(Vector3 pos, Vector3 sz, Vector3 vel, Vector3 frce, float mas, Color col, int id) : Instance(pos, sz, vel, frce, mas, col, id) {} 

    void draw()
    {
        DrawCube(position, size.x, size.y, size.z, color);
    }
};

class World 
{
private:
    std::vector<std::unique_ptr<Brick>> instanceList;

public:
    void addBrick(std::unique_ptr<Brick> newBrick)
    {
        instanceList.push_back(std::move(newBrick));
    }

    void drawWorld()
    {
        for (const auto& brick : instanceList) {
            brick->draw(); 
        }
    }

    const std::vector<std::unique_ptr<Brick>>& getBricks() const
    {
        return instanceList;
    }
};