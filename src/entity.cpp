#include <iostream>
#include "entity.h"

Entity::Entity() {

    this->state[0] =(0.0); // x
    this->state[1] = (0.0); // y
    this->state[2] = (0.0); // angle: theta from x axis
}

void Entity::updateEntityState(){

}
void Entity::moveEntityUp() {
    float nextstatex;
    float nextstatey;
    int mapx;
    int mapy;
    nextstatex = this->state[0] + 5*cos(this->state[2]*M_PI/180);
    nextstatey = this->state[1] + 5*sin(this->state[2]*M_PI/180);
    mapx = (int)nextstatex/25;
    mapy = (int)nextstatey/25;
    if(map.map[mapx+(mapy*16)] ==0) {
    this->state[0] = (this->state[0]) +1* cos(this->state[2] * M_PI / 180);
    this->state[1] = (this->state[1]) +1* sin(this->state[2] * M_PI/180);
    } 
   
    this->printEntityState();

}
void Entity::moveEntityDown(){
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
        this->state[0] = (this->state[0]) -1* cos(this->state[2] * M_PI / 180);
        this->state[1] = (this->state[1]) -1* sin(this->state[2] * M_PI/180);
    }
    this->printEntityState();

}
void Entity::moveEntityRight(){
   //move entity vectorially
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
    glm::vec2 position = glm::vec2(600.0f, 400.0f);
    glm::vec2 size = glm::vec2(400.0f, 400.0f);
    glm::vec3 color = glm::vec3(1.0f);
    Renderer* spriterenderer = &this->playerrenderer;
    spriterenderer ->drawSprite(position, size, 0, color);
    
}
void Entity::updateEntityState(int &state){

    if(state == 0){
        this->spritestate = IDLE;
    }
    if(state == 1){
        this->spritestate = SHOOTING;
    }
    if(state == 2){
        this->spritestate = RECOIL;
    }
    // move the player
}

float Entity::getx(){
    return this->state[0];
}
float Entity::gety(){
    return this->state[1];
}
float Entity::getrot(){
    return this->state[2];
}


