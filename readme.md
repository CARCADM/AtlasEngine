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

## Compatibility

Atlas Engine will likely first only be compatible with Windows
10/11 initially, but I do intend to build it with compatibility
in mind, mainly with Linux. It is very unlikely I will create
a version to integrate with MacOS or Apple at all. This is
because Apple is super stingy with their ecosystem.

## Project Overview

### Creating the neccessary subsystems:

There are two subsystems needed for the engine to work, the window class,
and the renderer subsystems. The window class is a static class designated
to creating the main game window, this mean the engine only suppourts one
window.

### Adding major rendering features:

Add texture processing, and separate dynamic and static sprites into their
own groups.

#### Dynamic Sprites

Dynamic sprites are sprites that are free to move around on the screen freely,
this inclues rescaling, translating, and rotating itself. Dynamic sprites are
significantly slower in comparison to **static sprite** mainly because they
cannot be batched by OpenGL. Each dynamic object has its own VAO, VBO, and EBO.
As well as its own texture buffer and optionally its own shader. These features
do give the user more control over the object, but its at the cost of performance,
as any time OpenGL wants to render the sprite it must swap the buffer which adds
many extra steps under the hood.

#### Static Sprites

Static sprites, while more difficult to code into the game engine because of the
need to code a texture atlas algorithm and handle batching, is significantly simpler
and more efficient for the OpenGL renderer to handle. There are however some drawbacks
to using a static sprite that being you cannot modify its position, size, or rotation
without modifying every other static sprite on the screen. This means that while you can
move static sprites freely around, they must all move at the same time. The current goal
is to have it so that you can still animate static sprites, but that will likely prove
difficult do to the use of a texture atlas to handle the rendering of sprites.

#### Texture atlasing

A texture atlas is essentially a group of textures all on one giant image. The biggest
struggle with texture atlasses is the reqirement of the use of a **packing algorithm**.
The easiest and quickest (while not most optimal way) to handle atlas creation would be
the use of a packing algorithm known as the **Skyline Sorting Algorithm**. This algorithm
is well known for its speed, and simplicity making it easy to use. The biggest issue
however would be figuring out how to decode PNGs and JPEGs as well as any other image
file types we would also like to include, this issue is solved with the use of an important
open source C++ library known as **stb_image_write** and **stb_image**. Both of these libs
are header only files meant to abstract away the decoding of PNGs and JPEGs, while it might
be fun to write these myself, I am already avoiding the use of the **stb_rect_pack** lib
mainly so I can maintain as much control as possible in the functionality of the code.

[Under Construction]