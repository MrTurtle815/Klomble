/*
Klomble

Klomble is a open-source, single-header, multimedia library designed
to let you easily build video games without a steep learning curve!

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

Klomble Links:

GitHub Repository: https://github.com/MrTurtle815/Klomble
Website: klomble.com

Made by MrTurtle815

*/

#pragma once

#ifndef KLOMBLE_H
#define KLOMBLE_H

// namespaec

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
            : position(pos),
            rotation(rot),
            mousePos(mosPos),
            lastMousePos(lastMosPos),
            fov(_fov)
        {}
    };
}

#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_INFO_LOG_LENGTH 0x8B84

// klomble functions

typedef struct {
    void* handle;
    void* deviceContext;
    void* renderingContext;
    int width;
    int height;
} KlombleWindow;


KlombleWindow* klombleCreateWindow(int width, int height, const char* title);
void klombleClearBackground(KlombleWindow* window, Klomble::Color color);

// shapes

inline void klombleDrawCube(KlombleWindow* window, Klomble::Vec3 position, float size, Klomble::Vec3 rotation, Klomble::Color color);
void klombleDrawSquare(KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color);
void klombleDrawTriangle(KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color);

void klombleCloseWindow(KlombleWindow* window);
int klombleUpdate(KlombleWindow* window);
float klombleGetDeltaTime();
bool klombleIsKeyDown(int key);
inline void* klombleLoadGLFunction(const char* name);

// camera

void klombleSetActiveCamera(Klomble::Camera3D* cam);
void klombleUpdateFreeCamera(KlombleWindow* window, Klomble::Camera3D& cam, float speed = 3.0f, float sensitivity = 0.15f);

#ifdef _WIN32
    #include <windows.h>
    #include <windowsx.h>
    #include <stdio.h>
    #include <cmath>
    #include <GL/gl.h>
    #include <stdlib.h>
#endif

// opengl plumbing

#ifdef _WIN32

#ifndef GL_ARRAY_BUFFER
    typedef ptrdiff_t GLsizeiptr;
    typedef char GLchar;
    #define GL_ARRAY_BUFFER     0x8892
    #define GL_STATIC_DRAW      0x88E4
    #define GL_FRAGMENT_SHADER  0x8B30
    #define GL_VERTEX_SHADER    0x8B31
#endif

typedef void (APIENTRY *PFNGLGENVAOPROC)(GLsizei, GLuint*);
typedef void (APIENTRY *PFNGLBINDVAOPROC)(GLuint);
typedef void (APIENTRY *PFNGLGENBUFPROC)(GLsizei, GLuint*);
typedef void (APIENTRY *PFNGLBINDBUFPROC)(GLenum, GLuint);
typedef void (APIENTRY *PFNGLBUFDATAPROC)(GLenum, GLsizeiptr, const void*, GLenum);
typedef void (APIENTRY *PFNGLVAPPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void*);
typedef void (APIENTRY *PFNGLEVAPROC)(GLuint);
typedef GLuint (APIENTRY *PFNGLCREATESHADERPROC)(GLenum);
typedef void (APIENTRY *PFNGLSHADERSRCPROC)(GLuint, GLsizei, const GLchar* const*, const GLint*);
typedef void (APIENTRY *PFNGLCOMPILEPROC)(GLuint);
typedef GLuint (APIENTRY *PFNGLCREATEPROGPROC)(void);
typedef void (APIENTRY *PFNGLATTACHPROC)(GLuint, GLuint);
typedef void (APIENTRY *PFNGLLINKPROC)(GLuint);
typedef void (APIENTRY *PFNGLUSEPROGPROC)(GLuint);
typedef GLint (APIENTRY *PFNGLGETULOCPROC)(GLuint, const GLchar*);
typedef void (APIENTRY *PFNGLU2FPROC)(GLint, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLU3FPROC)(GLint, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLU1FPROC)(GLint, GLfloat);
typedef void (APIENTRY *PFNGLGETSHADERIVPROC)(GLuint, GLenum, GLint*);
typedef void (APIENTRY *PFNGLGETSHADERINFOLOGPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (APIENTRY *PFNGLGETPROGRAMIVPROC)(GLuint, GLenum, GLint*);
typedef void (APIENTRY *PFNGLGETPROGRAMINFOLOGPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (APIENTRY *PFNGLDELETESHADERPROC)(GLuint);
typedef void (APIENTRY *PFNGLBINDVERTEXARRAYPROC)(GLuint);

namespace {

    // loaded GL entry points

    struct GLFunctions {
        PFNGLGENVAOPROC genVertexArrays;
        PFNGLBINDVAOPROC bindVertexArray;
        PFNGLGENBUFPROC genBuffers;
        PFNGLBINDBUFPROC bindBuffer;
        PFNGLBUFDATAPROC bufferData;
        PFNGLVAPPROC vertexAttribPointer;
        PFNGLEVAPROC enableVertexAttribArray;
        PFNGLCREATESHADERPROC createShader;
        PFNGLSHADERSRCPROC shaderSource;
        PFNGLCOMPILEPROC compileShader;
        PFNGLCREATEPROGPROC createProgram;
        PFNGLATTACHPROC attachShader;
        PFNGLLINKPROC linkProgram;
        PFNGLUSEPROGPROC useProgram;
        PFNGLGETULOCPROC getUniformLocation;
        PFNGLU2FPROC uniform2f;
        PFNGLU3FPROC uniform3f;
        PFNGLU1FPROC uniform1f;
        PFNGLGETSHADERIVPROC getShaderiv;
        PFNGLGETSHADERINFOLOGPROC getShaderInfoLog;
        PFNGLGETPROGRAMIVPROC getProgramiv;
        PFNGLGETPROGRAMINFOLOGPROC getProgramInfoLog;
        PFNGLDELETESHADERPROC deleteShader;
    } gl;

    struct Renderer2D {
        GLuint program;
        GLuint vao, vbo;
        GLint  uOffset, uScale, uColor, uRotation;
    } renderer2D;

    struct Renderer3D {
        GLuint program;
        GLuint cubeVAO, cubeVBO;
        GLint  uOffset, uScale, uRotation, uColor, uAspect;
        GLint uCamPos, uCamRot;
    } renderer3D;

    Klomble::Camera3D* activeCamera = nullptr;

    bool glReady = false;

    void initGL()
{
    if (glReady) return;

    // GL functions

    gl.genVertexArrays = (PFNGLGENVAOPROC)klombleLoadGLFunction("glGenVertexArrays");
    gl.bindVertexArray = (PFNGLBINDVAOPROC)klombleLoadGLFunction("glBindVertexArray");

    gl.genBuffers = (PFNGLGENBUFPROC)klombleLoadGLFunction("glGenBuffers");
    gl.bindBuffer = (PFNGLBINDBUFPROC)klombleLoadGLFunction("glBindBuffer");
    gl.bufferData = (PFNGLBUFDATAPROC)klombleLoadGLFunction("glBufferData");

    gl.vertexAttribPointer = (PFNGLVAPPROC)klombleLoadGLFunction("glVertexAttribPointer");
    gl.enableVertexAttribArray = (PFNGLEVAPROC)klombleLoadGLFunction("glEnableVertexAttribArray");

    gl.createShader = (PFNGLCREATESHADERPROC)klombleLoadGLFunction("glCreateShader");
    gl.shaderSource = (PFNGLSHADERSRCPROC)klombleLoadGLFunction("glShaderSource");
    gl.compileShader = (PFNGLCOMPILEPROC)klombleLoadGLFunction("glCompileShader");

    gl.createProgram = (PFNGLCREATEPROGPROC)klombleLoadGLFunction("glCreateProgram");
    gl.attachShader = (PFNGLATTACHPROC)klombleLoadGLFunction("glAttachShader");
    gl.linkProgram = (PFNGLLINKPROC)klombleLoadGLFunction("glLinkProgram");
    gl.useProgram = (PFNGLUSEPROGPROC)klombleLoadGLFunction("glUseProgram");

    gl.getUniformLocation = (PFNGLGETULOCPROC)klombleLoadGLFunction("glGetUniformLocation");

    gl.uniform2f = (PFNGLU2FPROC)klombleLoadGLFunction("glUniform2f");
    gl.uniform3f = (PFNGLU3FPROC)klombleLoadGLFunction("glUniform3f");
    gl.uniform1f = (PFNGLU1FPROC)klombleLoadGLFunction("glUniform1f");

    gl.getShaderiv = (PFNGLGETSHADERIVPROC)klombleLoadGLFunction("glGetShaderiv");
    gl.getShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)klombleLoadGLFunction("glGetShaderInfoLog");
    gl.getProgramiv = (PFNGLGETPROGRAMIVPROC)klombleLoadGLFunction("glGetProgramiv");
    gl.getProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)klombleLoadGLFunction("glGetProgramInfoLog");

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
        void main(){
            float rad = radians(uRotation);
            float c = cos(rad);
            float s = sin(rad);
            
            mat2 rot = mat2(c, s, -s, c);
            
            vec2 finalPos = rot * (aPos * uScale) + uOffset;
            
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

    glEnable(GL_DEPTH_TEST);
    
    GLuint vertexShader = gl.createShader(GL_VERTEX_SHADER);
    gl.shaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    gl.compileShader(vertexShader);

    GLint success;
    gl.getShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char log[1024];
        gl.getShaderInfoLog(vertexShader, sizeof(log), nullptr, log);
        printf("Klomble: Vertex shader compilation failed:\n%s\n", log);
    }

    GLuint fragmentShader = gl.createShader(GL_FRAGMENT_SHADER);
    gl.shaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    gl.compileShader(fragmentShader);

    gl.getShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        char log[1024];
        gl.getShaderInfoLog(fragmentShader, sizeof(log), nullptr, log);
        printf("Klomble: Fragment shader compilation failed:\n%s\n", log);
    }

    renderer2D.program = gl.createProgram();
    gl.attachShader(renderer2D.program, vertexShader);
    gl.attachShader(renderer2D.program, fragmentShader);
    gl.linkProgram(renderer2D.program);

    renderer2D.uOffset = gl.getUniformLocation(renderer2D.program, "uOffset");
    renderer2D.uScale = gl.getUniformLocation(renderer2D.program, "uScale");
    renderer2D.uColor = gl.getUniformLocation(renderer2D.program, "uColor");
    renderer2D.uRotation = gl.getUniformLocation(renderer2D.program, "uRotation");

    float shapes[] = {
        // square vertices 0 1 2 3

        -0.5f, -0.5f,  
         0.5f, -0.5f,  
         0.5f,  0.5f,  
        -0.5f,  0.5f,

        // triangle vertices 4 5 6

         0.0f,  0.5f,  
        -0.5f, -0.5f,  
         0.5f, -0.5f
    };

    gl.genVertexArrays(1, &renderer2D.vao);
    gl.bindVertexArray(renderer2D.vao);
    
    gl.genBuffers(1, &renderer2D.vbo);
    gl.bindBuffer(GL_ARRAY_BUFFER, renderer2D.vbo);
    
    gl.bufferData(GL_ARRAY_BUFFER, sizeof(shapes), shapes, GL_STATIC_DRAW);
    
    gl.vertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    gl.enableVertexAttribArray(0);

    // uses same fragment shader as 2d
    
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

    // cube verticies

    float cubeVertices[] = {
        -0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f, 0.5f,-0.5f,  0.5f, 0.5f,-0.5f, -0.5f, 0.5f,-0.5f, -0.5f,-0.5f,-0.5f,
        -0.5f,-0.5f, 0.5f,  0.5f,-0.5f, 0.5f,  0.5f, 0.5f, 0.5f,  0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f,-0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,-0.5f, -0.5f,-0.5f,-0.5f, -0.5f,-0.5f,-0.5f, -0.5f,-0.5f, 0.5f, -0.5f, 0.5f, 0.5f,
         0.5f, 0.5f, 0.5f,  0.5f, 0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f, 0.5f,  0.5f, 0.5f, 0.5f,
        -0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f, 0.5f,  0.5f,-0.5f, 0.5f, -0.5f,-0.5f, 0.5f, -0.5f,-0.5f,-0.5f,
        -0.5f, 0.5f,-0.5f,  0.5f, 0.5f,-0.5f,  0.5f, 0.5f, 0.5f,  0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,-0.5f
    };

    gl.genVertexArrays(1, &renderer3D.cubeVAO);
    gl.genBuffers(1, &renderer3D.cubeVBO);
    gl.bindVertexArray(renderer3D.cubeVAO);
    gl.bindBuffer(GL_ARRAY_BUFFER, renderer3D.cubeVBO);
    gl.bufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    gl.vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    gl.enableVertexAttribArray(0);

    glReady = true;
}

} // namespace

#endif

// klomble windwo

#ifdef _WIN32
    namespace {
        // delta time

        LARGE_INTEGER timeFrequency;
        LARGE_INTEGER timeLast;
        float deltaTime = 0.0f;

        bool keys[256] = { false };
    }

    static LRESULT CALLBACK KlombleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
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

inline void klombleClearBackground(KlombleWindow* window, Klomble::Color color) 
{
    if (!window) return;

    #ifdef _WIN32
        wglMakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);
        glClearColor(color.r, color.g, color.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    #endif
}

// shapes

inline void klombleDrawCube(KlombleWindow* window, Klomble::Vec3 position, float size, Klomble::Vec3 rotation, Klomble::Color color)
{
    if (!window) return;

    #ifdef _WIN32
        wglMakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

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
        glDrawArrays(GL_TRIANGLES, 0, 36);
    #endif
}

inline void klombleDrawTriangle(KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color)
{
    if (!window) return;

    #ifdef _WIN32
        wglMakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

        gl.useProgram(renderer2D.program);
        
        gl.uniform2f(renderer2D.uOffset, position.x, position.y);
        gl.uniform1f(renderer2D.uScale, size);
        gl.uniform1f(renderer2D.uRotation, rotation);
        gl.uniform3f(renderer2D.uColor, color.r, color.g, color.b);

        gl.bindVertexArray(renderer2D.vao); 
        
        // start at vertex 4 and draw 3 vertices

        glDrawArrays(GL_TRIANGLES, 4, 3); 
    #endif
}

inline KlombleWindow* klombleCreateWindow(int width, int height, const char* title)
{
    KlombleWindow* window = (KlombleWindow*)malloc(sizeof(KlombleWindow));
    window->width = width;
    window->height = height;

    #ifdef _WIN32

        // register the window class

        HINSTANCE hInstance = GetModuleHandle(NULL);
        const char* className = "KlombleWindowClass";

        WNDCLASS wc = {0};
        wc.lpfnWndProc = KlombleWindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = className;
        wc.style = CS_OWNDC; 

        RegisterClass(&wc);

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
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
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

        initGL();

        QueryPerformanceFrequency(&timeFrequency);
        QueryPerformanceCounter(&timeLast);
    #endif

    return window;
}

inline void klombleDrawSquare(KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color)
{
    if (!window) return;

    #ifdef _WIN32
        wglMakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

        gl.useProgram(renderer2D.program);
        
        gl.uniform2f(renderer2D.uOffset, position.x, position.y);
        gl.uniform1f(renderer2D.uScale, size);
        gl.uniform1f(renderer2D.uRotation, rotation);
        gl.uniform3f(renderer2D.uColor, color.r, color.g, color.b);

        gl.bindVertexArray(renderer2D.vao);
        
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4); 
    #endif
}

inline int klombleUpdate(KlombleWindow* window)
{
    if (!window) return 0;

    #ifdef _WIN32
        SwapBuffers((HDC)window->deviceContext); 

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

inline float klombleGetDeltaTime() 
{
    #ifdef _WIN32
        return deltaTime;
    #else
        return 0.016f;
    #endif
}

inline bool klombleIsKeyDown(int key) 
{
    if (key >= 0 && key < 256) {
        return keys[key];
    }
    return false;
}

inline void klombleCloseWindow(KlombleWindow* window)
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

// camera

inline void klombleSetActiveCamera(Klomble::Camera3D* cam)
{
    activeCamera = cam;
}

inline void klombleUpdateFreeCamera(KlombleWindow* window, Klomble::Camera3D& cam, float speed, float sensitivity) {

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
}

void klombleLogError(const char* message)
{
    fprintf(stderr, "[Klomble Error] %s\n", message);
}

inline void* klombleLoadGLFunction(const char* name)
{
    void* ptr = (void*)wglGetProcAddress(name);

    // some drivers return invalid values

    if (ptr == 0 ||
        ptr == (void*)0x1 ||
        ptr == (void*)0x2 ||
        ptr == (void*)0x3 ||
        ptr == (void*)-1)
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

#endif
