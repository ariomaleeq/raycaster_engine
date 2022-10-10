#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <array>
#include "maprenderer.h"


class Map {

    public:
        Map();
        void getMap(); //copies the map to an array
        void setMap();// function to set the map from a file
        void updateMap();
        void renderMap();// renders the map on the screen
        friend class Entity; //allows entities to get access to the map in the game
        friend class MapRenderer; //allows the map renderer to get access to the map in the game
        friend class Ray; //allows the ray to get access to the map in the game

    private:

        std::array<int,128> map;// map of the game
        int xoffset;            // x o:widthffset of the map
        int yoffset;            // y offset of the map
        int mapwidth;           // width of the map
        int mapheight;          // height of the map
                                 //

};

#endif
