#pragma once

#include <iostream>

namespace ECS {
// An enum used to identify the components type, note that since Component_Type inherits unsigned char there can only be 256 components (More than enough).
enum Component_Type : unsigned char {
    RENDERER
};

// This is just an abstract struct to take advantage of polymorphism.
struct Component {
    Component();
    // Abstract things do be happening in here.
};
}