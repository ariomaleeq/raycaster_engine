#ifndef RAYRENDERER_H
#define RAYRENDERER_H

#include "renderer.h"
#include "colorsettings.h"
#include "shader.h"
#define raynum 160
class RayRenderer : public Renderer {
    public:
        using Renderer::Renderer;
        void initRenderData() override;
        void initRenderData(std::array<float,raynum> &distance, std::array<int, raynum> &color);
        void DrawObject() override;
        unsigned int quadVAO[raynum];
        unsigned int quadVBO[raynum];
};
#endif
