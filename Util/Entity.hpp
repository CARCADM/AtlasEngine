#pragma once

#include <iostream>
#include <unordered_map>
#include <Component.hpp>

namespace ECS {
class Entity {
    static unsigned int globalID;
    std::unordered_map<Component_Type, Component*> childComponents;

    public:
    unsigned int id;
    // An entity can only hold one of each component type.
    Entity();
    ~Entity();

    // Returns: Whether the addition was a success.
    bool addComponent(Component_Type componentToAdd);

    // Returns: Whether the removal was successful.
    bool removeComponent(Component_Type component);

    // Returns: The desired component if one is attached, if there is not one then a default nullptr will be inserted instead
    Component *getComponent(Component_Type componentToGet);
};
}