#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <thread>
#include <String>


#pragma comment(lib, "OpenGL32")



using namespace std;
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    float f = 0.0f;
    float l = 0.0f;
    int count = 0;

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
        {
            l = l - 0.01f;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
        {
            f = f + 0.01f;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
        {
            l = l + 0.01f;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
        {
            f = f - 0.01f;
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
        {
            system("cls");
        }

        glClearColor(0.3f, 0.3f, 0.3f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        //고정상자
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.5f, 0.6f); //오른쪽 위
        glVertex2f(0.4f, 0.6f); //왼쪽위
        glVertex2f(0.4f, 0.5f); //왼쪽 아래
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.5f, 0.6f);
        glVertex2f(0.5f, 0.5); //오른쪽아래
        glVertex2f(0.4f, 0.5f);
        glEnd();
        //움직이는 상자
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(l, f + 0.1f);//오른쪽위
        glVertex2f(l - 0.1f, f + 0.1f);//왼쪽위
        glVertex2f(l - 0.1f, f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(l, f + 0.1f);
        glVertex2f(l, f); // 오른쪽아래
        glVertex2f(l - 0.1f, f); //왼쪽아래
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (l > 0.4 && l < 0.5f)
        {
            if (f + 0.1f > 0.5f && f + 0.1f < 0.6f)
            {
                cout << "충돌" << endl;
            }
        }

        if (l - 0.1f > 0.4 && l - 0.1f < 0.5f)
        {
            if (f + 0.1f > 0.5f && f + 0.1f < 0.6f)
            {
                cout << "충돌" << endl;
            }
        }

        if (l > 0.4 && l < 0.5f)
        {
            if (f > 0.5f && f < 0.6f)
            {
                cout << "충돌" << endl;
            }
        }

        if (l - 0.1f > 0.4 && l - 0.1f < 0.5f)
        {
            if (f > 0.5f && f < 0.6f)
            {
                cout << "충돌" << endl;
            }
        }
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}// 속도가 너무 빠른데 고칠수가없넹..//