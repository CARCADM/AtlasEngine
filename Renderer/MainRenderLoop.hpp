#pragma once

#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

namespace renderer {
class MainRenderLoop {
    SDL_GLContext renderTarget = SDL_GL_CreateContext(nullptr);
    std::vector<float> dynamicRenderObjects;

    public:
    void setRenderTargetWindow(SDL_Window *windowToTarget);

    // Rule of 3 (Not 5)
    MainRenderLoop(SDL_Window *windowToTarget);
    ~MainRenderLoop();
    MainRenderLoop(MainRenderLoop &cRenderLoop);
    MainRenderLoop& operator=(MainRenderLoop &cRenderLoop);

    // Updates every update in case you didn't know
    virtual inline void renderLoopUpdate();
};
}