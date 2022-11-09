#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <array>
#include "playerrenderer.h"
#include <math.h>
#include "map.h"
//Abstract implementation of all entities in the game: player, enemies, etc.

class Entity{

    public:
    enum entityState{
        IDLE=0,
        SHOOTING,
        RECOIL,
        WALKING
    };
 int spritestate;
        Entity();
        virtual void moveEntityUp();
        virtual void moveEntityDown();
        virtual void moveEntityRight();
        virtual void moveEntityLeft();
        virtual void rotateEntityClockwise();
        virtual void rotateEntityCounterClockwise();
        virtual void printEntityState();
        virtual void renderEntity();
        virtual void updateEntityState();
        virtual void updateEntityState(int &state);
        virtual float getx();
        virtual float gety();
        virtual float getrot();

        friend class Game;
    protected:
        std::array<float,3> state;//entity state: x,y,theta
        std::string name; //entity name in the game
        int width; //width in pixels
        int length;//length in pixels
        Map map;
        PlayerRenderer playerrenderer;//
};
#endif 
