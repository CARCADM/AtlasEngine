#include <iostream>
#include <Window.hpp>
#include <EventLoop.hpp>
#include <Component.hpp>
#include <Entity.hpp>
#include <SDL3/SDL.h>

using namespace window;
using namespace ECS;

int main() {
    Window mainWindow = Window("Main Window", 1920, 1080, SDL_WINDOW_RESIZABLE);
    mainWindow.enableSDL3Video();
    bool done = false;
    Entity mainEntity = Entity();
    mainEntity.addComponent(RENDERER);

    // Main loop
    while(!done) {
        EventLoop::pollEvents();

        if(EventLoop::getEvent(SDL_EVENT_QUIT)) {
            done = true;
        }
    }

    SDL_Quit();
}