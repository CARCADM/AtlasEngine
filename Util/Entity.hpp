#pragma once

#include <iostream>
#include <unordered_map>
#include <Component.hpp>

namespace ECS {
class Entity {
    static unsigned int globalID;
    unsigned int id;
    std::unordered_map<Component_Type, Component> childComponents;

    public:
    // An entity can only hold one of each component type.
    Entity();

    // Returns: Whether the addition was a success.
    bool addComponent(Component_Type &componentToAdd);

    // Returns: Whether the removal was successful.
    bool removeComponent(Component_Type &component);
    // Returns: Whether the removal was successful.
    // TODO: replace int with a meaningful type
    bool removeComponent(Component_Type ID);

    // Returns: The desired component if one is attached, if there is not one, return -1
    int getComponent(Component_Type &componentToGet);
};
}