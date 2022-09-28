#include <iostream>
#include <vector>
#include "player.h"

Player::Player() {
    this->state[0] = 0;
    this->state[1] = 0;
    this->state[2] = 0;
    this->state[3] = 0;
}

void Player::getPlayerState() {
    std::cout<<this->state;
}

void Player::movePlayer() {
    // move the player
}
