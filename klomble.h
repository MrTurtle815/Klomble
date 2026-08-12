/*
Klomble

Klomble is a open-source, single-header, multimedia library designed
to let you easily build video games without a steep learning curve!

------------------------------

Klomble is under the Zlib license:

Copyright (c) 2026 @MrTurtle815 on Github
This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

------------------------------

Klomble Requirements:

# Windows - Unfortunately Klomble only supports windows for the time
being, though with the goal of adding Linux and Mac compatibility

# C++ 11 and up - I managed to get it to compile wiht C++ 11 though not
with C++ 03, but I would suggest using a more modern version of C++ like
C++ 14/17/20/23

# OpenGL 3.3 and up - Ensure that you have a GPU or integrated graphics
with OpenGL 3.3 and up

------------------------------

Klomble Links:

GitHub Repository: https://github.com/MrTurtle815/Klomble
Website: klomble.com

------------------------------

IMPORTANT FOR PROGRAMMERS. PLEASE READ:

As klomble dosent use any external libraries such as GLAD to access OpenGL
functions, it uses Windows GL/GL.h which requires several linkers in the compiler!

For MSVC users this is automatically done although for GCC (G++) users you will need
to link these in your compiler:

# opengl32.lib
# gdi32.lib
# user32.lib

Please ensure that you do this or else your program may not run! Klomble is currently working
on a solution to this!

------------------------------

Made by MrTurtle815
*/

#pragma once

#ifndef KLOMBLE_H
#define KLOMBLE_H

// namespace

namespace Klomble {
    struct Vec2 {
        float x, y;
        Vec2(float _x = 0.0f, float _y = 0.0f) : x(_x), y(_y) {}
    };

    struct Vec3 {
        float x, y, z;
        Vec3(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) : x(_x), y(_y), z(_z) {}
    };

    struct Color {
        float r, g, b;
        Color(int red, int green, int blue) {
            r = (float)red / 255.0f;
            g = (float)green / 255.0f;
            b = (float)blue / 255.0f;
        }
    };

    enum Key {
        A = 'A', B = 'B', C = 'C', D = 'D', E = 'E', F = 'F', G = 'G',
        H = 'H', I = 'I', J = 'J', K = 'K', L = 'L', M = 'M', N = 'N',
        O = 'O', P = 'P', Q = 'Q', R = 'R', S = 'S', T = 'T', U = 'U',
        V = 'V', W = 'W', X = 'X', Y = 'Y', Z = 'Z',
        Num0 = '0', Num1 = '1', Num2 = '2', Num3 = '3', Num4 = '4',
        Num5 = '5', Num6 = '6', Num7 = '7', Num8 = '8', Num9 = '9',
        Space = 0x20, Enter = 0x0D, Escape = 0x1B,
        Left = 0x25, Up = 0x26, Right = 0x27, Down = 0x28
    };

    struct Camera3D {
        Vec3 position;
        Vec3 rotation;
        Vec2 mousePos;
        Vec2 lastMousePos;
        float fov;

        Camera3D(
            Vec3 pos = Vec3(0,0,0),
            Vec3 rot = Vec3(0,0,0),
            Vec2 mosPos = Vec2(0,0),
            Vec2 lastMosPos = Vec2(0,0),
            float _fov = 60.0f)
            : position(pos), rotation(rot), mousePos(mosPos),
              lastMousePos(lastMosPos), fov(_fov)
        {}
    };

    struct KlombleWindow {
        void* handle;
        void* deviceContext;
        void* renderingContext;
        int width;
        int height;
    };
}

#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_INFO_LOG_LENGTH 0x8B84

// klomble functions

Klomble::KlombleWindow* klombleCreateWindow(int width, int height, const char* title);
void klombleClearBackground(Klomble::KlombleWindow* window, Klomble::Color color);

// shapes

void klombleDrawCube(Klomble::KlombleWindow* window, Klomble::Vec3 position, float size, Klomble::Vec3 rotation, Klomble::Color color);
void klombleDrawSquare(Klomble::KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color);
void klombleDrawTriangle(Klomble::KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color);
void klombleDrawCircle(Klomble::KlombleWindow* window, Klomble::Vec2 position, float size, Klomble::Color color);
void klombleDrawSphere(Klomble::KlombleWindow* window, Klomble::Vec3 position, float size, Klomble::Vec3 rotation, Klomble::Color color);

void klombleCloseWindow(Klomble::KlombleWindow* window);
void klombleSetWindowTitle(Klomble::KlombleWindow* window, const char* title);
int klombleUpdate(Klomble::KlombleWindow* window);
float klombleGetDeltaTime();
float klombleGetFPS();

bool klombleIsKeyDown(int key);
void* klombleLoadGLFunction(const char* name);
void klombleLogError(const char* message);

// camera

void klombleSetActiveCamera(Klomble::Camera3D* cam);
void klombleUpdateFreeCamera(Klomble::KlombleWindow* window, Klomble::Camera3D& cam, float speed = 3.0f, float sensitivity = 0.15f);

#ifdef _WIN32
    #include <windows.h>
    #include <windowsx.h>
    #include <stdio.h>
    #include <vector>
    #include <stdlib.h>
    #include <cmath>
    #include <algorithm>
    #include <GL/gl.h>

    #ifdef _MSC_VER
        #pragma comment(lib, "opengl32.lib")
    #endif
#endif

// opengl

#ifdef _WIN32

#ifndef GL_ARRAY_BUFFER
    typedef ptrdiff_t GLsizeiptr;
    typedef char GLchar;
    #define GL_ARRAY_BUFFER 0x8892
    #define GL_STATIC_DRAW 0x88E4
    #define GL_FRAGMENT_SHADER 0x8B30
    #define GL_VERTEX_SHADER 0x8B31
#endif

#ifndef GL_MAJOR_VERSION
    #define GL_MAJOR_VERSION 0x821B
#endif

#ifndef GL_MINOR_VERSION
    #define GL_MINOR_VERSION 0x822C
#endif

typedef void (APIENTRY* GenVertexArraysProc)(GLsizei, GLuint*);
typedef void (APIENTRY* BindVertexArrayProc)(GLuint);

typedef void (APIENTRY* GenBuffersProc)(GLsizei, GLuint*);
typedef void (APIENTRY* BindBufferProc)(GLenum, GLuint);

typedef void (APIENTRY* BufferDataProc)(
    GLenum,
    GLsizeiptr,
    const void*,
    GLenum
);

typedef void (APIENTRY* VertexAttribPointerProc)(
    GLuint,
    GLint,
    GLenum,
    GLboolean,
    GLsizei,
    const void*
);

typedef void (APIENTRY* EnableVertexAttribArrayProc)(GLuint);

typedef GLuint (APIENTRY* CreateShaderProc)(GLenum);
typedef void (APIENTRY* ShaderSourceProc)(
    GLuint,
    GLsizei,
    const GLchar* const*,
    const GLint*
);

typedef void (APIENTRY* CompileShaderProc)(GLuint);

typedef GLuint (APIENTRY* CreateProgramProc)(void);
typedef void (APIENTRY* AttachShaderProc)(GLuint, GLuint);
typedef void (APIENTRY* LinkProgramProc)(GLuint);
typedef void (APIENTRY* UseProgramProc)(GLuint);

typedef GLint (APIENTRY* GetUniformLocationProc)(
    GLuint,
    const GLchar*
);

typedef void (APIENTRY* Uniform1fProc)(GLint, GLfloat);
typedef void (APIENTRY* Uniform2fProc)(GLint, GLfloat, GLfloat);
typedef void (APIENTRY* Uniform3fProc)(GLint, GLfloat, GLfloat, GLfloat);

typedef void (APIENTRY* GetShaderivProc)(
    GLuint,
    GLenum,
    GLint*
);

typedef void (APIENTRY* GetShaderInfoLogProc)(
    GLuint,
    GLsizei,
    GLsizei*,
    GLchar*
);

typedef void (APIENTRY* GetProgramivProc)(
    GLuint,
    GLenum,
    GLint*
);

typedef void (APIENTRY* GetProgramInfoLogProc)(
    GLuint,
    GLsizei,
    GLsizei*,
    GLchar*
);

typedef void (APIENTRY* DeleteShaderProc)(GLuint);

typedef void (APIENTRY* EnableProc)(GLenum);
typedef void (APIENTRY* ClearColorProc)(GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY* ClearProc)(GLbitfield);
typedef void (APIENTRY* DrawArraysProc)(GLenum, GLint, GLsizei);
typedef void (APIENTRY* GetIntegervProc)(GLenum, GLint*);

#ifdef KLOMBLE_IMPLEMENTATION

    namespace Klomble {
        namespace detail {
            namespace {

                // loaded GL entry points

                struct GLFunctions {
                    GenVertexArraysProc genVertexArrays;
                    BindVertexArrayProc bindVertexArray;

                    GenBuffersProc genBuffers;
                    BindBufferProc bindBuffer;
                    BufferDataProc bufferData;

                    VertexAttribPointerProc vertexAttribPointer;
                    EnableVertexAttribArrayProc enableVertexAttribArray;

                    CreateShaderProc createShader;
                    ShaderSourceProc shaderSource;
                    CompileShaderProc compileShader;

                    CreateProgramProc createProgram;
                    AttachShaderProc attachShader;
                    LinkProgramProc linkProgram;
                    UseProgramProc useProgram;

                    GetUniformLocationProc getUniformLocation;

                    Uniform1fProc uniform1f;
                    Uniform2fProc uniform2f;
                    Uniform3fProc uniform3f;

                    GetShaderivProc getShaderiv;
                    GetShaderInfoLogProc getShaderInfoLog;

                    GetProgramivProc getProgramiv;
                    GetProgramInfoLogProc getProgramInfoLog;

                    DeleteShaderProc deleteShader;

                    EnableProc enable;
                    ClearColorProc clearColor;
                    ClearProc clear;
                    DrawArraysProc drawArrays;
                    GetIntegervProc getIntegerv;
                } gl;

                struct Renderer2D {
                    GLuint program;
                    GLuint vao, vbo;
                    GLint  uOffset, uScale, uColor, uRotation;
                    GLint  uAspect;
                    
                    GLint circleOffset;
                    GLint circleCount;
                } renderer2D;

                struct Renderer3D {
                    GLuint program;
                    GLuint cubeVAO, cubeVBO;
                    GLint  uOffset, uScale, uRotation, uColor, uAspect;
                    GLint  uCamPos, uCamRot;
                    
                    GLint sphereOffset;
                    GLint sphereCount;
                } renderer3D;

                Camera3D* activeCamera = nullptr;
                bool glReady = false;

                HGLRC currentRC = nullptr;
                HDC currentDC = nullptr;

                LARGE_INTEGER timeFrequency;
                LARGE_INTEGER timeLast;
                float deltaTime = 0.0f;
                bool keys[256] = { false };
            }

            inline void MakeCurrent(HDC dc, HGLRC rc) {
                if (currentRC != rc || currentDC != dc) {
                    wglMakeCurrent(dc, rc);
                    currentRC = rc;
                    currentDC = dc;
                }
            }
            inline void InitGL()
            {
                if (glReady) return;

                gl.genVertexArrays = (GenVertexArraysProc)klombleLoadGLFunction("glGenVertexArrays");
                gl.bindVertexArray = (BindVertexArrayProc)klombleLoadGLFunction("glBindVertexArray");
                gl.genBuffers = (GenBuffersProc)klombleLoadGLFunction("glGenBuffers");
                gl.bindBuffer = (BindBufferProc)klombleLoadGLFunction("glBindBuffer");
                gl.bufferData = (BufferDataProc)klombleLoadGLFunction("glBufferData");
                gl.vertexAttribPointer = (VertexAttribPointerProc)klombleLoadGLFunction("glVertexAttribPointer");
                gl.enableVertexAttribArray = (EnableVertexAttribArrayProc)klombleLoadGLFunction("glEnableVertexAttribArray");
                gl.createShader = (CreateShaderProc)klombleLoadGLFunction("glCreateShader");
                gl.shaderSource = (ShaderSourceProc)klombleLoadGLFunction("glShaderSource");
                gl.compileShader = (CompileShaderProc)klombleLoadGLFunction("glCompileShader");
                gl.createProgram = (CreateProgramProc)klombleLoadGLFunction("glCreateProgram");
                gl.attachShader = (AttachShaderProc)klombleLoadGLFunction("glAttachShader");
                gl.linkProgram = (LinkProgramProc)klombleLoadGLFunction("glLinkProgram");
                gl.useProgram = (UseProgramProc)klombleLoadGLFunction("glUseProgram");
                gl.getUniformLocation = (GetUniformLocationProc)klombleLoadGLFunction("glGetUniformLocation");
                gl.uniform2f = (Uniform2fProc)klombleLoadGLFunction("glUniform2f");
                gl.uniform3f = (Uniform3fProc)klombleLoadGLFunction("glUniform3f");
                gl.uniform1f = (Uniform1fProc)klombleLoadGLFunction("glUniform1f");
                gl.getShaderiv = (GetShaderivProc)klombleLoadGLFunction("glGetShaderiv");
                gl.getShaderInfoLog = (GetShaderInfoLogProc)klombleLoadGLFunction("glGetShaderInfoLog");
                gl.getProgramiv = (GetProgramivProc)klombleLoadGLFunction("glGetProgramiv");
                gl.getProgramInfoLog = (GetProgramInfoLogProc)klombleLoadGLFunction("glGetProgramInfoLog");
                gl.deleteShader = (DeleteShaderProc)klombleLoadGLFunction("glDeleteShader");
                gl.enable = (EnableProc)klombleLoadGLFunction("glEnable");
                gl.clearColor = (ClearColorProc)klombleLoadGLFunction("glClearColor");
                gl.clear = (ClearProc)klombleLoadGLFunction("glClear");
                gl.drawArrays = (DrawArraysProc)klombleLoadGLFunction("glDrawArrays");
                gl.getIntegerv = (GetIntegervProc)klombleLoadGLFunction("glGetIntegerv");

                GLint majorVersion = 0;
                GLint minorVersion = 0;
                gl.getIntegerv(GL_MAJOR_VERSION, &majorVersion);
                gl.getIntegerv(GL_MINOR_VERSION, &minorVersion);
                if (majorVersion < 3 || (majorVersion == 3 && minorVersion < 3)) {
                    klombleLogError("Klomble Error: Klomble requires OpenGL 3.3 or higher");
                    return;
                }

                const char* vertexShader3DSource = R"(#version 330
                layout(location=0) in vec3 aPos;

                uniform vec3 uOffset;
                uniform vec3 uRotation;
                uniform float uScale;
                uniform float uAspect;
                uniform vec3 uCamPos;
                uniform vec3 uCamRot;

                void main() {
                    vec3 pos = aPos * uScale;

                    vec3 r = radians(uRotation);
                    vec3 c = cos(r);
                    vec3 s = sin(r);

                    float y1 = pos.y * c.x - pos.z * s.x;
                    float z1 = pos.y * s.x + pos.z * c.x;
                    pos.y = y1; pos.z = z1;

                    float x2 = pos.x * c.y + pos.z * s.y;
                    float z2 = -pos.x * s.y + pos.z * c.y;
                    pos.x = x2; pos.z = z2;

                    float x3 = pos.x * c.z - pos.y * s.z;
                    float y3 = pos.x * s.z + pos.y * c.z;
                    pos.x = x3; pos.y = y3;

                    pos += uOffset;

                    // camera
                    pos -= uCamPos;

                    vec3 cameraRotationRadians = radians(-uCamRot);
                    vec3 cameraCos = cos(cameraRotationRadians);
                    vec3 cameraSin = sin(cameraRotationRadians);

                    // yaw
                    float rotatedX = pos.x * cameraCos.y + pos.z * cameraSin.y;
                    float rotatedZ2 = -pos.x * cameraSin.y + pos.z * cameraCos.y;
                    pos.x = rotatedX;
                    pos.z = rotatedZ2;

                    // pitch
                    float rotatedY = pos.y * cameraCos.x - pos.z * cameraSin.x;
                    float rotatedZ = pos.y * cameraSin.x + pos.z * cameraCos.x;
                    pos.y = rotatedY;
                    pos.z = rotatedZ;

                    float zNear = 0.1;
                    float zFar = 100.0;

                    gl_Position = vec4(
                        pos.x / uAspect,
                        pos.y,
                        (pos.z * (zFar + zNear) + (2.0 * zFar * zNear)) / (zNear - zFar),
                        -pos.z
                    );
                }
                )";

                const char* vertexShaderSource = R"(#version 330
                    layout(location=0) in vec2 aPos;
                    uniform vec2 uOffset;
                    uniform float uScale;
                    uniform float uRotation;
                    uniform float uAspect;
                    void main(){
                        float rad = radians(uRotation);
                        float c = cos(rad);
                        float s = sin(rad);
                        mat2 rot = mat2(c, s, -s, c);

                        vec2 finalPos = rot * (aPos * uScale) + uOffset;
                        finalPos.x /= uAspect;
                        gl_Position = vec4(finalPos, 0.0, 1.0);
                    }
                )";

                const char* fragmentShaderSource = R"(#version 330
                    out vec4 FragColor;
                    uniform vec3 uColor;
                    void main(){
                        FragColor = vec4(uColor, 1.0);
                    }
                )";

                gl.enable(GL_DEPTH_TEST);

                GLuint vertexShader = gl.createShader(GL_VERTEX_SHADER);
                gl.shaderSource(vertexShader, 1, &vertexShaderSource, NULL);
                gl.compileShader(vertexShader);

                GLint success;
                gl.getShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
                if (!success) {
                    char log[1024];
                    gl.getShaderInfoLog(vertexShader, sizeof(log), nullptr, log);
                    printf("Klomble Error: Vertex shader compilation failed:\n%s\n", log);
                }

                GLuint fragmentShader = gl.createShader(GL_FRAGMENT_SHADER);
                gl.shaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
                gl.compileShader(fragmentShader);
                gl.getShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
                if (!success) {
                    char log[1024];
                    gl.getShaderInfoLog(fragmentShader, sizeof(log), nullptr, log);
                    printf("Klomble Error: Fragment shader compilation failed:\n%s\n", log);
                }

                renderer2D.program = gl.createProgram();
                gl.attachShader(renderer2D.program, vertexShader);
                gl.attachShader(renderer2D.program, fragmentShader);
                gl.linkProgram(renderer2D.program);

                GLint linkSuccess;
                gl.getProgramiv(renderer2D.program, GL_LINK_STATUS, &linkSuccess);
                if (!linkSuccess) {
                    char log[1024];
                    gl.getProgramInfoLog(renderer2D.program, sizeof(log), nullptr, log);
                    printf("Klomble: 2D program link failed:\n%s\n", log);
                }

                renderer2D.uOffset   = gl.getUniformLocation(renderer2D.program, "uOffset");
                renderer2D.uScale    = gl.getUniformLocation(renderer2D.program, "uScale");
                renderer2D.uRotation = gl.getUniformLocation(renderer2D.program, "uRotation");
                renderer2D.uColor    = gl.getUniformLocation(renderer2D.program, "uColor");
                renderer2D.uAspect   = gl.getUniformLocation(renderer2D.program, "uAspect");

                std::vector<float> shapes2D;

                float square[] = { -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f };
                shapes2D.insert(shapes2D.end(), square, square + 8);

                float triangle[] = { 0.0f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f };
                shapes2D.insert(shapes2D.end(), triangle, triangle + 6);

                renderer2D.circleOffset = shapes2D.size() / 2;
                int circleSegments = 36; 
                shapes2D.push_back(0.0f); 
                shapes2D.push_back(0.0f);
                for (int i = 0; i <= circleSegments; i++) {
                    float angle = i * 3.14159265f * 2.0f / circleSegments;
                    shapes2D.push_back(cos(angle) * 0.5f);
                    shapes2D.push_back(sin(angle) * 0.5f);
                }
                renderer2D.circleCount = circleSegments + 2;

                gl.genVertexArrays(1, &renderer2D.vao);
                gl.bindVertexArray(renderer2D.vao);
                gl.genBuffers(1, &renderer2D.vbo);
                gl.bindBuffer(GL_ARRAY_BUFFER, renderer2D.vbo);
                gl.bufferData(GL_ARRAY_BUFFER, shapes2D.size() * sizeof(float), shapes2D.data(), GL_STATIC_DRAW);
                gl.vertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
                gl.enableVertexAttribArray(0);

                GLuint vs3D = gl.createShader(GL_VERTEX_SHADER);
                gl.shaderSource(vs3D, 1, &vertexShader3DSource, NULL);
                gl.compileShader(vs3D);

                renderer3D.program = gl.createProgram();
                gl.attachShader(renderer3D.program, vs3D);
                gl.attachShader(renderer3D.program, fragmentShader);
                gl.linkProgram(renderer3D.program);

                renderer3D.uOffset = gl.getUniformLocation(renderer3D.program, "uOffset");
                renderer3D.uScale = gl.getUniformLocation(renderer3D.program, "uScale");
                renderer3D.uRotation = gl.getUniformLocation(renderer3D.program, "uRotation");
                renderer3D.uColor = gl.getUniformLocation(renderer3D.program, "uColor");
                renderer3D.uAspect = gl.getUniformLocation(renderer3D.program, "uAspect");
                renderer3D.uCamPos = gl.getUniformLocation(renderer3D.program, "uCamPos");
                renderer3D.uCamRot = gl.getUniformLocation(renderer3D.program, "uCamRot");

                // cube vertices
                float cubeVertices[] = {
                    -0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f, 0.5f,-0.5f,  0.5f, 0.5f,-0.5f, -0.5f, 0.5f,-0.5f, -0.5f,-0.5f,-0.5f,
                    -0.5f,-0.5f, 0.5f,  0.5f,-0.5f, 0.5f,  0.5f, 0.5f, 0.5f,  0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f,-0.5f, 0.5f,
                    -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,-0.5f, -0.5f,-0.5f,-0.5f, -0.5f,-0.5f,-0.5f, -0.5f,-0.5f, 0.5f, -0.5f, 0.5f, 0.5f,
                    0.5f, 0.5f, 0.5f,  0.5f, 0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f, 0.5f,  0.5f, 0.5f, 0.5f,
                    -0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f, 0.5f,  0.5f,-0.5f, 0.5f, -0.5f,-0.5f, 0.5f, -0.5f,-0.5f,-0.5f,
                    -0.5f, 0.5f,-0.5f,  0.5f, 0.5f,-0.5f,  0.5f, 0.5f, 0.5f,  0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,-0.5f
                };

                std::vector<float> shapes3D;
                shapes3D.insert(shapes3D.end(), cubeVertices, cubeVertices + 108);

                renderer3D.sphereOffset = shapes3D.size() / 3;
                int stacks = 16, sectors = 16;
                float radius = 0.5f;

                for (int i = 0; i < stacks; ++i) {
                    float lat0 = 3.14159f * (-0.5f + (float)(i) / stacks);
                    float z0 = radius * sin(lat0);
                    float zr0 = radius * cos(lat0);

                    float lat1 = 3.14159f * (-0.5f + (float)(i + 1) / stacks);
                    float z1 = radius * sin(lat1);
                    float zr1 = radius * cos(lat1);

                    for (int j = 0; j < sectors; ++j) {
                        float lng0 = 2 * 3.14159f * (float)(j) / sectors;
                        float x0 = cos(lng0);
                        float y0 = sin(lng0);

                        float lng1 = 2 * 3.14159f * (float)(j + 1) / sectors;
                        float x1 = cos(lng1);
                        float y1 = sin(lng1);

                        shapes3D.insert(shapes3D.end(), { x0 * zr0, y0 * zr0, z0,  x1 * zr0, y1 * zr0, z0,  x0 * zr1, y0 * zr1, z1 });
                        shapes3D.insert(shapes3D.end(), { x1 * zr0, y1 * zr0, z0,  x1 * zr1, y1 * zr1, z1,  x0 * zr1, y0 * zr1, z1 });
                    }
                }
                renderer3D.sphereCount = (shapes3D.size() / 3) - renderer3D.sphereOffset;

                gl.genVertexArrays(1, &renderer3D.cubeVAO);
                gl.genBuffers(1, &renderer3D.cubeVBO);
                gl.bindVertexArray(renderer3D.cubeVAO);
                gl.bindBuffer(GL_ARRAY_BUFFER, renderer3D.cubeVBO);
                gl.bufferData(GL_ARRAY_BUFFER, shapes3D.size() * sizeof(float), shapes3D.data(), GL_STATIC_DRAW);
                gl.vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
                gl.enableVertexAttribArray(0);

                glReady = true;
            }
        }
    }

    // klomble window

    #ifdef _WIN32
        static LRESULT CALLBACK KlombleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
        {
            using namespace Klomble::detail;
            switch (uMsg) {
                // keyboard input

                case WM_KEYDOWN:
                    if (wParam >= 0 && wParam < 256) keys[wParam] = true;
                    return 0;

                case WM_KEYUP:
                    if (wParam >= 0 && wParam < 256) keys[wParam] = false;
                    return 0;

                case WM_PAINT:
                    ValidateRect(hwnd, NULL);
                    return 0;

                case WM_DESTROY:
                case WM_CLOSE:
                    PostQuitMessage(0);
                    return 0;
            }
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    #endif

    void klombleClearBackground(Klomble::KlombleWindow* window, Klomble::Color color)
    {
        if (!window) return;

        #ifdef _WIN32
            using namespace Klomble::detail;
            MakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);
            gl.clearColor(color.r, color.g, color.b, 1.0f);
            gl.clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        #endif
    }

    // shapes

    void klombleDrawCube(Klomble::KlombleWindow* window, Klomble::Vec3 position, float size, Klomble::Vec3 rotation, Klomble::Color color)
    {
        if (!window) return;

        #ifdef _WIN32
            using namespace Klomble::detail;
            MakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

            // recompute aspect every draw call in case the window got resized

            RECT rect;
            GetClientRect((HWND)window->handle, &rect);
            float aspect = (float)(rect.right - rect.left) / (float)(rect.bottom - rect.top);

            gl.useProgram(renderer3D.program);

            if (activeCamera) {
                gl.uniform3f(renderer3D.uCamPos, activeCamera->position.x, activeCamera->position.y, activeCamera->position.z);
                gl.uniform3f(renderer3D.uCamRot, activeCamera->rotation.x, activeCamera->rotation.y, activeCamera->rotation.z);
            } else {
                gl.uniform3f(renderer3D.uCamPos, 0, 0, 0);
                gl.uniform3f(renderer3D.uCamRot, 0, 0, 0);
            }

            gl.uniform3f(renderer3D.uOffset, position.x, position.y, position.z);
            gl.uniform3f(renderer3D.uRotation, rotation.x, rotation.y, rotation.z);
            gl.uniform1f(renderer3D.uScale, size);
            gl.uniform1f(renderer3D.uAspect, aspect);
            gl.uniform3f(renderer3D.uColor, color.r, color.g, color.b);

            gl.bindVertexArray(renderer3D.cubeVAO);
            gl.drawArrays(GL_TRIANGLES, 0, 36);
        #endif
    }

    void klombleDrawTriangle(Klomble::KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color)
    {
        if (!window) return;

        #ifdef _WIN32
            using namespace Klomble::detail;
            MakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

            gl.useProgram(renderer2D.program);

            gl.uniform2f(renderer2D.uOffset, position.x, position.y);
            gl.uniform1f(renderer2D.uScale, size);
            gl.uniform1f(renderer2D.uRotation, rotation);
            gl.uniform3f(renderer2D.uColor, color.r, color.g, color.b);

            gl.bindVertexArray(renderer2D.vao);

            // start at vertex 4 and draw 3 vertices

            gl.drawArrays(GL_TRIANGLES, 4, 3);
        #endif
    }

    Klomble::KlombleWindow* klombleCreateWindow(int width, int height, const char* title)
    {
        Klomble::KlombleWindow* window = (Klomble::KlombleWindow*)malloc(sizeof(Klomble::KlombleWindow));
        window->width = width;
        window->height = height;

        #ifdef _WIN32
            using namespace Klomble::detail;

            // register the window class

            HINSTANCE hInstance = GetModuleHandle(NULL);
            const char* className = "KlombleWindowClass";
        
            static bool classRegistered = false;
            if (!classRegistered) {
                WNDCLASS wc = {0};
                wc.lpfnWndProc = KlombleWindowProc;
                wc.hInstance = hInstance;
                wc.lpszClassName = className;
                wc.style = CS_OWNDC;

                RegisterClass(&wc);
                classRegistered = true;
            }

            HWND hwnd = CreateWindowEx(
                0,
                className,
                title,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                CW_USEDEFAULT, CW_USEDEFAULT,
                width, height,
                NULL,
                NULL,
                hInstance,
                NULL
            );

            HDC hdc = GetDC(hwnd);

            // get 32 bit RGBA double buffered depth capable pixel format

            PIXELFORMATDESCRIPTOR pfd = {0};
            pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
            pfd.nVersion = 1;
            pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
            pfd.iPixelType = PFD_TYPE_RGBA;
            pfd.cColorBits = 32;
            pfd.cDepthBits = 24;
            pfd.cStencilBits = 8;
            pfd.iLayerType = PFD_MAIN_PLANE;

            int format = ChoosePixelFormat(hdc, &pfd);
            SetPixelFormat(hdc, format, &pfd);

            HGLRC hglrc = wglCreateContext(hdc);
            wglMakeCurrent(hdc, hglrc);

            window->handle = (void*)hwnd;
            window->deviceContext = (void*)hdc;
            window->renderingContext = (void*)hglrc;

            InitGL();

            QueryPerformanceFrequency(&timeFrequency);
            QueryPerformanceCounter(&timeLast);
        #endif

        return window;
    }

    void klombleDrawSquare(Klomble::KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color)
    {
        if (!window) return;

        #ifdef _WIN32
            using namespace Klomble::detail;
            MakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

            gl.useProgram(renderer2D.program);

            gl.uniform2f(renderer2D.uOffset, position.x, position.y);
            gl.uniform1f(renderer2D.uScale, size);
            gl.uniform1f(renderer2D.uRotation, rotation);
            gl.uniform3f(renderer2D.uColor, color.r, color.g, color.b);

            gl.bindVertexArray(renderer2D.vao);

            gl.drawArrays(GL_TRIANGLE_FAN, 0, 4);
        #endif
    }

    void klombleDrawCircle(Klomble::KlombleWindow* window, Klomble::Vec2 position, float size, Klomble::Color color)
    {
        if (!window) return;

        #ifdef _WIN32
            using namespace Klomble::detail;
            MakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

            RECT rect;
            GetClientRect((HWND)window->handle, &rect);
            float aspect = (float)(rect.right - rect.left) / (float)(rect.bottom - rect.top);

            gl.useProgram(renderer2D.program);
            gl.uniform2f(renderer2D.uOffset, position.x, position.y);
            gl.uniform1f(renderer2D.uScale, size);
            gl.uniform1f(renderer2D.uRotation, 0.0f);
            gl.uniform3f(renderer2D.uColor, color.r, color.g, color.b);
            gl.uniform1f(renderer2D.uAspect, aspect);

            gl.bindVertexArray(renderer2D.vao);
            
            gl.drawArrays(GL_TRIANGLE_FAN, renderer2D.circleOffset, renderer2D.circleCount);
        #endif
    }

    void klombleDrawSphere(Klomble::KlombleWindow* window, Klomble::Vec3 position, float size, Klomble::Vec3 rotation, Klomble::Color color)
    {
        if (!window) return;

        #ifdef _WIN32
            using namespace Klomble::detail;
            MakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

            RECT rect;
            GetClientRect((HWND)window->handle, &rect);
            float aspect = (float)(rect.right - rect.left) / (float)(rect.bottom - rect.top);

            gl.useProgram(renderer3D.program);

            if (activeCamera) {
                gl.uniform3f(renderer3D.uCamPos, activeCamera->position.x, activeCamera->position.y, activeCamera->position.z);
                gl.uniform3f(renderer3D.uCamRot, activeCamera->rotation.x, activeCamera->rotation.y, activeCamera->rotation.z);
            } else {
                gl.uniform3f(renderer3D.uCamPos, 0, 0, 0);
                gl.uniform3f(renderer3D.uCamRot, 0, 0, 0);
            }

            gl.uniform3f(renderer3D.uOffset, position.x, position.y, position.z);
            gl.uniform3f(renderer3D.uRotation, rotation.x, rotation.y, rotation.z);
            gl.uniform1f(renderer3D.uScale, size);
            gl.uniform1f(renderer3D.uAspect, aspect);
            gl.uniform3f(renderer3D.uColor, color.r, color.g, color.b);

            gl.bindVertexArray(renderer3D.cubeVAO);
            
            gl.drawArrays(GL_TRIANGLES, renderer3D.sphereOffset, renderer3D.sphereCount);
        #endif
    }

    int klombleUpdate(Klomble::KlombleWindow* window)
    {
        if (!window) return 0;

        #ifdef _WIN32
            using namespace Klomble::detail;

            SwapBuffers((HDC)window->deviceContext);

            glFlush();

            // add to clock

            LARGE_INTEGER currentTime;
            QueryPerformanceCounter(&currentTime);

            deltaTime = (float)((currentTime.QuadPart - timeLast.QuadPart) / (double)timeFrequency.QuadPart);
            timeLast = currentTime;

            MSG msg;
            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
                if (msg.message == WM_QUIT) {
                    return 0;
                }
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        #endif

        return 1;
    }

    float klombleGetDeltaTime()
    {
        #ifdef _WIN32
            return Klomble::detail::deltaTime;
        #else
            return 0.016f;
        #endif
    }

    bool klombleIsKeyDown(int key)
    {
        #ifdef _WIN32
            if (key >= 0 && key < 256) {
                return Klomble::detail::keys[key];
            }
        #endif
        return false;
    }

    float klombleGetFPS()
    {
        #ifdef _WIN32
            float dt = Klomble::detail::deltaTime;
            if (dt <= 0.0f) return 0.0f;
            float fps = 1.0f / dt;
            return std::round(fps * 10.0f) / 10.0f;
        #else
            return 0.0f;
        #endif
    }

    void klombleCloseWindow(Klomble::KlombleWindow* window)
    {
        if (!window) return;

        #ifdef _WIN32
            wglMakeCurrent(NULL, NULL);
            wglDeleteContext((HGLRC)window->renderingContext);
            ReleaseDC((HWND)window->handle, (HDC)window->deviceContext);
            DestroyWindow((HWND)window->handle);
        #endif

        free(window);
    }

    void klombleSetWindowTitle(Klomble::KlombleWindow* window, const char* title)
    {
        if (!window || !window->handle) return;

        #ifdef _WIN32
            SetWindowTextA((HWND)window->handle, title);
        #endif
    }

    // camera

    void klombleSetActiveCamera(Klomble::Camera3D* cam)
    {
        Klomble::detail::activeCamera = cam;
    }

    void klombleUpdateFreeCamera(Klomble::KlombleWindow* window, Klomble::Camera3D& cam, float speed, float sensitivity) {
        #ifdef _WIN32
            RECT rect;
            GetClientRect((HWND)window->handle, &rect);
            POINT center = { (rect.left + rect.right) / 2, (rect.top + rect.bottom) / 2 };

            POINT p;
            GetCursorPos(&p);
            ScreenToClient((HWND)window->handle, &p);

            cam.lastMousePos = cam.mousePos;
            cam.mousePos = { (float)p.x, (float)p.y };

            float dt = klombleGetDeltaTime();
            float move = speed * dt;

            float yaw = cam.rotation.y * 3.14159265f / 180.0f;

            Klomble::Vec3 forward(-std::sin(yaw), 0.0f, -std::cos(yaw));
            Klomble::Vec3 right(std::cos(yaw), 0.0f, -std::sin(yaw));

            if (klombleIsKeyDown(Klomble::W))
            {
                cam.position.x += forward.x * move;
                cam.position.z += forward.z * move;
            }

            if (klombleIsKeyDown(Klomble::S))
            {
                cam.position.x -= forward.x * move;
                cam.position.z -= forward.z * move;
            }

            if (klombleIsKeyDown(Klomble::A))
            {
                cam.position.x -= right.x * move;
                cam.position.z -= right.z * move;
            }

            if (klombleIsKeyDown(Klomble::D))
            {
                cam.position.x += right.x * move;
                cam.position.z += right.z * move;
            }

            float dx = (float)p.x - (float)center.x;
            float dy = (float)p.y - (float)center.y;

            cam.rotation.y += -(dx * sensitivity);
            cam.rotation.x += -(dy * sensitivity);
            cam.rotation.x = std::max(-89.0f, std::min(89.0f, cam.rotation.x)); // clamp

            // center mouse for next frame

            POINT screenCenter = center;
            ClientToScreen((HWND)window->handle, &screenCenter);
            SetCursorPos(screenCenter.x, screenCenter.y);
        #endif
    }

    void klombleLogError(const char* message)
    {
        fprintf(stderr, "[Klomble Error] %s\n", message);
    }

    void* klombleLoadGLFunction(const char* name)
    {
        void* ptr = (void*)wglGetProcAddress(name);

        // some drivers return invalid values

        if (ptr == 0 || ptr == (void*)0x1 || ptr == (void*)0x2 || ptr == (void*)0x3 || ptr == (void*)-1)
        {
            HMODULE module = LoadLibraryA("opengl32.dll");
            if (module)
                ptr = (void*)GetProcAddress(module, name);
        }

        if (!ptr)
        {
            fprintf(stderr,
                "[Klomble] Failed to load OpenGL function: %s\n",
                name);
        }

        return ptr;
    }
    #endif // klomble implementation

    #endif // win32
#endif // KLOMBLE_H
