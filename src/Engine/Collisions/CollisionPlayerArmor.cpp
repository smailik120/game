#include <list>
#include <iostream>
#include "../Collisions/CollisionPlayerArmor.h"
void CollisionPlayerArmor::Action(Entity* player, Entity* armor) {
    const int buttonY = 121;
    const int buttonN = 110;
    Health* healthPlayer = static_cast<Health*> (player->getComponent("health"));
    Health* healthArmor = static_cast<Health*> (armor->getComponent("health"));
    Death* death = static_cast<Death*> (armor->getComponent("death"));
    Slots* slots = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slots->getSlots();
    Bag* bag = static_cast<Bag*> (player->getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    Entity entity;
    entity.add("active", new Active());
    entity.add("health", new Health(healthArmor->getHealth()));
    entity.add("death", new Death());
    entity.setName("armor");
    listBag->push_front(entity);
    Engine* engine = Engine::getEngine();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    int change = cameraSystem->putThing(armor);
    if (change == 121) {
        pair<int, int>* coordinates = cameraSystem->log;
        engine->logs->push_front("The player took armor");
        if (slots->getArmor() == NULL) {
            listSlots->push_front(entity);
        }
    }
    death->setDeath(true);
}