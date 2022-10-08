#include "maprenderer.h"
#include "shader.h"
void MapRenderer::initRenderData(){

}


void MapRenderer::initRenderData(std::array<int,128> &map){
 unsigned int VBO;
        ColorSettings colormap;
        int columns = map.size()/8;
        // std::cout<<columns<<std::endl;
        int rows = map.size()/16;
        float edgex = -1.0;
        float edgey = 1.0;
        float* vertices = new float[map.size()*24];
        for(int i = 0; i <(map.size());i++ ){
        //all 0.005 offset is to leave a line between the tiles
        //first triangle
        vertices[36*i] = edgex+0.005; //top left x
        vertices[36*i+1]= edgey-0005; //top left x
        vertices[36*i+2]=0.0; //top left z
        vertices[36*i+6] = edgex+0.03125-0.005; //top right x
        vertices[36*i+7]= edgey-0.005; //top right y
        vertices[36*i+8]=0.0; //top right z
        vertices[36*i+12] = edgex+0.005; //bottom left x
        vertices[36*i+13]= edgey-0.03125+0.005; //bottom left y
        vertices[36*i+14]=0.0; //bottom left z
        //second triangle
        vertices[36*i+18] = edgex+0.005; //bottom left x again
        vertices[36*i+19]= edgey-0.03125+0.005;//bottom left y again
        vertices[36*i+20]=0.0; //bottom left z again
        vertices[36*i+24] = edgex+0.03125-0.005; //top right x again
        vertices[36*i+25]= edgey-0.005;//top right y again
        vertices[36*i+26] =0;//top right z again
        vertices[36*i+30]= edgex+0.03125-0.005;//bottom right x
        vertices[36*i+31]= edgey-0.03125+0.005;//bottom right y
        vertices[36*i+32]=0.0;//bottom right z
        if(map[i]==0){
        vertices[36*i+3]=colormap.sand[0];
        vertices[36*i+4]=colormap.sand[1];
        vertices[36*i+5]=colormap.sand[2];
        vertices[36*i+9]=colormap.sand[0];
        vertices[36*i+10]=colormap.sand[1];
        vertices[36*i+11]=colormap.sand[2];
        vertices[36*i+15]=colormap.sand[0];
        vertices[36*i+16]=colormap.sand[1];
        vertices[36*i+17]=colormap.sand[2];
        vertices[36*i+21]=colormap.sand[0];
        vertices[36*i+22]=colormap.sand[1];
        vertices[36*i+23]=colormap.sand[2];
        vertices[36*i+27]=colormap.sand[0];
        vertices[36*i+28]=colormap.sand[1];
        vertices[36*i+29]=colormap.sand[2];
        vertices[36*i+33]=colormap.sand[0];
        vertices[36*i+34]=colormap.sand[1];
        vertices[36*i+35]=colormap.sand[2];
        }
        else if(map[i]==1){
        vertices[36*i+3]=colormap.sand[0];
        vertices[36*i+4]=colormap.sand[1];
        vertices[36*i+5]=colormap.sand[2];
        vertices[36*i+9]=colormap.sand[0];
        vertices[36*i+10]=colormap.sand[1];
        vertices[36*i+11]=colormap.sand[2];
        vertices[36*i+15]=colormap.sand[0];
        vertices[36*i+16]=colormap.sand[1];
        vertices[36*i+17]=colormap.sand[2];
        vertices[36*i+21]=colormap.sand[0];
        vertices[36*i+22]=colormap.sand[1];
        vertices[36*i+23]=colormap.sand[2];
        vertices[36*i+27]=colormap.sand[0];
        vertices[36*i+28]=colormap.sand[1];
        vertices[36*i+29]=colormap.sand[2];
        vertices[36*i+33]=colormap.sand[0];
        vertices[36*i+34]=colormap.sand[1];
        vertices[36*i+35]=colormap.sand[2];
        }
        edgex+=0.03125;
        if(i%16==0){
            edgey-=0.03125;//makes sure that the next row is drawn below the previous row
            edgex = -1.0;  //re-sets the x coordinate to the left edge
        }
        }
        std::cout<<"array is succesfully created"<<std::endl;
        glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
glEnableVertexAttribArray(1);
std::cout<<"vertex sucesfully bound"<<std::endl;
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    std::cout<<"wtf?"<<std::endl;

}

void MapRenderer::DrawObject(){
    this->shader.use();
    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 128*6);
    glBindVertexArray(0);
}
