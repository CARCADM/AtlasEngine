#pragma once

#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

class MainRenderLoop {
    SDL_GLContext renderTarget = SDL_GL_CreateContext(nullptr);
    std::vector<float> dynamicRenderObjects;

    public:
    void setRenderTargetWindow(SDL_Window *windowToTarget);

    // Rule of 3
    MainRenderLoop(SDL_Window *windowToTarget);
    ~MainRenderLoop();
    MainRenderLoop(MainRenderLoop &cRenderLoop);
    MainRenderLoop& operator=(MainRenderLoop &cRenderLoop);

    virtual inline void renderLoopUpdate();
};