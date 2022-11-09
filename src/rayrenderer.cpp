#include "rayrenderer.h"
void RayRenderer::initRenderData(){
    std::cout<<"constructor was called"<<std::endl;
}
void RayRenderer::initRenderData(std::array<float, raynum> &distance, std::array<int, raynum> &color, std::array<float, 3> &state)
{


    unsigned int VBO;
        float rayoffset = -25;
    float rayangle = state[2]+rayoffset;
    if (rayangle<0){
        rayangle = 360 + rayangle;
    }
    if (rayangle>360){
        rayangle = rayangle - 360;
    }

    float** rayarray = new float*[raynum];
 for(int i = 0; i<raynum;i++){
 if (rayangle<0){
        rayangle = 360 + rayangle;
    }
    if (rayangle>360){
        rayangle = rayangle - 360;
    }

        rayarray[i]  = new float[12];

    for(int j = 0; j<1; j++){
        float lineh = (((800*50)/distance[i])*cos(((state[2]-rayangle)/360)*2*M_PI));

        if (lineh>800){
            lineh = 800;;
        }
        float lineo = 400-(lineh/2);
        rayarray[i][j] = (i*5);
        rayarray[i][j+1] = 0; //lineo;
        rayarray[i][j+2] = 0;
        if(color[i] == 1){
            rayarray[i][j+3] = this->colors.brown[0];
            rayarray[i][j+4]= this->colors.brown[1];
            rayarray[i][j+5] = this->colors.brown[2];
        }
        else if(color[i]==0){
            rayarray[i][j+3] = this->colors.darkbrown[0];
            rayarray[i][j+4]= this->colors.darkbrown[1];
            rayarray[i][j+5] = this->colors.darkbrown[2];

        }


        rayarray[i][j+6] = rayarray[i][j];
        rayarray[i][j+7] =1;// lineh+lineo;
        rayarray[i][j+8] = 0;
        rayarray[i][j+9] = rayarray[i][j+3];
        rayarray[i][j+10] = rayarray[i][j+4];
        rayarray[i][j+11] = rayarray[i][j+5];

    }
 glGenVertexArrays(1, &this->quadVAO[i]); //THIS GOES FIRST
    glBindVertexArray(this->quadVAO[i]);

    glGenBuffers(1, &(this->quadVBO[i]));

    glBindBuffer(GL_ARRAY_BUFFER, (this->quadVBO[i]));
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*12, rayarray[i], GL_DYNAMIC_DRAW);
//have to make sure sizeof(vertices) is correct or else it wont show

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
glEnableVertexAttribArray(1);


  delete[] rayarray[i];
   rayangle= rayangle-(rayoffset*2/raynum);
    }




delete[] rayarray;
    rayarray= NULL;
  glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);




}
void RayRenderer::DrawObject(){}
void RayRenderer::DrawObject(std::array<float, raynum> &distance, std::array<int, raynum> &color, std::array<float, 3> &state)
{
    float rayoffset = -25;
    float rayangle = state[2]+rayoffset;
    //Move all of the distances to this area as a uniform to multiply with the
    //original vector value, scale the height of the line and translate the
    //value based on the height
    for(int i = 0; i<raynum; i++){
 if (rayangle<0){
        rayangle = 360 + rayangle;
    }
    if (rayangle>360){
        rayangle = rayangle - 360;
    }

  float lineh = (((800*50)/distance[i])*cos(((state[2]-rayangle)/360)*2*M_PI));

        if (lineh>800){
            lineh = 800.0;
        }
        float lineo = 400-(lineh/2);
    glm::mat4 trans = glm::mat4(1.0f);
   
    trans = glm::translate(trans,glm::vec3(0.0f,lineo,0.0));
 trans = glm::scale(trans,glm::vec3(1,lineh,1));
    glm::vec3 colorvec;
    if(state[2] <90 || state[2]>270){
 
    if(color[i] == 0){
    colorvec = glm::vec3(this->colors.brown[0]-0.075,this->colors.brown[1]-0.075,this->colors.brown[2]-0.075);
    }
    else if(color[i]==1){
    colorvec = glm::vec3(this->colors.brown[0]-0.125,this->colors.brown[1]-0.125,this->colors.brown[2]-0.125);
    }}
    else {

    if(color[i] == 1){
    colorvec = glm::vec3(this->colors.brown[0]-0.075,this->colors.brown[1]-0.075,this->colors.brown[2]-0.075);
    }
    else if(color[i]==0){
    colorvec = glm::vec3(this->colors.brown[0]-0.125,this->colors.brown[1]-0.125,this->colors.brown[2]-0.125);
    }
    }
/*     if(color[i] == 1){ */
    /* colorvec = glm::vec3(this->colors.darkblue[0]-0.075,this->colors.darkblue[1]-0.075,this->colors.darkblue[2]-0.075); */
    /* } */
    /* else if(color[i]==0){ */
    /* colorvec = glm::vec3(this->colors.darkblue[0],this->colors.darkblue[1],this->colors.darkblue[2]); */
    /* } */
/*  */

  this->shader.use();
  this->shader.setMatrix4("projection", this->projection);
  this->shader.setMatrix4("transform",trans);
  this->shader.setVector3("color", colorvec);
    glBindVertexArray(this->quadVAO[i]);
    glLineWidth(30);
    // for(int i = 0; i< 2;i++){
    // glDrawArrays(GL_LINES,(i),((i+2)));
    // }
    glDrawArrays(GL_LINES,0,2);
    // glDrawArrays(GL_LINES,2,2);
    glBindVertexArray(0);
rayangle= rayangle-(rayoffset*2/raynum);

    }

    
    }

