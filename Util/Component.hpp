#pragma once

#include <iostream>
#include <glad.h>

namespace ECS {
// An enum used to identify the components type, note that since Component_Type inherits unsigned char there can only be 256 components (More than enough).
enum Component_Type : unsigned char {
    RENDERER
};

// This is just an abstract struct to take advantage of polymorphism.
struct Component {
    // Abstract things do be happening here.
    Component() = default;
};


class RenderComponent : public Component {
    const static Component_Type componentType = RENDERER;

    void bindToBuffer();

    public:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO = -1; // This is optional represented by the -1 default value.
    unsigned int EBOSize;
    
    RenderComponent();
    RenderComponent(unsigned int VAO, unsigned int VBO);
    RenderComponent(unsigned int VAO, unsigned int VBO, unsigned int EBO);

    void draw();
};
}