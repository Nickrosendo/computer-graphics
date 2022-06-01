#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

static void draw_first_triangle() {
  glBegin( GL_POINTS );
  glColor4f( 0.95f, 0.207, 0.031f, 1.0f );
  glVertex2f(-0.5f, 0.9f);
  glVertex2f(-0.9, 0);
  glVertex2f(-0.5f, -0.9f);

  glEnd();
}

static void draw_second_triangle() {
  glBegin( GL_POINTS );
  glColor4f( 0.95f, 0.207, 0.031f, 1.0f );
  glVertex2f(0.5f, 0.9f);
  glVertex2f(0.9f, 0);
  glVertex2f(0.5f, -0.9f);

  glEnd();
}



static void draw_triangles() {
  draw_first_triangle();
  draw_second_triangle();
}


int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Two Triangles - ex5", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glPointSize( 10.0 );
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        draw_triangles(); 
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
