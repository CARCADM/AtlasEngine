#include <RenderData.hpp>

using namespace renderer;

RenderData::RenderData(std::unique_ptr<float[]> vData) {
    RenderData::vertexData.swap(vData);
}

RenderData::RenderData(std::unique_ptr<float[]> vData, std::unique_ptr<unsigned int[]> eData) {
    RenderData::vertexData.swap(vData);
    RenderData::elementBufferData.swap(eData);
}

void RenderData::generateBuffers() {
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