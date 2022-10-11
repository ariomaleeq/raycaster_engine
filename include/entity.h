#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <array>
#include "playerrenderer.h"
//Abstract implementation of all entities in the game: player, enemies, etc.

class Entity{

    public:
        Entity();
        virtual void moveEntityUp();
        virtual void moveEntityDown();
        virtual void moveEntityRight();
        virtual void moveEntityLeft();
        virtual void rotateEntityClockwise();
        virtual void rotateEntityCounterClockwise();
        virtual void printEntityState();
        virtual void renderEntity();
        friend class Game;
    protected:
        std::array<float,3> state;//entity state: x,y,theta
        std::string name; //entity name in the game
        int width; //width in pixels
        int length;//length in pixels
};
#endif 
