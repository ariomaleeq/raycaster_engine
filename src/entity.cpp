#include <iostream>
#include "entity.h"

Entity::Entity() {

    this->state[0] =(0.0); // x
    this->state[1] = (0.0); // y
    this->state[2] = (0.0); // angle: theta from x axis
}


void Entity::moveEntityUp() {
    // move the entity up naively
    // this->state[1] = (this->state[1]) - 1;
    //move entity vectorially
    // if(this->state[2] <=90){
    float nextstatex;
    float nextstatey;
    int mapx;
    int mapy;
    nextstatex = this->state[0] + 5*cos(this->state[2]*M_PI/180);
    nextstatey = this->state[1] + 5*sin(this->state[2]*M_PI/180);
    mapx = (int)nextstatex/25;
    mapy = (int)nextstatey/25;
    if(map.map[mapx+(mapy*16)] ==0) {
    this->state[0] = (this->state[0]) +0.75* cos(this->state[2] * M_PI / 180);
    this->state[1] = (this->state[1]) +0.75* sin(this->state[2] * M_PI/180);
    } 
    /*   } */
    /* else if(this->state[2] <360 && this->state[2] > 180){ */
    /* this->state[0] = (this->state[0]) + 0.001 * cos(this->state[2]); */
    /* this->state[1] = (this->state[1]) + 0.001 * sin(this->state[2]); */
    //print entity state
    this->printEntityState();

}
void Entity::moveEntityDown(){
    //move entity down naively
    // this->state[1] = (this->state[1]) + 1;
    //move entity vectorially
    float nextstatex;
    float nextstatey;
    int mapx;
    int mapy;
    nextstatex = this->state[0] - 5*cos(this->state[2]*M_PI/180);
    nextstatey = this->state[1] - 5*sin(this->state[2]*M_PI/180);
    mapx = (int)nextstatex/25;
    mapy = (int)nextstatey/25;
    if(map.map[mapx+(mapy*16)] ==0) {
    this->state[0] = (this->state[0]) -0.75* cos(this->state[2] * M_PI / 180);
    this->state[1] = (this->state[1]) -0.75* sin(this->state[2] * M_PI/180);
    }
  /*   } */

    // this->state[0] = (this->state[0]) - 0.001 * cos(this->state[2]);
    // this->state[1] = (this->state[1]) - 0.001 * sin(this->state[2]);
    this->printEntityState();

}
void Entity::moveEntityRight(){
    //move entity right naively
    // this->state[0] = (this->state[0]) +1;
    //move entity vectorially
    // this->state[0] = (this->state[0]) + 0.001 * sin(this->state[2]);
    // this->state[1] = (this->state[1]) - 0.001 * cos(this->state[2]);
    float nextstatex;
    float nextstatey;
    int mapx;
    int mapy;
    nextstatey = this->state[1] + 5*cos(this->state[2]*M_PI/180);
    nextstatex = this->state[0] - 5*sin(this->state[2]*M_PI/180);
    mapx = (int)nextstatex/25;
    mapy = (int)nextstatey/25;
    if(map.map[mapx+(mapy*16)] ==0) {

    this->state[1] = (this->state[1]) +0.75* cos(this->state[2] * M_PI / 180);
    this->state[0] = (this->state[0]) -0.75* sin(this->state[2] * M_PI/180);
    }
    this->printEntityState();
}

void Entity::moveEntityLeft(){
    //move entity left naively
    // this->state[0] = (this->state[0]) -1;
    //move entity vectorially
    // this->state[0] = (this->state[0]) - 0.001 * sin(this->state[2]);
    // this->state[1] = (this->state[1]) + 0.001 * cos(this->state[2]);
    float nextstatex;
    float nextstatey;
    int mapx;
    int mapy;
    nextstatey = this->state[1] - 5*cos(this->state[2]*M_PI/180);
    nextstatex = this->state[0] + 5*sin(this->state[2]*M_PI/180);
    mapx = (int)nextstatex/25;
    mapy = (int)nextstatey/25;
    if(map.map[mapx+(mapy*16)] ==0) {

    this->state[1] = (this->state[1]) -0.75* cos(this->state[2] * M_PI / 180);
    this->state[0] = (this->state[0]) +0.75* sin(this->state[2] * M_PI/180);
    }
    this->printEntityState();
}

void Entity::rotateEntityClockwise(){
    this->state[2] = (this->state[2]) - 5;

    this->printEntityState();
    if(state[2]<0){
        state[2] = 359;
    }
    if(state[2]>359){
        state[2] = 0;
    }

}
void Entity::rotateEntityCounterClockwise(){
    this->state[2] = (this->state[2]) + 5;
    this->printEntityState();
    if(state[2]>359){
        state[2] = 0;
    }
    if(state[2]<0){
        state[2] = 359;
    }
}
void Entity::printEntityState(){
    std::cout << "Entity: "<< this->name << " x: " << this->state[0] << " y: " << this->state[1] << " theta: " << this->state[2] << std::endl;
}
void Entity::renderEntity(){
     
    this->playerrenderer.initRenderData(this->state);
    this->playerrenderer.DrawObject();
    glm::vec2 position = glm::vec2(550.0f, 350.0f);
    glm::vec2 size = glm::vec2(500.0f, 500.0f);
    glm::vec3 color = glm::vec3(1.0f);
    Renderer* spriterenderer = &this->playerrenderer;
    spriterenderer ->drawSprite(position, size, 0, color);
    
}



