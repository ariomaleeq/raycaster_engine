#include "entity.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "renderer.h"
#include "ray.h"
class Enemy: public Entity{
    public:
        Enemy();
        void updateEntityState(float position_x, float position_y, float rotation_theta, Ray &ray);
        void renderEntity() override;
    private:
        glm::vec2 translation;
        glm::vec2 scale;
        float rotation;
        Renderer* spriterenderer;
        float x;
        float y;
        float z; //the z position of a sprite
        Ray* ray; 

};

