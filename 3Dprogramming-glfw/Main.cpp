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
        float Pi = 3.141;//����
        float r = 1;//������ �� �Ǵ� �ﰢ���� ����

        ////90���� ���� ������ �����ϰ� ������
        ////glm�� �ﰢ�Լ��� radian �������� �Է��� �ޱ� ������ ��ȯ�ؼ� �־��־���Ѵ�.
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
            x = glm::cos(glm::radians(angle * Pi)) * r; //���� ��ġ���� ���̸� ���ϰ� �������� �ٲ�
            y = glm::sin(glm::radians(angle * Pi)) * r;
            //������ �̰� �� �� �׷����� ���� �� �ϴٺ��� ��
            float a, b, c;
            a = rand() % 5;
            b = rand() % 5;
            c = rand() % 5;


            glColor4f(a, b, c, 1.0f);
            glVertex3f(0.0f + x, 0.0f + y, 0.0f);
        }

        glEnd();


        //1. glm�� �ִ� sin �� cos �Լ��� Ȱ���Ͽ� OpenGL�� line strip���� ȭ�鿡 �ش��ϴ� 2���� �����󿡼� �������� 1�� ���� �׷������� ����.    

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}