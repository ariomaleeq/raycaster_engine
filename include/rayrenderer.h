#ifndef RAYRENDERER_H
#define RAYRENDERER_H

#include "renderer.h"
#include "colorsettings.h"
#include "shader.h"
#define raynum 320
class RayRenderer : public Renderer {
    public:
        using Renderer::Renderer;
        void initRenderData() override;
        void initRenderData(std::array<float,raynum> &distance, std::array<int, raynum> &color, std::array<float, 3> &state);
        void DrawObject() override;
        unsigned int quadVAO[raynum];
        unsigned int quadVBO[raynum];
};
#endif
