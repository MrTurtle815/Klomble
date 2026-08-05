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
Website: Coming soon :-)

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
}

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

#endif

#ifdef _WIN32
    #include <windows.h>
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

static PFNGLGENVAOPROC _glGenVertexArrays;
static PFNGLBINDVAOPROC _glBindVertexArray;
static PFNGLGENBUFPROC _glGenBuffers;
static PFNGLBINDBUFPROC _glBindBuffer;
static PFNGLBUFDATAPROC _glBufferData;
static PFNGLVAPPROC _glVertexAttribPointer;
static PFNGLEVAPROC _glEnableVertexAttribArray;
static PFNGLCREATESHADERPROC _glCreateShader;
static PFNGLSHADERSRCPROC _glShaderSource;
static PFNGLCOMPILEPROC _glCompileShader;
static PFNGLCREATEPROGPROC _glCreateProgram;
static PFNGLATTACHPROC _glAttachShader;
static PFNGLLINKPROC _glLinkProgram;
static PFNGLUSEPROGPROC _glUseProgram;
static PFNGLGETULOCPROC _glGetUniformLocation;
static PFNGLU2FPROC _glUniform2f;
static PFNGLU3FPROC _glUniform3f;
static PFNGLU1FPROC _glUniform1f;

static GLuint klomble3DProgram;
static GLuint klombleCubeVAO, klombleCubeVBO;
static GLint k3DUOffset, k3DUScale, k3DURotation, k3DUColor, k3DUAspect;

static GLuint klombleProgram, klombleVAO, klombleVBO;
static GLint klombleUOffset, klombleUScale, klombleUColor, klombleURotation;
static int klombleGLReady = 0;

static void klombleInitGL()
{
    if (klombleGLReady) return;

    _glGenVertexArrays = (PFNGLGENVAOPROC)wglGetProcAddress("glGenVertexArrays");
    _glBindVertexArray = (PFNGLBINDVAOPROC)wglGetProcAddress("glBindVertexArray");
    _glGenBuffers = (PFNGLGENBUFPROC)wglGetProcAddress("glGenBuffers");
    _glBindBuffer = (PFNGLBINDBUFPROC)wglGetProcAddress("glBindBuffer");
    _glBufferData = (PFNGLBUFDATAPROC)wglGetProcAddress("glBufferData");
    _glVertexAttribPointer = (PFNGLVAPPROC)wglGetProcAddress("glVertexAttribPointer");
    _glEnableVertexAttribArray = (PFNGLEVAPROC)wglGetProcAddress("glEnableVertexAttribArray");
    _glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
    _glShaderSource = (PFNGLSHADERSRCPROC)wglGetProcAddress("glShaderSource");
    _glCompileShader = (PFNGLCOMPILEPROC)wglGetProcAddress("glCompileShader");
    _glCreateProgram = (PFNGLCREATEPROGPROC)wglGetProcAddress("glCreateProgram");
    _glAttachShader = (PFNGLATTACHPROC)wglGetProcAddress("glAttachShader");
    _glLinkProgram = (PFNGLLINKPROC)wglGetProcAddress("glLinkProgram");
    _glUseProgram = (PFNGLUSEPROGPROC)wglGetProcAddress("glUseProgram");
    _glGetUniformLocation = (PFNGLGETULOCPROC)wglGetProcAddress("glGetUniformLocation");
    _glUniform2f = (PFNGLU2FPROC)wglGetProcAddress("glUniform2f");
    _glUniform3f = (PFNGLU3FPROC)wglGetProcAddress("glUniform3f");
    _glUniform1f = (PFNGLU1FPROC)wglGetProcAddress("glUniform1f");

    const char* vertexShader3DSource = R"(#version 330
    layout(location=0) in vec3 aPos;
    
    uniform vec3 uOffset;
    uniform vec3 uRotation;
    uniform float uScale;
    uniform float uAspect;

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
    
    GLuint vertexShader = _glCreateShader(GL_VERTEX_SHADER);
    _glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    _glCompileShader(vertexShader);

    GLuint fragmentShader = _glCreateShader(GL_FRAGMENT_SHADER);
    _glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    _glCompileShader(fragmentShader);

    klombleProgram = _glCreateProgram();
    _glAttachShader(klombleProgram, vertexShader);
    _glAttachShader(klombleProgram, fragmentShader);
    _glLinkProgram(klombleProgram);

    klombleUOffset = _glGetUniformLocation(klombleProgram, "uOffset");
    klombleUScale  = _glGetUniformLocation(klombleProgram, "uScale");
    klombleUColor  = _glGetUniformLocation(klombleProgram, "uColor");
    klombleURotation = _glGetUniformLocation(klombleProgram, "uRotation");

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

    _glGenVertexArrays(1, &klombleVAO);
    _glBindVertexArray(klombleVAO);
    
    _glGenBuffers(1, &klombleVBO);
    _glBindBuffer(GL_ARRAY_BUFFER, klombleVBO);
    
    _glBufferData(GL_ARRAY_BUFFER, sizeof(shapes), shapes, GL_STATIC_DRAW);
    
    _glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    _glEnableVertexAttribArray(0);

    // 3d
    
    GLuint vs3D = _glCreateShader(GL_VERTEX_SHADER);
    _glShaderSource(vs3D, 1, &vertexShader3DSource, NULL);
    _glCompileShader(vs3D);
    
    klomble3DProgram = _glCreateProgram();
    _glAttachShader(klomble3DProgram, vs3D);
    _glAttachShader(klomble3DProgram, fragmentShader);
    _glLinkProgram(klomble3DProgram);

    k3DUOffset = _glGetUniformLocation(klomble3DProgram, "uOffset");
    k3DUScale = _glGetUniformLocation(klomble3DProgram, "uScale");
    k3DURotation = _glGetUniformLocation(klomble3DProgram, "uRotation");
    k3DUColor = _glGetUniformLocation(klomble3DProgram, "uColor");
    k3DUAspect = _glGetUniformLocation(klomble3DProgram, "uAspect");

    float cubeVertices[] = {
        -0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f, 0.5f,-0.5f,  0.5f, 0.5f,-0.5f, -0.5f, 0.5f,-0.5f, -0.5f,-0.5f,-0.5f,
        -0.5f,-0.5f, 0.5f,  0.5f,-0.5f, 0.5f,  0.5f, 0.5f, 0.5f,  0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f,-0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,-0.5f, -0.5f,-0.5f,-0.5f, -0.5f,-0.5f,-0.5f, -0.5f,-0.5f, 0.5f, -0.5f, 0.5f, 0.5f,
         0.5f, 0.5f, 0.5f,  0.5f, 0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f, 0.5f,  0.5f, 0.5f, 0.5f,
        -0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f, 0.5f,  0.5f,-0.5f, 0.5f, -0.5f,-0.5f, 0.5f, -0.5f,-0.5f,-0.5f,
        -0.5f, 0.5f,-0.5f,  0.5f, 0.5f,-0.5f,  0.5f, 0.5f, 0.5f,  0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,-0.5f
    };

    _glGenVertexArrays(1, &klombleCubeVAO);
    _glGenBuffers(1, &klombleCubeVBO);
    _glBindVertexArray(klombleCubeVAO);
    _glBindBuffer(GL_ARRAY_BUFFER, klombleCubeVBO);
    _glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    _glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    _glEnableVertexAttribArray(0);

    klombleGLReady = 1;
}

#endif

// klomble windwo

#ifdef _WIN32
    static LARGE_INTEGER klombleTimeFrequency;
    static LARGE_INTEGER klombleTimeLast;
    static float klombleDeltaTime = 0.0f;

    static bool klombleKeys[256] = { false };

    static LRESULT CALLBACK KlombleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg) {
            // keyboard input

            case WM_KEYDOWN:
                if (wParam >= 0 && wParam < 256) klombleKeys[wParam] = true;
                return 0;
            case WM_KEYUP:
                if (wParam >= 0 && wParam < 256) klombleKeys[wParam] = false;
                return 0;

            case WM_PAINT:
                ValidateRect(hwnd, NULL);
                return 0;
            case WM_DESTROY:
            case WM_CLOSE:
                PostQuitMessage(0);
                return 0;
            default:
                return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }
#endif

inline KlombleWindow* klombleCreateWindow(int width, int height, const char* title)
{
    KlombleWindow* window = (KlombleWindow*)malloc(sizeof(KlombleWindow));
    window->width = width;
    window->height = height;

    #ifdef _WIN32
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

        klombleInitGL();

        QueryPerformanceFrequency(&klombleTimeFrequency);
        QueryPerformanceCounter(&klombleTimeLast);
    #endif

    return window;
}

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

        RECT rect;
        GetClientRect((HWND)window->handle, &rect);
        float aspect = (float)(rect.right - rect.left) / (float)(rect.bottom - rect.top);

        _glUseProgram(klomble3DProgram);
        
        _glUniform3f(k3DUOffset, position.x, position.y, position.z);
        _glUniform3f(k3DURotation, rotation.x, rotation.y, rotation.z);
        _glUniform1f(k3DUScale, size);
        _glUniform1f(k3DUAspect, aspect);
        _glUniform3f(k3DUColor, color.r, color.g, color.b);

        _glBindVertexArray(klombleCubeVAO); 
        glDrawArrays(GL_TRIANGLES, 0, 36);
    #endif
}

inline void klombleDrawSquare(KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color)
{
    if (!window) return;

    #ifdef _WIN32
        wglMakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

        _glUseProgram(klombleProgram);
        
        _glUniform2f(klombleUOffset, position.x, position.y);
        _glUniform1f(klombleUScale, size);
        _glUniform1f(klombleURotation, rotation);
        _glUniform3f(klombleUColor, color.r, color.g, color.b);

        _glBindVertexArray(klombleVAO);
        
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4); 
    #endif
}

inline void klombleDrawTriangle(KlombleWindow* window, Klomble::Vec2 position, float size, float rotation, Klomble::Color color)
{
    if (!window) return;

    #ifdef _WIN32
        wglMakeCurrent((HDC)window->deviceContext, (HGLRC)window->renderingContext);

        _glUseProgram(klombleProgram);
        
        _glUniform2f(klombleUOffset, position.x, position.y);
        _glUniform1f(klombleUScale, size);
        _glUniform1f(klombleURotation, rotation);
        _glUniform3f(klombleUColor, color.r, color.g, color.b);

        _glBindVertexArray(klombleVAO); 
        
        // start at vertex 4 and draw 3 vertices
        glDrawArrays(GL_TRIANGLES, 4, 3); 
    #endif
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

inline int klombleUpdate(KlombleWindow* window)
{
    if (!window) return 0;

    #ifdef _WIN32
        SwapBuffers((HDC)window->deviceContext); 

        LARGE_INTEGER currentTime;
        QueryPerformanceCounter(&currentTime);

        klombleDeltaTime = (float)((currentTime.QuadPart - klombleTimeLast.QuadPart) / (double)klombleTimeFrequency.QuadPart);
        klombleTimeLast = currentTime;

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
        return klombleDeltaTime;
    #else
        return 0.016f;
    #endif
}

inline bool klombleIsKeyDown(int key) 
{
    if (key >= 0 && key < 256) {
        return klombleKeys[key];
    }
    return false;
}