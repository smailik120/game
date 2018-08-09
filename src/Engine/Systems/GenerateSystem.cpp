#include <stdlib.h>
#include <list>
#include <iostream>
#include <random>
#include "../Systems/GenerateSystem.h"
void GenerateSystem::update() {
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    unsigned int rand_value = time(NULL);
    rand_r(&rand_value);
    if (rand_r(&rand_value) % 10 == 0) {
        for (list<Entity>::iterator it = entities->begin(); it != entities->end(); it++) {
            if (it->getName() == "floor") {
                Position* position = static_cast<Position*> ((&(*it))->getComponent("position"));
                Sprite *spriteMoney = new Sprite('$');
                Position* positionMoney = new Position(position->getX(), position->getY());
                Entity entity;
                entity.add("position", positionMoney);
                entity.add("sprite", spriteMoney);
                entity.add("score", new Score(10));
                entity.setName("money");
                entities->push_front(entity);
                entities->erase(it);
                it->dispose();
                break;
            }
        }
        refresh();
    }
}
bool GenerateSystem::validate(Entity* entity) {
    return !(entity->getComponent("score") == NULL || entity->getComponent("sprite") == NULL);
}
