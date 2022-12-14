#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "colorsettings.h"
#include "game.h"
#include <functional>
#include <boost/bind.hpp>
#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 800
//global variables that tracks mouse movement
int previous_mousex;
int mousexchange;
//functions for callbacks: framebuffer, mouse position, input processing
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, Entity* playerentity);
void mouse_callback(GLFWwindow* window, double xpos, double ypose);
int main()
{
       glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raycaster", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetCursorPosCallback(window, mouse_callback);
    Game raycaster(WINDOW_WIDTH, WINDOW_HEIGHT);
    ColorSettings color; 

    raycaster.Init();
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

        int i = 0;
    while(!glfwWindowShouldClose(window))
    {
        glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        processInput(window, raycaster.playerReference());
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glClearColor(color.sand[0], color.sand[1], color.sand[2], color.sand[3]);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        raycaster.Update(deltaTime);
        raycaster.Render();
        // glClearColor(0.75f, 0.82f, 0.8f, 1.0f);
         
        glfwSwapBuffers(window);
        i++;
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

        playerentity->rotateEntityClockwise();
               mousexchange = 0;
    }
    if(mousexchange>0){
 playerentity->rotateEntityCounterClockwise();

        mousexchange = 0;
    }
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
