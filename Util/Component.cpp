#include <Component.hpp>

using namespace ECS;

void RenderComponent::bindToBuffer() {
    glBindVertexArray(VAO);
}

RenderComponent::RenderComponent() {
    VAO = 0;
    VBO = 0;
}

RenderComponent::RenderComponent(unsigned int VAO, unsigned int VBO) {
    VAO = VAO;
    VBO = VBO;
}

RenderComponent::RenderComponent(unsigned int VAO, unsigned int VBO, unsigned int EBO) {
    VAO = VAO;
    VBO = VBO;
    EBO = EBO;
}

void RenderComponent::draw() {
    bindToBuffer();
    if(EBO == -1) {
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    else {
        glDrawElements(GL_TRIANGLES, EBOSize, GL_UNSIGNED_INT, 0);
    }
}