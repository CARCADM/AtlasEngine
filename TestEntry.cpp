#include <iostream>
#include <Window.hpp>
#include <EventLoop.hpp>
#include <SDL3/SDL.h>

using namespace window;

int main() {
    Window mainWindow = Window("Main Window", 1920, 1080, SDL_WINDOW_RESIZABLE);
    mainWindow.enableSDL3Video();
    bool done = false;

    // Main loop
    while(!done) {
        EventLoop::pollEvents();

        if(EventLoop::getEvent(SDL_EVENT_QUIT)) {
            done = true;
        }
    }

    SDL_Quit();
}