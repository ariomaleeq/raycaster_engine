#include <iostream>
#include <vector>
#include "map.h"
Map::Map(){
    //right now map is hard coded but will be changed to read from a file

this->map =
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};
}

void Map::renderMap(){
    //renders the map based on the location of the player
    //this->maprenderer.renderMap(this->map, this->xoffset, this->yoffset);
    Shader mapshader("../src/shaders/map.vs", "../src/shaders/map.frag");
    MapRenderer maprenderer(mapshader);

    // maprenderer.initRenderData(this->map);
    // maprenderer.DrawObject();

}


