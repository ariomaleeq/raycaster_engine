#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "colorsettings.h"
#include "game.h"
#include <functional>
#include <boost/bind.hpp>
#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 800
int previous_mousex;
int mousexchange;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, Entity* playerentity);
void mouse_callback(GLFWwindow* window, double xpos, double ypose);
int main()
{
    Game raycaster(WINDOW_WIDTH, WINDOW_HEIGHT);
    ColorSettings color; 
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raycaster", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    glfwSetCursorPosCallback(window, mouse_callback);
    raycaster.Init();
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while(!glfwWindowShouldClose(window))
    {
        processInput(window, raycaster.playerReference());
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwPollEvents();
        raycaster.Update(deltaTime);
        raycaster.Render();
        // glClearColor(0.75f, 0.82f, 0.8f, 1.0f);
        glClearColor(color.lighterblue[0], color.lighterblue[1], color.lighterblue[2], color.lighterblue[3]);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    int mousex = xpos;
    mousexchange = mousex - previous_mousex;
    previous_mousex = mousex;
}
void processInput(GLFWwindow* window, Entity* playerentity)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        playerentity->moveEntityUp();

    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        playerentity->moveEntityDown();
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        playerentity->moveEntityLeft();
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        playerentity->moveEntityRight();
    }
    if(mousexchange<0){
        playerentity->rotateEntityCounterClockwise();
        mousexchange = 0;
    }
    if(mousexchange>0){
        playerentity->rotateEntityClockwise();
        mousexchange = 0;
    }
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
