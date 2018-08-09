#include <stdlib.h>
#include <list>
#include <iostream>
#include <random>
#include "../Systems/DropSystem.h"
void DropSystem::update() {
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
        for (list<Entity>::iterator it = entities->begin(); it != entities->end(); it++) {
            if (validate(&(*it))) {
                Health* health = static_cast<Health*> (it->getComponent("health"));
                Bag* bag = static_cast<Bag*> ((&(*it))->getComponent("bag"));
                if (health->isDeath()) {
                    list<Entity>* things = bag->getThings();
                    for (list<Entity>::iterator it1 = things->begin(); it1 != things->end(); it1++) {
                        Position* position = static_cast<Position*> ((&(*it))->getComponent("position"));
                        it1->add("position", new Position(position->getX(), position->getY()));
                        entities->push_front(*it1);
                    }
                }
            }
        }
        engine->getCurrentScene()->sortEntities();
}
bool DropSystem::validate(Entity* entity) {
    return !(entity->getComponent("bag") == NULL || entity->getComponent("health") == NULL);
}
