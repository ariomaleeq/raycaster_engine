#include "input_handler.h"


Command* InputHandler::handleInput(GLFWwindow* window){
if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
{
    glfwSetWindowShouldClose(window, true);
}
if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
       return w_command; 

    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        return s_command;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        return a_command;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        return d_command;
    }
 if(glfwGetKey(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        return right_click_command;
    }
   return nullptr;
}
