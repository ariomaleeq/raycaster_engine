#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "colorsettings.h"
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "texture.h"

class Renderer{
    public:
    Renderer();
    Renderer(Shader& shader);    
   
    void virtual initRenderData();
    void virtual initSpriteData(Texture2D &texture, glm::vec2 position, 
            glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, 
            glm::vec3 color = glm::vec3(1.0f));
    void virtual drawSprite(Texture2D &texture, glm::vec2 position, 
  glm::vec2 size, float rotate, glm::vec3 color);
    void virtual DrawObject();
    virtual ~Renderer();

    protected:

    Shader shader;
    

    unsigned int spriteVAO;

    unsigned int quadVAO;
};
#endif
