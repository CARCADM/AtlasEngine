#pragma once

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <SDL3/SDL.h>

namespace window {
typedef Uint32 keycode;
typedef SDL_EventType eventType;

class EventLoop {
    EventLoop() = delete;
    EventLoop &operator=(EventLoop &eLoop) = delete;

    static SDL_Event kEvent;
    static std::unordered_set<keycode> eventSet;
    static std::unordered_map<keycode, int> keyStates;
    static const bool *keyboardInputs;

    static void updatePressTriggers();

    public:

    static void assignEventLoop(SDL_Event &eLoop);

    static void pollEvents();

    static bool getEvent(const eventType &eventType);

    static bool getInputPressed(const keycode &keycode);

    static bool getInputJustPressed(const keycode &keycode);
    
    static bool getInputJustReleased(const keycode &keycode);
};

// Keycodes for game input
enum Keycode {
    keyA = SDL_SCANCODE_A,
    keyB,
    keyC,
    keyD,
    keyE,
    keyF,
    keyG,
    keyH,
    keyI,
    keyJ,
    keyK,
    keyL,
    keyM,
    keyN,
    keyO,
    keyP,
    keyQ,
    keyR,
    keyS,
    keyT,
    keyU,
    keyV,
    keyW,
    keyX,
    keyY,
    keyZ,
    
    key1,
    key2,
    key3,
    key4,
    key5,
    key6,
    key7,
    key8,
    key9,
    key0,

    keyRETURN,
    keyESCAPE,
    keyBACKSPACE,
    keyTAB,
    keySPACE,

    keyMINUS,
    keyEQUALS,
    keyLBRACKET,
    keyRBRACKET,
    keyBACKSLASH,
    
    keySEMICOLON = SDL_SCANCODE_SEMICOLON,
    keyAPOSTROPHE,
    keyTILDA,
    keyCOMMA,
    keyPERIOD,
    keySLASH,

    keyCAPSLOCK,

    keyF1,
    keyF2,
    keyF3,
    keyF4,
    keyF5,
    keyF6,
    keyF7,
    keyF8,
    keyF9,
    keyF10,
    keyF11,
    keyF12,

    keyPRINTSCREEN,
    keySCROLLLOCK,
    keyPAUSE,
    keyINSERT,

    keyHOME,
    keyPGUP,
    keyDELETE,
    keyEND,
    keyPGDOWN,
    keyRIGHTARROW,
    keyLEFTARROW,
    keyDOWNARROW,
    keyUPARROW,

    keyLCTRL = SDL_SCANCODE_LCTRL,
    keyLSHIFT,
    keyLALT,
    keyLGUI,
    keyRCTRL,
    keyRSHIFT,
    keyRALT,
    keyRGUI
};
}