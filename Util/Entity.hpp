#pragma once

#include <iostream>
#include <vector>
#include <Util/Component.hpp>

using namespace ECS;
class Entity {
    static int globalID;
    int id;
    std::vector<Component> childComponents;

    // Elipses!!!
    template<typename... Component>
    Entity(Component... components);

    /* 
        This is a special function so bear with me here, since the programmer will only be working with Lua
        We can take advantage of some pretty risky and dangerous pointer manipulation since it is all 
        abstracted away anyways. So essentially how this is going to work is the add component class will create
        a new instance of the component they wish to add that will be placed in this function, then on the functions
        end, it will copy the component over to itself, and then delete the components original data, thus placing
        the data only on the entity, and in a way "taking" the component from the user.

        Returns: Whether the addition was a success.
    */
    bool addComponent(Component *componentToAdd);

    // Returns: Whether the removal was successful.
    bool removeComponent(Component &component);
    // Returns: Whether the removal was successful.
    // TODO: replace int with a meaningful type
    bool removeComponent(int ID);

    // Returns: The desired component if one is attached, if there is not one, return -1
    int getComponent(Component *componentToGet);
};