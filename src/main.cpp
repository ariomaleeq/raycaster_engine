#include<glad/glad.h>
#include <GLFW/glfw3.h>

#include "game.h"
#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 800

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, Entity* playerentity);
int main()
{
    Game raycaster(WINDOW_WIDTH, WINDOW_HEIGHT);

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

    raycaster.Init();
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while(!glfwWindowShouldClose(window))
    {
        processInput(window, raycaster.playerreference());
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwPollEvents();
        raycaster.Update(deltaTime);
        raycaster.Render();
        // glClearColor(0.75f, 0.82f, 0.8f, 1.0f);
        glClearColor(0.3764,0.23137,0.2156,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
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
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
