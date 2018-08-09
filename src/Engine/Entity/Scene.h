#ifndef _SCENE_H
#define _SCENE_H
#include <list>
#include <iterator>
#include <string>
#include "../Entity/Entity.h"
#include "../Systems/SystemManager.h"
class Scene {
 private:
    list<Entity>* entities;
    list<Entity>* velocityEntities;
    string name;
 public:
    Scene();
    Scene(list<Entity>* entities, string name);
    explicit Scene(string name);
    void update(SystemManager* systemManager);
    void setName(string name);
    string getName();
    void sortEntities();
    list<Entity>* getEntities();
    list<Entity>* getVelocityEntities();
};
#endif
