#include <list>
#include <iostream>
#include "../Collisions/CollisionPlayerHelmet.h"
void CollisionPlayerHelmet::Action(Entity* player, Entity* helmet) {
    const int buttonY = 121;
    const int buttonN = 110;
    Health* healthPlayer = static_cast<Health*> (player->getComponent("health"));
    Health* healthHelmet = static_cast<Health*> (helmet->getComponent("health"));
    Death* death = static_cast<Death*> (helmet->getComponent("death"));
    Slots* slots = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slots->getSlots();
    Bag* bag = static_cast<Bag*> (player->getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    Entity entity;
    entity.add("active", new Active());
    entity.add("health", new Health(healthHelmet->getHealth()));
    entity.add("death", new Death());
    entity.setName("helmet");
    listBag->push_front(entity);
    Engine* engine = Engine::getEngine();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    int change = cameraSystem->putThing(helmet);
    if (change == 121) {
        if (slots->getHelmet() == NULL) {
            listSlots->push_front(entity);
        }
    }
    death->setDeath(true);
}