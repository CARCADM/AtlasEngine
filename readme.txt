# Welcome to the Atlas Engine source code!

This is the source code for Atlas Eninge, a C++ written
game engine based on Lua game development!.

## What is Atlas Engine?

Atlas Engine is a low-level game engine coded in C++,
it offers language suppourt for Lua programming allowing
games to be made in a very low-level game engine.

The engine has no UI and relies entirely on the user writing
Lua code to handle the generation of their sprites, though
the majority of the rendering is handled behind the scenes
by the C++ core of the engine.

## How is Atlas Engine built?

Atlas Engine is made up of two parts, and is more of a Lua
library than it is a game enigne. There is the core library,
which contains all of the C++ code for handing the internal
engine, and there is the extended logic, written by the user
through both Lua functions that send signals to the Core, and
Lua game logic for the actual game.