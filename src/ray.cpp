#include "ray.h"

Ray::Ray(){
this->mapx = 2;
this->mapy = 2;

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
    float rayoffset= -40;
    float rayangle = playerstate[2]+rayoffset;
  if (rayangle<0){
        rayangle = 360+rayangle;
    }
    if (rayangle>359){
        rayangle = rayangle - 360;
    }


        for (int i=0; i<raynum;i++ ){
   if (rayangle<0){
        rayangle = 360 + rayangle;
    }
    if (rayangle>359){
        rayangle = rayangle - 360;
    }
    float atan = 1/tan(((rayangle)/360)*2*M_PI);
    float ntan = tan(((rayangle)/360)*2*M_PI);

    float vraydistancey;
    float vraydistancex;
    float hraydistancex;
    float hraydistancey;


       //find offset from current position to the nearest multiple of
    //0,03125 and in the end add the offset in the map display +0.00125
    float mapoffset = 25;
    this->mapx = (int)(this->playerstate[0]/mapoffset);
    std::cout<<"the value of mapx is:"<<this->mapx<<std::endl;
    this->mapy = (int)(this->playerstate[1]/mapoffset);
    std::cout<<"the value of mapy is:"<<this->mapy<<std::endl; 
    int hcheckx; 
    int hchecky;
    int vcheckx ;
    int vchecky ;
    
   //for checking horizontal line
    if(rayangle<180){

    if(rayangle<90){
    float yoffset = mapoffset-fmod((this->playerstate[1]),mapoffset);
        hraydistancey = this->playerstate[1]+yoffset;
        hraydistancex = ((this->playerstate[1]-hraydistancey)*(atan))+this->playerstate[0];
    
    int increment = 0;
   while(increment<16){
  hcheckx = (int)(hraydistancex/mapoffset);
    hchecky= (int)(hraydistancey/mapoffset);
   /*  if(hchecky>0){ */
        /* hcheckx+=1; */
    /* } */
   if(hcheckx <= 0 || hchecky <= 0 || hcheckx>map.map.size() || hchecky>map.map.size()){
        break;
    }
    if(map.map[hcheckx+((hchecky)*16)]==1 && hcheckx<16 && hchecky<(16*8) && hcheckx>=0 && hchecky>=0){
        break;

    }

    hraydistancey = hraydistancey+mapoffset;
    hraydistancex = hraydistancex+mapoffset*(atan);
     increment++;
    }
    }
    else{
        float yoffset = mapoffset-fmod((this->playerstate[1]),mapoffset);
        hraydistancey = this->playerstate[1]+yoffset;
        hraydistancex = this->playerstate[0]-((this->playerstate[1]-hraydistancey)*(atan));
    
        int increment = 0;
        while(increment<16){
        hcheckx = (int)(hraydistancex/mapoffset);
        hchecky= (int)(hraydistancey/mapoffset);
 /* if(hchecky>0){ */
        /* hcheckx+=1; */
    /* } */
        if(hcheckx <= 0 || hchecky <= 0 || hcheckx>map.map.size() || hchecky>map.map.size()){
            break;
        }
        if(map.map[hcheckx+((hchecky)*16)]==1 && hcheckx-1<16 && hchecky-1<(16*8) && hcheckx-1>=0 && hchecky-1>=0){
            break;

        }

    hraydistancey = hraydistancey+mapoffset;
    hraydistancex = hraydistancex+mapoffset*(atan);
     increment++;
    }

    }

    }
    else if(rayangle>180){
        if(rayangle<270){
    float yoffset = mapoffset-fmod(this->playerstate[1],mapoffset);
    hraydistancey = this->playerstate[1]-yoffset-0.001;
    hraydistancex = this->playerstate[0]-((this->playerstate[1]-hraydistancey)*(atan));
    int increment = 0;
   while(increment<16){
 hcheckx = (int)(hraydistancex/mapoffset);
    hchecky= (int)(hraydistancey/mapoffset);
    /*  if(hchecky>0){ */
        /* hcheckx+=1; */
    /* } */
 if(hcheckx<=0 || hchecky<=0 || hcheckx>map.map.size() || hchecky>map.map.size()){
        break;
    }

    if(map.map[hcheckx+((hchecky)*16)]==1 && hcheckx<16 && hchecky<(16*8) && hcheckx>=0 && hchecky>=0){
        break;

    }

    hraydistancey = hraydistancey-mapoffset;
    hraydistancex = hraydistancex-mapoffset*(atan);
      increment++;

    }
        }        
   
    
    
     else{
            float yoffset = mapoffset-fmod(this->playerstate[1],mapoffset);
            hraydistancey = this->playerstate[1]-yoffset-0.001;
            hraydistancex = this->playerstate[0]+((this->playerstate[1]-hraydistancey)*(atan));
            int increment = 0;
            while(increment<16){
            hcheckx = (int)(hraydistancex/mapoffset);
            hchecky= (int)(hraydistancey/mapoffset);
 /* if(hchecky>0){ */
        /* hcheckx+=1; */
    /* } */
                if(hcheckx<=0 || hchecky<=0 || hcheckx>map.map.size() || hchecky>map.map.size()){
                    break;
                }

                if(map.map[hcheckx+((hchecky)*16)]==1 && hcheckx<16 && hchecky<(16*8) && hcheckx>=0 && hchecky>=0){
                    break;

                }

    hraydistancey = hraydistancey-mapoffset;
    hraydistancex = hraydistancex+mapoffset*(atan);
      increment++;


    } 
    
    }
    }
    //for checking vertical line
   if(rayangle<90 || rayangle>270 ){
if(rayangle<90){
    float xoffset = mapoffset-fmod(this->playerstate[0],mapoffset);
  vraydistancex = this->playerstate[0]+xoffset+0.001;

  vraydistancey = this->playerstate[1]+(this->playerstate[0]-vraydistancex)*((ntan));
 
 int increment = 0;
    while(increment <16){
  vcheckx = (int)(vraydistancex/mapoffset);
    vchecky = (int)(vraydistancey/mapoffset);
/*  if(vchecky>0){ */
        /* vcheckx+=1; */
    /* } */
 if(vcheckx <=0 || vchecky <=0 || vcheckx>map.map.size() || vchecky>map.map.size()){
        break;
    }

        if(map.map[vcheckx+((vchecky)*16)]==1 && vcheckx<16 && vchecky<(16*8) && vcheckx>=0 && vchecky>=0){
        break;

    }

    vraydistancex = vraydistancex+mapoffset;
    vraydistancey = vraydistancey-mapoffset*(ntan);
         increment++;

    }
}
else{
  float xoffset = mapoffset-fmod(this->playerstate[0],mapoffset);
vraydistancex = this->playerstate[0]+xoffset+0.001;
  vraydistancey = this->playerstate[1]-(this->playerstate[0]-vraydistancex)*((ntan));
   
 int increment = 0;
    while(increment <16){
  vcheckx = (int)(vraydistancex/mapoffset);
    vchecky = (int)(vraydistancey/mapoffset);
 /* if(vchecky>0){ */
        /* vcheckx+=1; */
    /* } */
    if(vcheckx <=0 || vchecky <=0 || vcheckx>map.map.size() || vchecky>map.map.size()){
        break;
    }

        if(map.map[vcheckx+((vchecky)*16)]==1 && vcheckx<16 && vchecky<(16*8) && vcheckx>=0 && vchecky>=0){
        break;

    }

    vraydistancex = vraydistancex+mapoffset;
    vraydistancey = vraydistancey+mapoffset*(ntan);
         increment++;

    }
}

} 
   else if(rayangle>90 && rayangle<270){
       if(rayangle<180){
    float xoffset = fmod(this->playerstate[0],mapoffset);
 vraydistancex = this->playerstate[0]-xoffset-0.001;
    vraydistancey = this->playerstate[1]+((this->playerstate[0]-vraydistancex)*(ntan));
   
 int increment = 0;
    while(increment <16){
 vcheckx = (int)(vraydistancex/mapoffset);
    vchecky = (int) (vraydistancey/mapoffset); 
 /* if(vchecky>0){ */
        /* vcheckx+=1; */
    /* } */
    if(vcheckx <=0 || vchecky <=0 || vcheckx>map.map.size() || vchecky>map.map.size()){
        break;
    }

if(map.map[vcheckx+((vchecky)*16)]==1 && vcheckx<8 && vchecky<(16*8) && vcheckx>=0 && vchecky>=0){
        break;

    }

    vraydistancex = vraydistancex-mapoffset;
    vraydistancey = vraydistancey-(mapoffset*(ntan));
   
         increment++;

    }

   }
       else{
  float xoffset = fmod(this->playerstate[0],mapoffset);
vraydistancex = this->playerstate[0]-xoffset-0.001;
    vraydistancey = this->playerstate[1]-((this->playerstate[0]-vraydistancex)*(ntan));
    
 int increment = 0;
    while(increment <16){
 vcheckx = (int)(vraydistancex/mapoffset);
    vchecky = (int) (vraydistancey/mapoffset); 
 /* if(vchecky>0){ */
        /* vcheckx+=1; */
    /* } */
    if(vcheckx <=0 || vchecky <=0 || vcheckx>map.map.size() || vchecky>map.map.size()){
        break;
    }

if(map.map[vcheckx+((vchecky)*16)]==1 && vcheckx<8 && vchecky<(16*8) && vcheckx>=0 && vchecky>=0){
        break;

    }

    vraydistancex = vraydistancex-mapoffset;
    vraydistancey = vraydistancey+(mapoffset*(ntan));
   
         increment++;

    }
       }
   }
//horizontal line checkdist functiondist function in c++ in c++
    //vertical line check
    rayangle = rayangle-(rayoffset*2/raynum);
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
