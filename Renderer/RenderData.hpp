#pragma once

#include <iostream>
#include <glad/glad.h>
#include <memory>

namespace renderer {
    // These are container structs for rendering data stored in the render components

    struct RenderData {    
        std::unique_ptr<float[]> vertexData = nullptr;
        unsigned int vSize;
        std::unique_ptr<unsigned int[]> elementBufferData = nullptr;
        unsigned int eSize;
        
        // Gives the vertex data inputted to the class, and gives back a nullptr.
        RenderData(std::unique_ptr<float[]> vData, const unsigned int vDataSize);
        // Gives the vertex and element data inputted to the class, and gives back a nullptr for each one.
        RenderData(std::unique_ptr<float[]> vData, const unsigned int vDataSize, std::unique_ptr<unsigned int[]> eData, const unsigned int eDataSize);

        void generateBuffers(unsigned int *VAO, unsigned int *VBO);
        void generateBuffers(unsigned int *VAO, unsigned int *VBO, unsigned int *EBO, unsigned int *EBOSizeStorer);
        
        protected: // I feel so smart for this
        RenderData() = default;
    };

    // Extra basic classes that utilize render data

    struct Triangle : RenderData {
        Triangle();
    };
    struct Rectangle : RenderData {
        Rectangle();
    };
}