#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include "../Entity/Scene.h"
Scene::Scene(list<Entity>* entitie, string name) {
    this->setName(name);
    this->entities = entitie;
    velocityEntities = new list<Entity>;
    sortEntities();
    for (list<Entity>::iterator it = this->entities->begin(); it != this->entities->end(); it++) {
        if (((&(*it))->getComponent("velocity")) != NULL) {
            Entity entity = *it;
            velocityEntities->push_back(entity);
        }
    }
}

Scene::Scene() {
}

void Scene::sortEntities() {
    entities->sort();
}

void Scene::setName(string name) {
    this->name = name;
}

string Scene::getName() {
    return name;
}

Scene::Scene(string name) {
    this->name = name;
    entities = new list<Entity>;
    velocityEntities = new list<Entity>;
}

void Scene::update(SystemManager* systemManager) {
    systemManager->start();
    while (!systemManager->isEmpty()) {
        systemManager->update();
        systemManager->next();
    }
}

list<Entity>* Scene::getEntities() {
    return this->entities;
}

list<Entity>* Scene::getVelocityEntities() {
    return this->velocityEntities;
}

