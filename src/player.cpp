#include <vector>
#include "player.h"



Player::Player() {
    this->state[0] = 0.0; // x
    this->state[1] = 0.0; // y
    this->state[2] = 0.0; // angle: theta from x axis
    this->name = "Player";
    this->width = 5;
    this->length = 5;
                         //
std::cout << "Entity: "<< this->name <<"created" << std::endl;
}

    // move the player

