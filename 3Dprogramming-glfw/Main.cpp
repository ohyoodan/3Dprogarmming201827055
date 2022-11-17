#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
#include"MuSoenMath.h"
#include <cstdlib>
#include <iostream>
using namespace MuSoenMath;
#pragma comment(lib, "OpenGL32")

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
    window = glfwCreateWindow(1280, 960, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        float Pi = 3.141;//파이
        float r = 1;//반지름 값 또는 삼각형의 빗변

        ////90도와 같이 각도로 연산하고 싶으면
        ////glm의 삼각함수는 radian 형식으로 입력을 받기 때문에 변환해서 넣어주어야한다.
        //glm::sin(glm::radians(90.0));  






        glClearColor(0.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINE_STRIP);
        /*glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);*/


        srand((unsigned int)time(NULL));




        for (float angle = 0.0f; angle <= 360; angle++) {

            float x, y;
            x = glm::cos(glm::radians(angle * Pi)) * r; //현재 위치에서 파이를 더하고 라디안으로 바꿈
            y = glm::sin(glm::radians(angle * Pi)) * r;
            //솔직히 이게 왜 원 그려지는 지는 모름 하다보니 됨
            float a, b, c;
            a = rand() % 5;
            b = rand() % 5;
            c = rand() % 5;


            glColor4f(a, b, c, 1.0f);
            glVertex3f(0.0f + x, 0.0f + y, 0.0f);
        }

        glEnd();


        //1. glm에 있는 sin 과 cos 함수를 활용하여 OpenGL의 line strip으로 화면에 해당하는 2차원 공간상에서 반지름이 1인 원을 그려보도록 하자.    

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}