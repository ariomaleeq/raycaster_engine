#include "game.h"

Game::Game(unsigned int width, unsigned int height)
    : Width(width), Height(height), State(GAME_ACTIVE) 
{

    //ctor
}

void Game::Init(){
//initialize the game
}

void Game::ProcessInput(float dt){
this->playerentity = &player;
}

void Game::Update(float dt){

}

void Game::Render(){
//will render the player and the map using the methods from the respective
//classes

}
Entity* Game::playerreference(){
Entity* playerentity = &player;
return playerentity;
}

