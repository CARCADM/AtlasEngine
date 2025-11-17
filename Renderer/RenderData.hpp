#pragma once

#include <iostream>
#include <glad/glad.h>
#include <memory>

namespace renderer {
    // These are container structs for rendering data stored in the render components

    struct RenderData {
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO = -1;
    
        std::unique_ptr<float[]> vertexData = nullptr;
        std::unique_ptr<unsigned int[]> elementBufferData = nullptr;
        
        // Gives the vertex data inputted to the class, and gives back a nullptr.
        RenderData(std::unique_ptr<float[]> vData);
        // Gives the vertex and element data inputted to the class, and gives back a nullptr for each one.
        RenderData(std::unique_ptr<float[]> vData, std::unique_ptr<unsigned int[]> eData);

        void generateBuffers();
        
        protected: // I feel so smart for this
        RenderData();
    };

    // Extra basic classes that utilize render data

    struct Triangle : RenderData {
        Triangle();
    };
    struct Rectangle : RenderData {
        Rectangle();
    };
}