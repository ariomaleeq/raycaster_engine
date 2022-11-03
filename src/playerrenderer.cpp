#include "playerrenderer.h"
#include "shader.h"

void PlayerRenderer::initRenderData(){

}

void PlayerRenderer::initRenderData(std::array<float, 3> &state){
unsigned int VBO;
ColorSettings colormap2;
//0,000195313 is 10 pixel

float* vertices = new float[state.size()*4];
vertices[0] = state[0];
vertices[1] = state[1];
vertices[2] = 0.0f;
vertices[3] = colormap2.black[0];
vertices[4] = colormap2.black[1];
vertices[5] = colormap2.black[2];
vertices[6] = vertices[0]+((cos((state[2]/360)*2*M_PI))*15);
vertices[7] = vertices[1]+((sin((state[2]/360)*2*M_PI))*15);
vertices[8] = 0.0f;
vertices[9] = colormap2.black[0];
vertices[10] = colormap2.black[1];
vertices[11] = colormap2.black[2];

glGenVertexArrays(1, &this->quadVAO);
glBindVertexArray(this->quadVAO);
glGenBuffers(1, &VBO);
glBindBuffer(GL_ARRAY_BUFFER,VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(float)*12,vertices,GL_DYNAMIC_DRAW);

glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
glEnableVertexAttribArray(0);
glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3*sizeof(float)));
glEnableVertexAttribArray(1);

delete[] vertices;
vertices = NULL;
glBindBuffer(GL_ARRAY_BUFFER,0);
glBindVertexArray(0);
}

void PlayerRenderer::DrawObject(){
this->shader.use();
this->shader.setMatrix4("projection", this->projection);
glBindVertexArray(this->quadVAO);
glLineWidth(2);
glDrawArrays(GL_LINES,0,2);
glPointSize(5);
glDrawArrays(GL_POINTS,0,1);

glBindVertexArray(0);
}
