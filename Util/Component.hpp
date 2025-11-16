#pragma once

#include <iostream>

namespace ECS {
// An int used to identify the components type.
enum Component_TypeID {
    RENDERER
};

// Honestly, this is just an abstract class to take advantage of polymorphism.
class Component {
    // Abstract things do be happening in here.
};
}