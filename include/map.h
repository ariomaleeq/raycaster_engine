#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <array>


class Map {

    public:
        Map();
        void getMap(); //copies the map to an array
        void setMap();// function to set the map from a file
        friend class Entity; //allows entities to get access to the map in the game

    private:

        std::array<int,100> map; // map of the game
};

#endif
