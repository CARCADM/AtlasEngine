#include <Window.hpp>

using namespace window;

bool Window::enableSDL3Video() {
    return SDL_InitSubSystem(SDL_INIT_VIDEO);
}

Window::Window(const char *name, int width, int height, SDL_WindowFlags flags) {
    win = SDL_CreateWindow(name, width, height, flags | SDL_WINDOW_OPENGL);
    winName = name;
    surface = SDL_GL_CreateContext(win);
}

bool Window::resizeWindow(int width, int height) {
    return SDL_SetWindowSize(win, width, height);
}

bool Window::setAndLimitAspectRatio(float minRatio, float maxRatio) {
    return SDL_SetWindowAspectRatio(win, minRatio, maxRatio);
}

Window::Window(Window &kWindow) {
    winName = kWindow.winName;
    int w, h; 
    SDL_GetWindowSize(kWindow.win, &w, &h);
    SDL_WindowFlags flags = SDL_GetWindowFlags(kWindow.win);
    win = SDL_CreateWindow(winName, w, h, flags);
    SDL_GL_DestroyContext(surface);
    surface = kWindow.surface;
}

Window *Window::operator=(Window &kWindow) {
    SDL_DestroyWindow(win);
    delete winName;
    winName = kWindow.winName;
    int w, h;
    SDL_GetWindowSize(kWindow.win, &w, &h);
    SDL_WindowFlags flags = SDL_GetWindowFlags(kWindow.win);
    win = SDL_CreateWindow(winName, w, h, flags);
    SDL_GL_DestroyContext(surface);
    surface = kWindow.surface;
    return this;
}

Window::~Window() {
    SDL_DestroyWindow(win);
    SDL_GL_DestroyContext(surface);
    delete winName;
}