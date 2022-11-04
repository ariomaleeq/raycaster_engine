#include <vector>
#include "player.h"



Player::Player() {
    this->state[0] = 25.0; // x
    this->state[1] = 25.0; // y
    this->state[2] = 0.0; // angle: theta from x axis
    this->name = "Player";
    this->width = 5;
    this->length = 5;
    Shader playershader("../src/shaders/player.vs", "../src/shaders/player.frag");
Shader spriteshader("../src/shaders/sprite.vs", "../src/shaders/sprite.frag");

    this->playerrenderer = PlayerRenderer(playershader, spriteshader);
    Renderer* spriterenderer = &this->playerrenderer;
        spriterenderer->loadTexture("../images/revolver-idle.png", true);
    spriterenderer->initSpriteData();
    spriterenderer->initRenderData();
std::cout << "Entity: "<< this->name <<"created" << std::endl;
this->spritestate = IDLE;
}

void Player::updateEntityState(){
    Renderer* spriterenderer = &this->playerrenderer;
    if(this->spritestate == IDLE){
        spriterenderer->loadTexture("../images/revolver-idle.png", true);
    }
    if(this->spritestate == SHOOTING){
        spriterenderer->loadTexture("../images/revolver-shot.png", true);
    }
    if(this->spritestate == RECOIL){
        spriterenderer->loadTexture("../images/revolver-cock.png", true);
    }

}

