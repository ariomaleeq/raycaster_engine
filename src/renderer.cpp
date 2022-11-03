#include "renderer.h"
Renderer::Renderer(){
    std::cout << "Renderer constructor called" << std::endl;
}
Renderer::Renderer(Shader& shader){
    this->shader = shader;

    this->initRenderData();
}


Renderer::~Renderer()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}
void Renderer::DrawObject(){
}
void Renderer::initRenderData(){

}
void Renderer::initSpriteData(){
 // configure VAO/VBO
    unsigned int VBO;
    float vertices[] = {
        // pos      // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &this->spriteVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->spriteVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void Renderer::drawSprite(glm::vec2 position,
  glm::vec2 size, float rotate, glm::vec3 color){
    this->spriteshader.use();
    this->spriteshader.setMatrix4("projection", this->projection);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    model = glm::scale(model, glm::vec3(size, 1.0f));

    this->spriteshader.setMatrix4("model", model);
    this->spriteshader.setVector3("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    this->texture.Bind();

    glBindVertexArray(this->spriteVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
void Renderer::loadTexture(const char *file, bool alpha, Shader &shader){
    if (alpha){
    this->texture.Internal_Format = GL_RGBA;
    this->texture.Image_Format = GL_RGBA;
    }

    int width, height, nrCHannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrCHannels, 0);

    this->texture.Generate(width, height, data);
    stbi_image_free(data);
    this->spriteshader = shader;

}
