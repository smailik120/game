#include <list>
#include <string>
#include <iostream>
#include "../Systems/SlotSystem.h"
void SlotSystem::update() {
    int allHealth = 0;
    int allDamage = 0;
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    Entity* player = &entities->back();
    Health* playerHealth = static_cast<Health*> (player->getComponent("health"));
    Damage* playerDamage = static_cast<Damage*> (player->getComponent("damage"));
    Slots* slots = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slots->getSlots();
    for (list<Entity>::iterator it = listSlots->begin(); it != listSlots->end(); it++) {
        if (validate(&(*it))) {
            Active* active = static_cast<Active*> ((&(*it))->getComponent("active"));
            if (active->getActive() == false) {
                Health* health = static_cast<Health*> ((&(*it))->getComponent("health"));
                Damage* damage = static_cast<Damage*> ((&(*it))->getComponent("damage"));
                if (health != NULL) {
                    allHealth += health->getHealth();
                    active->setActive(true);
                }
                if(damage != NULL) {
                    allDamage += damage->getDamage();
                    active->setActive(true);
                }
            }
        }
    }
    playerHealth->setHealth(playerHealth->getHealth() + allHealth);
    playerDamage->setDamage(playerDamage->getDamage() + allDamage);
}

bool SlotSystem::validate(Entity* entity) {
    return !(entity->getComponent("active") == NULL);
}