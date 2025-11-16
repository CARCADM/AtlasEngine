#include <RenderComponent.hpp>

using namespace renderer;

RenderComponent::RenderComponent() {
    VAO = 0;
    VBO = 0;
}

RenderComponent::RenderComponent(unsigned int VAO, unsigned int VBO) {
    this->VAO = VAO;
    VBO = VBO;
}

RenderComponent::RenderComponent(unsigned int VAO, unsigned int VBO, unsigned int EBO) {
    this->VAO = VAO;
    this->VBO = VBO;
    this->EBO = EBO;
}