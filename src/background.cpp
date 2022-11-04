#include "background.h"

Background::Background(){
    this->initRenderData();
    this->backgroundShader= Shader("../src/shaders/map.vs", "../src/shaders/map.frag");
}

void Background::initRenderData(){
float vertices[] = {
    // positions          // colors
    -1.0f,  0.0f, 0.0f,  background.sand[0]-0.35f, background.sand[1]-0.35f ,background.sand[2]-0.35f  ,  // bottom right
    -1.0f, -1.0f, 0.0f,  background.sand[0]-0.35f, background.sand[1]-0.35f ,background.sand[2]-0.35f  , // bottom left
    1.0f, 0.0f, 0.0f,  background.sand[0]-0.35f, background.sand[1]-0.35f ,background.sand[2]-0.35f  , // top left
    1.0f,  0.0f, 0.0f,  background.sand[0]-0.35f, background.sand[1]-0.35f ,background.sand[2]-0.35f  , // top right
    1.0f,  -1.0f, 0.0f,  background.sand[0]-0.35f, background.sand[1]-0.35f ,background.sand[2]-0.35f  ,
    -1.0f,  -1.0f, 0.0f,  background.sand[0]-0.35f, background.sand[1]-0.35f ,background.sand[2]-0.35f  ,
};
unsigned int VBO;
glGenVertexArrays(1, &this->VAO);
glBindVertexArray(this->VAO);
glGenBuffers(1, &VBO);
glBindBuffer(GL_ARRAY_BUFFER,VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(float)*36,vertices,GL_DYNAMIC_DRAW);

glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
glEnableVertexAttribArray(0);
glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3*sizeof(float)));
glEnableVertexAttribArray(1);

glBindBuffer(GL_ARRAY_BUFFER,0);
glBindVertexArray(0);

}


void Background::drawBackground(){
    this->backgroundShader.use();
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
