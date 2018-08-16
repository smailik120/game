#include <list>
#include "../Systems/DeleteSystem.h"
void DeleteSystem::update() {
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    list<Entity>* velocityEntities = engine->getCurrentScene()->getVelocityEntities();
    for (list<Entity>::iterator it = velocityEntities->begin(); it != velocityEntities->end(); it++) {
        if (validate(&(*it))) {
            Score* score = static_cast<Score*> ((&(*it))->getComponent("score"));
            Sprite* sprite = static_cast<Sprite*> ((&(*it))->getComponent("sprite"));
            Position* position = static_cast<Position*> ((&(*it))->getComponent("position"));
            Health* health = static_cast<Health*> ((&(*it))->getComponent("health"));
            if (score->isDeath() || health->isDeath()) {
                velocityEntities->erase(it);
                it--;
            }
        }
    }
    for (list<Entity>::iterator it = entities->begin(); it != entities->end(); it++) {
        if (validate(&(*it))) {
            Score* score = static_cast<Score*> ((&(*it))->getComponent("score"));
            Sprite* sprite = static_cast<Sprite*> ((&(*it))->getComponent("sprite"));
            Position* position = static_cast<Position*> ((&(*it))->getComponent("position"));
            Health* health = static_cast<Health*> ((&(*it))->getComponent("health"));
            Death* death = static_cast<Death*> ((&(*it))->getComponent("death"));
            if (death->getDeath()) {
                Entity entity;
                entity.add("position", new Position(position->getX(), position->getY()));
                entity.add("sprite", new Sprite('.'));
                entity.setName("floor");
                entity.setLayer(0);
                entities->push_front(entity);
                entities->erase(it);
                (*it).dispose();
                it--;
            }
        }
    }
}

bool DeleteSystem::validate(Entity* entity) {
    return
    !(entity->getComponent("death") == NULL
    || entity->getName() == "player");
}

