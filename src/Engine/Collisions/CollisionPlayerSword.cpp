#include <list>
#include <iostream>
#include "../Collisions/CollisionPlayerSword.h"
void CollisionPlayerSword::Action(Entity* player, Entity* sword) {
    const int buttonY = 121;
    const int buttonN = 110;
    Damage* damageSword = static_cast<Damage*> (sword->getComponent("damage"));
    Death* death = static_cast<Death*> (sword->getComponent("death"));
    Slots* slots = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slots->getSlots();
    Bag* bag = static_cast<Bag*> (player->getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    Entity entity;
    entity.add("active", new Active());
    entity.add("damage", new Damage(damageSword->getDamage()));
    entity.add("death", new Death());
    entity.setName("weapon");
    listBag->push_front(entity);
    Engine* engine = Engine::getEngine();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    int change = cameraSystem->putThing(sword);
    if (change == 121) {
        pair<int, int>* coordinates = cameraSystem->log;
        engine->logs->push_front("The player took sword");
        if (slots->getWeapon() == NULL) {
            listSlots->push_front(entity);
        }
    }
    death->setDeath(true);
}