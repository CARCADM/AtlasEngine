#include <Entity.hpp>

using namespace ECS;

Entity::Entity() {
    id = globalID;
    globalID += 1;
}

bool Entity::addComponent(Component_Type &componentToAdd) {
    try {
        
        return true;
    }
    catch (char* e) {
        std::cerr << e << std::endl;
        return false;
    }
}

unsigned int Entity::globalID = 0;