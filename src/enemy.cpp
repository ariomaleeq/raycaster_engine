#include "enemy.h"

Enemy::Enemy()
{ //initialize enemy object
    this->state[0] = 315.0;
    this->state[1] = 110.0;
    this->state[2] = 180.0;
    this->width = 128;
    this->length= 256;
    this->name = "Radioactive Suit Guy";
    Shader spriteshader("../src/shaders/sprite.vs", "../src/shaders/sprite.frag");
    this->spriterenderer =new Renderer(spriteshader, spriteshader);
 this->spriterenderer->loadTexture("../images/enemy-idle.png", true);
    this->spriterenderer->initSpriteData();
   

 
    this->spritestate = IDLE;
}

void Enemy::updateEntityState(float position_x, float position_y, float rotation_theta, Ray &ray){
if(this->spritestate==IDLE){
    }
this->rotation = rotation_theta-this->state[2];
float player_frame_x = position_x-this->state[0];
float player_frame_y = position_y-this->state[1];

float cos_angle = cos(this->rotation*M_PI/180.0);
float sin_angle = sin(this->rotation*M_PI/180.0);

this->x = player_frame_y*cos_angle + player_frame_x*sin_angle;
this->y = player_frame_x*cos_angle - player_frame_y*sin_angle;

this->translation = glm::vec2((this->x*108/this->y)+(1600.0/2) , (this->length*108/this->y)+(800.0/2));
this->scale = glm::vec2((128*80/this->y),(128*80/this->y)); 
this->ray = &ray;
std::cout<<"the x value is:"<<this->translation.x<<std::endl;
std::cout<<"the y value is:"<<this->translation.y<<std::endl;
std::cout<<"the x scale is:"<<this->scale.x<<std::endl;
std::cout<<"the y scale is:"<<this->scale.y<<std::endl;
}
void Enemy::renderEntity(){
    // if(this->translation.x >0 && this->translation.x < 1600 ){
    this->spriterenderer->drawSprite(this->translation, this->scale,0.0, glm::vec3(1.0));  
    // }
    }
