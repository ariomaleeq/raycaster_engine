#include <iostream>
#include "entity.h"

Entity::Entity() {

    this->state[0] =(0.0); // x
    this->state[1] = (0.0); // y
    this->state[2] = (0.0); // angle: theta from x axis
}


void Entity::moveEntityUp() {
    // move the entity up naively
    this->state[1] = (this->state[1]) + 0.001;
    //move entity vectorially
    // if(this->state[2] <=90){
    // this->state[0] = (this->state[0]) + 0.001 * cos(this->state[2]);
    // this->state[1] = (this->state[1]) + 0.001 * sin(this->state[2]);
    // }
    // else if(this->state[2] <360 && this->state[2] > 180){
    // this->state[0] = (this->state[0]) + 0.001 * cos(this->state[2]);
    // this->state[1] = (this->state[1]) + 0.001 * sin(this->state[2]);
    //print entity state
    this->printEntityState();

}
void Entity::moveEntityDown(){
    //move entity down naively
    this->state[1] = (this->state[1]) - 0.001;
    //move entity vectorially
    // this->state[0] = (this->state[0]) - 0.001 * cos(this->state[2]);
    // this->state[1] = (this->state[1]) - 0.001 * sin(this->state[2]);
    this->printEntityState();

}
void Entity::moveEntityRight(){
    //move entity right naively
    this->state[0] = (this->state[0]) + 0.001;
    //move entity vectorially
    // this->state[0] = (this->state[0]) + 0.001 * sin(this->state[2]);
    // this->state[1] = (this->state[1]) - 0.001 * cos(this->state[2]);
    this->printEntityState();
}

void Entity::moveEntityLeft(){
    //move entity left naively
    this->state[0] = (this->state[0]) - 0.001;
    //move entity vectorially
    // this->state[0] = (this->state[0]) - 0.001 * sin(this->state[2]);
    // this->state[1] = (this->state[1]) + 0.001 * cos(this->state[2]);
    this->printEntityState();
}

void Entity::rotateEntityClockwise(){
    this->state[2] = (this->state[2]) - 7.5;

    this->printEntityState();
    if(state[2] ==-360){
        state[2] = 0;
    }
}
void Entity::rotateEntityCounterClockwise(){
    this->state[2] = (this->state[2]) + 7.5;
    this->printEntityState();
    if(state[2]==360){
        state[2] = 0;
    }
}
void Entity::printEntityState(){
    std::cout << "Entity: "<< this->name << " x: " << this->state[0] << " y: " << this->state[1] << " theta: " << this->state[2] << std::endl;
}
void Entity::renderEntity(){
 Shader playershader("../src/shaders/map.vs", "../src/shaders/map.frag");
    PlayerRenderer playerrenderer(playershader);
    playerrenderer.initRenderData(this->state);
    playerrenderer.DrawObject();
}



