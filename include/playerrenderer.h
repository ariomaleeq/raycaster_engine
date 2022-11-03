#include "renderer.h"

class PlayerRenderer : public Renderer {
public:
    using Renderer::Renderer;
    void initRenderData() override;
    void initRenderData(std::array<float, 3> &state);
    void DrawObject() override;
    
    glm::mat4 projection = glm::ortho(0.0f,1600.0f,800.0f,0.0f,-1.0f,1.0f);
    glm::vec2 size = glm::vec2(50.0f, 50.0f);
};
