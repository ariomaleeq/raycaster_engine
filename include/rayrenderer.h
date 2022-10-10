#include "renderer.h"

class RayRenderer : public Renderer {
    public:
        using Renderer::Renderer;
        ~RayRenderer();
        void initRenderData(std::array<float, 3> &state);
        void DrawObject() override;
};
