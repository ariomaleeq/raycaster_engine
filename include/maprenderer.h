#include "renderer.h"
class MapRenderer: public Renderer{
public:
   
  using Renderer::Renderer;

//right now the map size has to be hard coded unfortuantely
    void initRenderData() override;
    void initRenderData(std::array<int, 128> &map);
    void DrawObject() override;
   };



