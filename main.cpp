#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <format>
void error (int error, const char * description)
{
    fputs (description, stderr);
}
void key (GLFWwindow * window, int key, int scancode, int action, int mods)
{
    if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
        glfwSetWindowShouldClose ( window, GL_TRUE );
}
void display (GLFWwindow * window)
{
    int width, height;
    glfwGetFramebufferSize (window, &width, &height );
    //float ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
}
void mouseKey (GLFWwindow * win, int button, int action, int mode)
{
    double x, y;
    glfwGetCursorPos ( win, &x, &y );
    std::string MouseCoord = std::format("Mouse coord is X:{} Y:{}", x, y);
    if ( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS )
        std::cout << MouseCoord <<std::endl;
}
int main ()
{
    glfwSetErrorCallback (error);
    if ( !glfwInit() )
        exit ( 1 );
    GLFWwindow * window = glfwCreateWindow
     (640, 480, "Simple example", NULL, NULL);
    if ( !window)
    {
        glfwTerminate ();
        exit ( 1 );
    }
    glfwMakeContextCurrent (window);
    glfwSwapInterval (1);
    glfwSetKeyCallback (window, key);
    glfwSetMouseButtonCallback (window, mouseKey);
    while (!glfwWindowShouldClose (window))
    {
        display (window);
            // выполнить требуемый рендеринг
        glfwSwapBuffers (window);
        glfwPollEvents ();
    }
    glfwDestroyWindow (window);
    glfwTerminate();
    return 0;
}
