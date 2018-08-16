#include <string>
#include <utility>
#include "../Entity/Entity.h"
using namespace std;
Entity::Entity() {
    currentId = id;
    id++;
}

void Entity::setName(string name) {
    this->name = name;
}

void Entity::setLayer(int layer) {
    this->layer = layer;
}

void Entity::add(string name, Component* component) {
    components.insert(pair<string, Component*>(name, component));
}

void Entity::remove(string name) {
    components.erase(name);
}

string Entity::getName() {
    return this->name;
}

Component* Entity::getComponent(string name) {
    return components[name];
}

int Entity::getLayer() {
    return layer;
}

void Entity::dispose() {
    for (auto it = components.begin(); it != components.end(); ++it) {
        delete (*it).second;
    }
}
int Entity::id = 0;