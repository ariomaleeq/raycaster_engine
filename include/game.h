#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "map.h"
#include "player.h"
#include "ray.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // game state
    GameState               State;
    unsigned int            Width, Height;
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    //~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    Entity* playerReference();//pass a pointer of the player to the main function
    Map* mapReference();      //pass a pointer of the map to the main function

private:
    Player player;
    Map map;
    Ray ray;
    };

#endif
