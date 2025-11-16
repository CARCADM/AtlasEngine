#include <Window/EventLoop.hpp>

using namespace window;

// -1 = not pressed (constant)
// 0 = just released
// 1 = just pressed
// 2 = pressed (constant)
void EventLoop::updatePressTriggers() {
    for(auto &value : keyStates) {
        if(keyboardInputs[value.first]) {
            if(value.second <= 0) {
                value.second = 1;
            }
            else if(value.second == 1) {
                value.second = 2;
            }
        }
        else if(!keyboardInputs[value.first]) {
            if(value.second >= 1) {
                value.second = 0;
            }
            else {
                value.second = -1;
            }
        }
    }
}

void EventLoop::assignEventLoop(SDL_Event &eLoop) {
    kEvent = eLoop;
}

void EventLoop::pollEvents() {
    eventSet.clear(); // Clear the event array to store new data
    updatePressTriggers();
    while(SDL_PollEvent(&kEvent)) {
        eventSet.emplace(kEvent.type);
    }
}

bool EventLoop::getEvent(const SDL_EventType &type) {
    return eventSet.find(type) != eventSet.end() ? true : false;
}

bool EventLoop::getInputPressed(const keycode &keycode) {
    if(keyboardInputs[keycode]) {
        return true;
    }
    return false;
}

bool EventLoop::getInputJustPressed(const keycode &keycode) {
    if(keyStates.count(keycode) == 0) {
        keyStates[keycode] = 1;
    }
    if (keyStates[keycode] == 1) {
        return true;
    }
    return false;
}

bool EventLoop::getInputJustReleased(const keycode &keycode) {
    if(keyStates.count(keycode) == 0) {
        keyStates[keycode] = 0;
    }
    if (keyStates[keycode] == 0) {
        return true;
    }
    return false;
}

SDL_Event EventLoop::kEvent = SDL_Event();
std::unordered_set<keycode> EventLoop::eventSet = std::unordered_set<keycode>();
std::unordered_map<keycode, int> EventLoop::keyStates = std::unordered_map<keycode, int>();
const bool *EventLoop::keyboardInputs = SDL_GetKeyboardState(nullptr);