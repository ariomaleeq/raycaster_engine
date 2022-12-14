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
        float edgex = -1.00f;
        float edgey = 1.00f;/* ; */
        float* vertices = new float[map.size()*36];
       /*  float* vertices = new float[36]; */
        /* int i = 0; */
        for(int i = 0; i <128;i++ ){
        //all 0.00125 offset is to leave a line between the tiles
        //first triangle
        vertices[36*i] = edgex+0.00125f; //top left x
        vertices[36*i+1]= edgey-0.00125f; //top left x
        vertices[36*i+2]=0.0f; //top left z
        vertices[36*i+6] = edgex+0.03125f-0.001251f; //top right x
        vertices[36*i+7]= edgey-0.00125f; //top right y
        vertices[36*i+8]=0.0f; //top right z
        vertices[36*i+12] = edgex+0.00125f; //bottom left x
        vertices[36*i+13]= edgey-0.0625f+0.00125f; //bottom left y
        vertices[36*i+14]=0.0f; //bottom left z
        //second triangle
        vertices[36*i+18] = edgex+0.00125f; //bottom left x again
        vertices[36*i+19]= edgey-0.0625+0.00125;//bottom left y again
        vertices[36*i+20]=0.0f; //bottom left z again
        vertices[36*i+24] = edgex+0.03125f-0.00125f; //top right x again
        vertices[36*i+25]= edgey-0.00125f;//top right y again
        vertices[36*i+26] =0.0f;//top right z again
        vertices[36*i+30]= edgex+0.03125f-0.00125f;//bottom right x
        vertices[36*i+31]= edgey-0.0625f+0.00125f;//bottom right y
        vertices[36*i+32]=0.0f;//bottom right z
        if(map[i]==1){
        vertices[36*i+3]=colormap.black[0];
        vertices[36*i+4]=colormap.black[1];
        vertices[36*i+5]=colormap.black[2];
        vertices[36*i+9]=colormap.black[0];
        vertices[36*i+10]=colormap.black[1];
        vertices[36*i+11]=colormap.black[2];
        vertices[36*i+15]=colormap.black[0];
        vertices[36*i+16]=colormap.black[1];
        vertices[36*i+17]=colormap.black[2];
        vertices[36*i+21]=colormap.black[0];
        vertices[36*i+22]=colormap.black[1];
        vertices[36*i+23]=colormap.black[2];
        vertices[36*i+27]=colormap.black[0];
        vertices[36*i+28]=colormap.black[1];
        vertices[36*i+29]=colormap.black[2];
        vertices[36*i+33]=colormap.black[0];
        vertices[36*i+34]=colormap.black[1];
        vertices[36*i+35]=colormap.black[2];
        }
        else if(map[i] == 0) {
        vertices[36*i+3]=colormap.lightgreen[0];
        vertices[36*i+4]=colormap.lightgreen[1];
        vertices[36*i+5]=colormap.lightgreen[2];
        vertices[36*i+9]=colormap.lightgreen[0];
        vertices[36*i+10]=colormap.lightgreen[1];
        vertices[36*i+11]=colormap.lightgreen[2];
        vertices[36*i+15]=colormap.lightgreen[0];
        vertices[36*i+16]=colormap.lightgreen[1];
        vertices[36*i+17]=colormap.lightgreen[2];
        vertices[36*i+21]=colormap.lightgreen[0];
        vertices[36*i+22]=colormap.lightgreen[1];
        vertices[36*i+23]=colormap.lightgreen[2];
        vertices[36*i+27]=colormap.lightgreen[0];
        vertices[36*i+28]=colormap.lightgreen[1];
        vertices[36*i+29]=colormap.lightgreen[2];
        vertices[36*i+33]=colormap.lightgreen[0];
        vertices[36*i+34]=colormap.lightgreen[1];
        vertices[36*i+35]=colormap.lightgreen[2];
        }

        // std::cout<<edgex<<std::endl;
        edgex+=0.03125;
        if((i+1)%16==0 | i==15){
            edgey-=0.0625;//makes sure that the next row is drawn below the previous row
            edgex = -1.00;  //re-sets the x coordinate to the left edge
        }
        }
        //print out vertices
        /*  */
        /* std::cout<<"first entry is:"<<vertices[0]<<"\n"; */
        /* std::cout<<"second entry is:"<<vertices[1]<<"\n"; */
        /* std::cout<<"third entry is:"<<vertices[2]<<"\n"; */
        /* std::cout<<"seventh entry is"<<vertices[6]<<"\n"; */
        /* std::cout<<"eighth entry is"<<vertices[7]<<"\n"; */
        /* std::cout<<"ninth entry is"<<vertices[8]<<"\n"; */
        /* std::cout<<"thirteenth entry is"<<vertices[12]<<"\n"; */
        /* std::cout<<"fourteenth entry is"<<vertices[13]<<"\n"; */
        /* std::cout<<"fifteenth entry is"<<vertices[14]<<"\n"; */
        /* std::cout<<"eighteenth entry is"<<vertices[18]<<"\n"; */
        /* std::cout<<"nineteenth entry is"<<vertices[19]<<"\n"; */
        /* std::cout<<"twentieth entry is"<<vertices[20]<<"\n"; */
        /* std::cout<<"twenty fourth entry is"<<vertices[24]<<"\n"; */
        /* std::cout<<"twenty fifth entry is"<<vertices[25]<<"\n"; */
        /* std::cout<<"twenty sixth entry is"<<vertices[26]<<"\n"; */
        /* std::cout<<"thirtieth entry is"<<vertices[30]<<"\n"; */
        /* std::cout<<"thirty first entry is"<<vertices[31]<<"\n"; */
//test vertices
    /*     float vertices[] = { */
/*     -0.5f, 0.0f, 0.0f, colormap.sand[0], colormap.sand[1], colormap.sand[2], */
/*     -0.05f,0.0,0.0f, colormap.sand[0], colormap.sand[1], colormap.sand[2], */
/*     -0.05f, 0.5f, 0.0f,colormap.sand[0] ,colormap.sand[1] ,colormap.sand[2],  */
/*    -0.5f, 0.0f, 0.0f, colormap.sand[0], colormap.sand[1], colormap.sand[2], */
/*     -0.05f, 0.5f, 0.0f,colormap.sand[0] ,colormap.sand[1] ,colormap.sand[2]  */
/*    , -0.5f, 0.5f, 0.0f, colormap.sand[0], colormap.sand[1], colormap.sand[2] */
/* ,0.5f,0.0f,0.0f, colormap.sand[0], colormap.sand[1], colormap.sand[2], */
/* 0.05f,0.0f,0.0f, colormap.sand[0], colormap.sand[1], colormap.sand[2], */
/* 0.05f,0.5f,0.0f, colormap.sand[0], colormap.sand[1], colormap.sand[2], */
/* }; */
    glGenVertexArrays(1, &this->quadVAO); //THIS GOES FIRST
    glBindVertexArray(this->quadVAO);
        
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*36*map.size(), vertices, GL_STATIC_DRAW);
//have to make sure sizeof(vertices) is correct or else it wont show

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
glEnableVertexAttribArray(1);
        delete[] vertices;
    vertices = NULL;
  glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0); 

}

void MapRenderer::DrawObject(){
    this->shader.use();
    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0,6*128);
      glBindVertexArray(0);
}
