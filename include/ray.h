#include <math.h>
#include "rayrenderer.h"
#include <array>
#include <vector>
#include "map.h"
#define raynum 160 //ray number is set as a constant value
class Ray{
    public:
        std::array<float,3> playerstate; //copied state of the player: x,y,z,angle 
        std::array<float,raynum> raydistance;
        std::array<int, raynum> colorarray;//
        Ray();
        void calculateRayDistances(Map &map);
        void updateRayState(std::array<float,3> &playerstate, Map &map);
        // float closestMapBlockMultiple(float n, float x);
        void renderRay();
        int mapx;            //
        int mapy; 
        




};
