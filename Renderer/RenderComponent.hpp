#pragma once

#include <iostream>
#include <glad/glad.h>
#include <Component.hpp>

using namespace ECS;
namespace renderer {
class RenderComponent : public Component {
    const static Component_Type componentType = RENDERER;

    void bindToBuffer();

    public:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO = -1; // This is optional represented by the -1 default value.
    
    RenderComponent();
    RenderComponent(unsigned int VAO, unsigned int VBO);
    RenderComponent(unsigned int VAO, unsigned int VBO, unsigned int EBO);

    void draw();
};
}