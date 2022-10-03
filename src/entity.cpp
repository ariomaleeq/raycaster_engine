#include <iostream>
#include "entity.h"

Entity::Entity() {

    this->state[0] =(0.0); // x
    this->state[1] = (0.0); // y
    this->state[2] = (90.0); // angle: theta from x axis
}


void Entity::moveEntityUp() {
    // move the entity up
    this->state[1] = (this->state[1]) + 0.5;

}
void Entity::moveEntityDown(){
    this->state[1] = (this->state[1]) - 0.5;

}
void Entity::moveEntityRight(){
    this->state[0] = (this->state[0]) + 0.5;

}

void Entity::moveEntityLeft(){
    this->state[0] = (this->state[0]) - 0.5;

}

void Entity::rotateEntityClockwise(){
    this->state[2] = (this->state[2]) - 0.5;

}
void Entity::rotateEntityCounterClockwise(){
    this->state[2] = (this->state[2]) + 0.5;

}



