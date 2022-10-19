#include "rayrenderer.h"
void RayRenderer::initRenderData(){
}
void RayRenderer::initRenderData(std::array<float, raynum> &distance, std::array<int, raynum> &color, std::array<float, 3> &state)
{  
   
   
    unsigned int VBO; 
    ColorSettings colors;
    float rayoffset = -40;
    float rayangle = state[2]+rayoffset;
    if (rayangle<0){
        rayangle = 360 + rayangle;
    }
    if (rayangle>359){
        rayangle = rayangle - 360;
    }

    float** rayarray = new float*[raynum];
 for(int i = 0; i<raynum;i++){
 if (rayangle<0){
        rayangle = 360 + rayangle;
    }
    if (rayangle>359){
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
        rayarray[i][j+1] =lineo; 
        rayarray[i][j+2] = 0;
        if(color[i] == 1){
            rayarray[i][j+3] = colors.brown[0];
            rayarray[i][j+4]= colors.brown[1];
            rayarray[i][j+5] = colors.brown[2];
        }
        else if(color[i]==0){
            rayarray[i][j+3] = colors.darkbrown[0];
            rayarray[i][j+4]= colors.darkbrown[1];
            rayarray[i][j+5] = colors.darkbrown[2];
            
        }

        
        rayarray[i][j+6] = rayarray[i][j]; 
        rayarray[i][j+7] = lineh+lineo;
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

void RayRenderer::DrawObject()
{
    for(int i = 0; i<raynum; i++){
  this->shader.use();
  this->shader.setMatrix4("projection", this->projection);
    glBindVertexArray(this->quadVAO[i]);
    glLineWidth(30);
    // for(int i = 0; i< 2;i++){
    // glDrawArrays(GL_LINES,(i),((i+2)));
    // }
    glDrawArrays(GL_LINES,0,2);
    // glDrawArrays(GL_LINES,2,2);
    glBindVertexArray(0);
    }
    }

