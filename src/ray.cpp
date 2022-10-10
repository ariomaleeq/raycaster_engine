#include "ray.h"

Ray::Ray(std::array<float,3> &playerstate, Map &map){
this->playerstate[0] = playerstate[0];
this->playerstate[1] = playerstate[1];
this->playerstate[2] = playerstate[2];
this->mapx = 2;
this->mapy = 1;

calculateRayDistances(map);

}

void Ray::renderRay(std::array<float, 3> &state){
    
    Shader rayshader("..src/shaders/ray.vs", "..src/shaders/ray.fs");
    RayRenderer rayrenderer(rayshader); //renderer of the ray
    rayrenderer.initRenderData(state);
    rayrenderer.DrawObject();//

}
/* float Ray::closestMapBlockMultiple(float n, float x){ */
    /* if(x>n) */
    /*    return x; */
   /*  */
    /* n = n + x/2; */
    /* n = n - (fmod(n,x)); */
    /* return n; */
/* } */
void Ray::updateRayState(std::array<float,3> &playerstate, Map &map){
    this->playerstate[0] = playerstate[0];
    this->playerstate[1] = playerstate[1];
    this->playerstate[2] = playerstate[2];
    calculateRayDistances(map);
}
void Ray::calculateRayDistances(Map &map){
    float rayoffset= 0;
    float atan = -1/tan((this->playerstate[2]/360)*2*M_PI);
    float ntan = -tan((this->playerstate[2]/360)*2*M_PI);
        
    //find offset from current position to the nearest multiple of
    //0,03125 and in the end add the offset in the map display +0.00125
    float mapoffset = 0.03125;
        //for checking horizontal line
    float yoffset = fmod(-1*(this->playerstate[1]),mapoffset);
     float hraydistancex = this->playerstate[0]+yoffset*(atan);
    float hraydistancey = this->playerstate[1]+yoffset;
   
   //for checking vertical line 
    float xoffset = fmod(this->playerstate[0],mapoffset);
   float vraydistancey = this->playerstate[1]-xoffset*(ntan);
   float vraydistancex = this->playerstate[0]+xoffset;
    
    //player position in the map
   this->mapx = (int)(this->playerstate[0]/mapoffset);
    this->mapy = (int)(this->playerstate[1]/mapoffset);
    int hcheckx = this->mapx;
    int hchecky = this->mapy;
    int vcheckx = this->mapx;
    int vchecky = this->mapy;
    //horizontal grid check
    int dof = 16; //depth of field of the player

    int increment = 0;
//horizontal line check
    while(increment<16){
    
    hraydistancey = hraydistancey+0.03125;
    hraydistancex = hraydistancex+0.03125*(atan);
   hcheckx = hcheckx+1;     
    hchecky= hchecky+1;
    if(map.map[hcheckx+(hchecky*16)]==1){
        break;

    }
    increment++;
    }
    increment = 0;
    //vertical line check
    while(increment <16){
        
    vraydistancex = vraydistancex-0.03125;
    vraydistancey = vraydistancey-0.03125*(ntan);
    vcheckx = vcheckx+1;
    vchecky = vchecky+1;
    }


}
