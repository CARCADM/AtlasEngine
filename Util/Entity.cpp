#include <Entity.hpp>

using namespace ECS;

Entity::Entity() {
    id = globalID;
    globalID += 1;
}
Entity::~Entity() {
    for(const auto component : childComponents) {
        delete component.second;
    }
    childComponents.clear();
}

bool Entity::addComponent(Component_Type componentToAdd) {
    try {
        switch (componentToAdd) {
            case RENDERER:
                childComponents[componentToAdd] = new ECS::RenderComponent();
                break;
            default:
                return false;
        }
        return true;
    } catch (char* e) {
        std::cerr << e << std::endl;
        return false;
    }
}

bool Entity::removeComponent(Component_Type componentToRemove) {
    try {
        delete childComponents[componentToRemove];
        childComponents.erase(componentToRemove);
        return true;
    } catch (char* e) {
        std::cerr << e << std::endl;
        return false;
    }
}

Component* Entity::getComponent(Component_Type componentToGet) {
    return childComponents[componentToGet];
}

unsigned int Entity::globalID = 0;