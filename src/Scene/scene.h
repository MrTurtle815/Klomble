// libraries

#include <raylib/raylib.h>

// utils

#include <vector>
#include <memory>

struct Instance
{
    Vector3 position;
    Vector3 size;
    Color color; 

    Instance(Vector3 pos, Vector3 sz, Color col) : position(pos), size(sz), color(col) {} 
};

class Brick : public Instance
{
public: 
    Brick(Vector3 pos, Vector3 sz, Color col) : Instance(pos, sz, col) {}

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
};