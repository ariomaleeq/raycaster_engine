#include "game.h"
#include <memory>
Game::Game(unsigned int width, unsigned int height)
    : Width(width), Height(height), State(GAME_ACTIVE)
{

    //ctor
}

void Game::Init(){
//initialize the game
}

void Game::ProcessInput(float dt){
}

void Game::Update(float dt){
    this->ray.updateRayState(this->player.state, this->map);
    //this will be where the collision detection is called to prevent collisions

}

void Game::Render(){
//will render the player and the map using the methods from the respective
//classes
this->ray.renderRay();
this->map.renderMap();
Entity* player = &(this->player);
player->renderEntity();

}
Entity* Game::playerReference(){
Entity* playerentity = &player;
return playerentity;
}

Map* Game::mapReference(){
    Map* mapref = &map;
    return mapref;
}

