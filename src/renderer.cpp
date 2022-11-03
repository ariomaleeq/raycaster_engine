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
