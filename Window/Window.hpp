#pragma once

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

namespace window {
    class Window {
        public:
            SDL_Window *win;
            const char *winName;
            SDL_GLContext surface;

            // Static methods
            static bool enableSDL3Video();

            // Constructs a new Window ensuring OpenGL is enabled on it.
            Window(const char *name, int width, int height, SDL_WindowFlags flags);

            bool resizeWindow(int width, int height);

            bool setAndLimitAspectRatio(float minRatio, float maxRatio);

            Window(Window &window);

            Window *operator=(Window &kWindow);

            // Deconstructor
            ~Window();
    };
}