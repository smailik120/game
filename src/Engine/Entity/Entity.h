#ifndef _ENTITY_H
#define _ENTITY_H
#include <map>
#include <cstring>
#include <string>
#include <iterator>
#include "../Components/Component.h"
using namespace std;
class Entity {
 private:
    map<string, Component*> components;
    int layer;
 public:
    bool operator < (const Entity& entity) const {
    return this->layer < entity.layer;
    }
    string name;
    void add(string name, Component* component);
    void remove(string name);
    void setName(string name);
    void setLayer(int layer);
    int getLayer();
    Component* getComponent(string name);
    string getName();
    void dispose();
};
#endif