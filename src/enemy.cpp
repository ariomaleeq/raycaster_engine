#include "enemy.h"

Enemy::Enemy()
{ //initialize enemy object
    this->state[0] = 315.0;
    this->state[1] = 110.0;
    this->state[2] = 180.0;
    this->z = -20.0;
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
    float theta_between_points = atan2(position_y - this->state[1], position_x - this->state[0])*180/M_PI;
    this->rotation = rotation_theta-theta_between_points+180;// there is an offset of 180 degrees from the heading to the angle between the player and the enemy
    if(this->rotation>360){
        this->rotation = this->rotation - 360;
    }
    //we need to map the sprite position to the field of view by figuring out where
    //it is in the field of view and normalizing the borders of the field of view
    //and placing the sprite position in that range if it is not in range then it is
    //not visible
    float distance_magnitude = sqrt(pow(position_x - this->state[0], 2) + pow(position_y - this->state[1], 2));
    float adjacent = cos(this->rotation)*distance_magnitude;
    float opposite = (sin(this->rotation)*distance_magnitude); //offset the value with 22.5 so that we can get the ratio later
    float fov_x = tan(22.5*M_PI/180)*adjacent*2; // the maximum span of the x of the field of view

    float fov_y = fov_x/2; // the maximum span of the y of the field of view
    opposite = opposite + fov_y;
    float screen_x= (opposite/fov_x)*1600; // the ratio of the x position of the enemy to the field of view
    float player_frame_x =this->state[0]-position_x;
    float player_frame_y = this->state[1]-position_y;

    float cos_angle = cos(rotation_theta*M_PI/180.0);
    float sin_angle = sin(rotation_theta*M_PI/180.0);
    std::cout<<"The value of theta is:"<<this->rotation<<std::endl;
    /* this->x = player_frame_y*cos_angle + player_frame_x*sin_angle; */
    /* this->y = player_frame_x*cos_angle - player_frame_y*sin_angle; */
    this->translation = glm::vec2(screen_x , (800.0/2));
    this->scale = glm::vec2((this->width*200/this->y),(this->length*200/this->y));
    /* this->ray = &ray; */
    std::cout<<"the x value is:"<<screen_x<<std::endl;
    /* std::cout<<"the y value is:"<<this->y<<std::endl; */
    // std::cout<<"the x scale is:"<<this->scale.x<<std::endl;
    // std::cout<<"the y scale is:"<<this->scale.y<<std::endl;
}
void Enemy::renderEntity(){
    // if(this->translation.x >0 && this->translation.x < 1600 ){
    this->spriterenderer->drawSprite(this->translation, this->scale,0.0, glm::vec3(1.0));  
    // }
    }
