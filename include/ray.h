#include <math.h>
#include "rayrenderer.h"
#include <array>
#include <vector>
#include "map.h"
#define raynum 160 //ray number is set as a constant value
class Ray{
    public:
        std::array<float,3> playerstate; //copied state of the player: x,y,z,angle 
        std::array<float,3> raystate;   //state of the ray: x,y,z,angle, distance to wall
        std::array<std::array<float,3>,raynum> rayArray;                           //
        Ray(std::array<float,3> &playerstate, Map &map);
        void calculateRayDistances(Map &map);
        void updateRayState(std::array<float,3> &playerstate, Map &map);
        // float closestMapBlockMultiple(float n, float x);
        ~Ray();
        void renderRay(std::array<float, 3> &state);
        int mapx;            //
        int mapy; 
        




};
