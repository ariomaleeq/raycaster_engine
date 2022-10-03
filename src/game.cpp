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

}

