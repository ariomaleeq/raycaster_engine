#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "colorsettings.h"
#include <array>
class Renderer{
    public:
    Renderer(Shader& shader);    
   
    void virtual initRenderData();
    void virtual DrawObject();
    virtual ~Renderer();

    protected:

    Shader shader;

    unsigned int quadVAO;
};
#endif
