#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <array>
#include "entity.h"


class Player: public Entity{

    public:

        Player(); //unique constructor to the player object 
               //moves the player up
        void updateEntityState() override; //updates the player state and texture
};

#endif
