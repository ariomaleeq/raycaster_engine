#include "ray.h"

Ray::Ray(){
this->mapx = 2;
this->mapy = 1;

}

void Ray::renderRay(){

    Shader rayshader("../src/shaders/ray.vs", "../src/shaders/ray.frag");
    RayRenderer rayrenderer(rayshader); //renderer of the ray
    rayrenderer.initRenderData(this->raydistance, this->colorarray, this->playerstate);
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
    float rayoffset= 80;

        for (int i=0; i<raynum;i++ ){
    float atan = -1/tan(((this->playerstate[2]+rayoffset)/360)*2*M_PI);
    float ntan = -tan(((this->playerstate[2]+rayoffset)/360)*2*M_PI);

    float vraydistancey;
    float vraydistancex;
    float hraydistancex;
    float hraydistancey;


       //find offset from current position to the nearest multiple of
    //0,03125 and in the end add the offset in the map display +0.00125
    float mapoffset = 25;
    this->mapx = (int)(this->playerstate[0]/mapoffset);
    this->mapy = (int)(this->playerstate[1]/mapoffset);
    int hcheckx = this->mapx;
    int hchecky = this->mapy;
    int vcheckx = this->mapx;
    int vchecky = this->mapy;

   //for checking horizontal line
    if(playerstate[2]+rayoffset>270){
    float yoffset = fmod(-1*(this->playerstate[1]),mapoffset);
    hraydistancex = this->playerstate[0]+yoffset*(atan);
    hraydistancey = this->playerstate[1]+yoffset;
    int increment = 0;
   while(increment<16){

    hraydistancey = hraydistancey+mapoffset;
    hraydistancex = hraydistancex+mapoffset*(atan);
   hcheckx = hcheckx+1;
    hchecky= hchecky+1;
    if(map.map[hcheckx+(hchecky*16)]==1){
        break;

    }
    increment++;
    }

    }
    else if(playerstate[2]+rayoffset<90){
    float yoffset = fmod(-1*this->playerstate[1],mapoffset);
    hraydistancex = this->playerstate[0]+yoffset*(atan);
    hraydistancey = this->playerstate[1]+mapoffset+yoffset;
    int increment = 0;
   while(increment<16){

    hraydistancey = hraydistancey+mapoffset;
    hraydistancex = hraydistancex+mapoffset*(atan);
   hcheckx = hcheckx+1;
    hchecky= hchecky-1;
    if(map.map[hcheckx+(hchecky*16)]==1){
        break;

    }
    increment++;

    }
    }
    else if(playerstate[2]+rayoffset>90 && playerstate[2]+rayoffset<180){
        mapoffset = -1*mapoffset;
    float yoffset = fmod(-1*this->playerstate[1],mapoffset);
    hraydistancex = this->playerstate[0]+mapoffset-yoffset*(atan);
    hraydistancey = this->playerstate[1]+yoffset;
    int increment = 0;
while(increment<16){

    hraydistancey = hraydistancey+mapoffset;
    hraydistancex = hraydistancex+mapoffset*(atan);
   hcheckx = hcheckx-1;
    hchecky= hchecky-1;
    if(map.map[hcheckx+(hchecky*16)]==1){
        break;

    }
    increment++;

    }

   }
    else if(playerstate[2]+rayoffset>180 && playerstate[2]+rayoffset<270){
        mapoffset = -1*mapoffset;
    float yoffset = fmod(-1*this->playerstate[1],mapoffset);
    hraydistancex = this->playerstate[0]+mapoffset+yoffset*(atan);
    hraydistancey = this->playerstate[1]+yoffset;
    int increment = 0;
while(increment<16){

    hraydistancey = hraydistancey-mapoffset;
    hraydistancex = hraydistancex-mapoffset*(atan);
   hcheckx = hcheckx-1;
    hchecky= hchecky-1;
    if(map.map[hcheckx+(hchecky*16)]==1){
        break;

    }
    increment++;

}
    }



    //for checking vertical line
   if(playerstate[2]+rayoffset>270 ){

    float xoffset = fmod(this->playerstate[0],mapoffset);
  vraydistancey = this->playerstate[1]-xoffset*(ntan);
   vraydistancex = this->playerstate[0]+xoffset;
 int increment = 0;
    while(increment <16){

    vraydistancex = vraydistancex+mapoffset;
    vraydistancey = vraydistancey+mapoffset*(ntan);
    vcheckx = vcheckx+1;
    vchecky = vchecky+1;
     if(map.map[vcheckx+(vchecky*16)]==1){
        break;

    }
    increment++;

    }

   }
   else if(playerstate[2]<90+rayoffset){
    float xoffset = fmod(this->playerstate[1],mapoffset);
    vraydistancey = this->playerstate[1]+mapoffset+xoffset*(ntan);
    vraydistancex = this->playerstate[0]+xoffset;
 int increment = 0;
    while(increment <16){

    vraydistancex = vraydistancex+mapoffset;
    vraydistancey = vraydistancey+mapoffset*(ntan);
    vcheckx = vcheckx+1;
    vchecky = vchecky-1;
     if(map.map[vcheckx+(vchecky*16)]==1){
        break;

    }
    increment++;

    }

   }
   else if(playerstate[2]+rayoffset>90 && playerstate[2]+rayoffset<180){
       mapoffset = -1*mapoffset;
       float xoffset = fmod(this->playerstate[1]+mapoffset,mapoffset);
       vraydistancey = this->playerstate[1]+mapoffset-xoffset*(ntan);
         vraydistancex = this->playerstate[0]+xoffset;
         int dof = 16; //depth of field of the player

    int increment = 0;
    while(increment <16){

    vraydistancex = vraydistancex+mapoffset;
    vraydistancey = vraydistancey+mapoffset*(ntan);
    vcheckx = vcheckx-1;
    vchecky = vchecky-1;
     if(map.map[vcheckx+(vchecky*16)]==1){
        break;

    }
    increment++;

    }

   }
   else if(playerstate[2]+rayoffset<270 && playerstate[2]+rayoffset>180){
       mapoffset=-1*mapoffset;
       float xoffset = fmod(this->playerstate[1],mapoffset);
        vraydistancey = this->playerstate[1]-xoffset*(ntan);
     vraydistancex = this->playerstate[0]+mapoffset+xoffset;
    //player positiodist function in c++dist function in c++n in the map

    //horizontal grid check
    int dof = 16; //depth of field of the player

    int increment = 0;
    while(increment <16){

    vraydistancex = vraydistancex+mapoffset;
    vraydistancey = vraydistancey+mapoffset*(ntan);
    vcheckx = vcheckx-1;
    vchecky = vchecky+1;
     if(map.map[vcheckx+(vchecky*16)]==1){
        break;

    }
    increment++;

    }
   }

//horizontal line checkdist functiondist function in c++ in c++
    //vertical line check
    rayoffset = rayoffset-0.5;
    //calculate the distance of the ray
    //horizontal line check distance
    float hraydistance = sqrt(pow((hraydistancex-this->playerstate[0]),2)+pow((hraydistancey-this->playerstate[1]),2));
    //vertical line check distance
    float vraydistance = sqrt(pow((vraydistancex-this->playerstate[0]),2)+pow((vraydistancey-this->playerstate[1]),2));
    //find the closest ray distance
    if(hraydistance<vraydistance){
        this->raydistance[i] = hraydistance;
        this->colorarray[i] = 1;

    }
    else{
        this->raydistance[i] = vraydistance;
        this->colorarray[i] = 0;
    }
}
}
