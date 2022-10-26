#ifndef RAYRENDERER_H
#define RAYRENDERER_H

#include "renderer.h"
#include "colorsettings.h"
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 
#define raynum 320 
class RayRenderer : public Renderer {
    public:
        using Renderer::Renderer;
        void initRenderData() override;
        void initRenderData(std::array<float,raynum> &distance, std::array<int, raynum> &color, std::array<float, 3> &state);
        void DrawObject() override;
        void DrawObject(std::array<float, raynum> &distance, std::array<int, raynum> &color, std::array<float, 3> &state);
        unsigned int quadVAO[raynum];
        unsigned int quadVBO[raynum];
        glm::mat4 projection = glm::ortho(0.0f,1600.0f,800.0f,0.0f,-1.0f,1.0f);

};
#endif
