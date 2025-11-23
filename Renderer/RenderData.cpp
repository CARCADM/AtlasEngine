#include <RenderData.hpp>

using namespace renderer;

RenderData::RenderData(std::unique_ptr<float[]> vData, const unsigned int vDataSize) {
    RenderData::vertexData.swap(vData);
    vSize = vDataSize;
    eSize = -1;
}

RenderData::RenderData(std::unique_ptr<float[]> vData, const unsigned int vDataSize, std::unique_ptr<unsigned int[]> eData, const unsigned int eDataSize) {
    RenderData::vertexData.swap(vData);
    RenderData::elementBufferData.swap(eData);
    vSize = vDataSize;
    eSize = eDataSize;
}

void RenderData::generateBuffers(unsigned int *VAO, unsigned int *VBO) {
    // Create the vertex array and bind it
    glGenVertexArrays(1, VAO);
    glBindVertexArray(*VAO);

    // Generate the vertex buffer object with the necessary vertex data
    glGenBuffers(1, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBufferData(GL_ARRAY_BUFFER, vSize * sizeof(float), vertexData.get(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind the VAO because we're not using it anymore.
    glBindVertexArray(0);
}

void RenderData::generateBuffers(unsigned int *VAO, unsigned int *VBO, unsigned int *EBO, unsigned int *EBOSizeStorer) {
    generateBuffers(VAO, VBO);
    // Rebind the VAO because we are using it again.
    glBindVertexArray(*VAO);

    glGenBuffers(1, EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, eSize * sizeof(unsigned int), elementBufferData.get(), GL_STATIC_DRAW);
    *EBOSizeStorer = eSize;

    glBindVertexArray(0);
}

// SHAPE IMPLEMENTATIONS
Triangle::Triangle() {    
    vertexData = std::make_unique<float[]>(9);
    vertexData.get()[0] = -0.5f;
    vertexData.get()[1] = -0.5f;
    vertexData.get()[3] = 0.5f;
    vertexData.get()[4] = -0.5f;
    vertexData.get()[6] = 0.0f;
    vertexData.get()[7] = 0.5f;
}

Rectangle::Rectangle() {
    vertexData = std::make_unique<float[]>(12);
    vertexData.get()[0] = -0.5f;
    vertexData.get()[1] = 0.5f;
    vertexData.get()[3] = -0.5f;
    vertexData.get()[4] = -0.5f;
    vertexData.get()[6] = 0.5f;
    vertexData.get()[7] = -0.5f;
    vertexData.get()[9] = 0.5f;
    vertexData.get()[10] = 0.5f;
    elementBufferData = std::make_unique<unsigned int[]>(6);
    elementBufferData.get()[0] = 0;
    elementBufferData.get()[1] = 1;
    elementBufferData.get()[2] = 2;
    elementBufferData.get()[3] = 0;
    elementBufferData.get()[4] = 2;
    elementBufferData.get()[5] = 3;
}