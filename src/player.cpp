#include <vector>
#include "player.h"



Player::Player() {
    this->state[0] = 25.0; // x
    this->state[1] = 25.0; // y
    this->state[2] = 0.0; // angle: theta from x axis
    this->name = "Player";
    this->width = 5;
    this->length = 5;
    Renderer* spriterenderer = &this->playerrenderer;
    Shader spriteshader("../src/shaders/sprite.vs", "../src/shaders/sprite.frag");
    spriterenderer->loadTexture("images/revolver-idle.png", true, spriteshader);
    spriterenderer->initSpriteData();
    spriterenderer->initRenderData();
std::cout << "Entity: "<< this->name <<"created" << std::endl;
}

    // move the player

