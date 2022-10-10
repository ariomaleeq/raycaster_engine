#include "renderer.h"

class PlayerRenderer : public Renderer {
public:
    using Renderer::Renderer;
    void initRenderData() override;
    void initRenderData(std::array<float, 3> &state);
    void DrawObject() override;
};
