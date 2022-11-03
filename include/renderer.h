#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "colorsettings.h"
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "texture.h"
#include "stb_image.h"

class Renderer{
    public:
    Renderer();
    Renderer(Shader &shader);
    Renderer(Shader& shader1, Shader& shader2);

    void virtual initRenderData();
    void virtual initSpriteData();
    void virtual drawSprite(glm::vec2 position,
  glm::vec2 size, float rotate, glm::vec3 color);
    void virtual DrawObject();
    void virtual loadTexture(const char *file, bool alpha);

    virtual ~Renderer();

    protected:
   Texture2D texture;
    Shader shader;
    Shader spriteshader;
glm::mat4 projection = glm::ortho(0.0f,1600.0f,800.0f,0.0f,-1.0f,1.0f);

    unsigned int spriteVAO;

    unsigned int quadVAO;
};
#endif
