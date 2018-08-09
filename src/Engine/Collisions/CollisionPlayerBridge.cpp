#include <list>
#include <iostream>
#include "../Collisions/CollisionPlayerBridge.h"
void CollisionPlayerBridge::Action(Entity* player, Entity* bridge) {
    const int buttonY = 121;
    const int buttonN = 110;
    Health* healthPlayer = static_cast<Health*> (player->getComponent("health"));
    Health* healthBridge = static_cast<Health*> (bridge->getComponent("health"));
    Death* death = static_cast<Death*> (bridge->getComponent("death"));
    Slots* slots = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slots->getSlots();
    Bag* bag = static_cast<Bag*> (player->getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    Entity entity;
    entity.add("active", new Active());
    entity.add("health", new Health(healthBridge->getHealth()));
    entity.add("death", new Death());
    entity.setName("bridge");
    listBag->push_front(entity);
    Engine* engine = Engine::getEngine();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    int change = cameraSystem->putThing(bridge);
    if (change == 121) {
        if (slots->getBridge() == NULL) {
            listSlots->push_front(entity);
        }
    }
    death->setDeath(true);
}