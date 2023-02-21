#include "command.h"
#include<glad/glad.h>
#include <GLFW/glfw3.h>


class InputHandler{
    public:
        virtual ~InputHandler() {}
        Command* handleInput(GLFWwindow* window);
    private:
        Command* w_command;
        Command* a_command;
        Command* s_command;
        Command* d_command;
        Command* right_click_command;

};
