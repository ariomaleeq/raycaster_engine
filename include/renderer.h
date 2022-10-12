#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "colorsettings.h"
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 
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
