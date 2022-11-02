#include <array>
#include <iostream>
#include "shader.h"
#include "colorsettings.h"

class Background{
    public:
    Background();
    void initRenderData();
    void drawBackground();

    private:
    Shader backgroundShader;
    unsigned int VAO;
    ColorSettings background;

};
