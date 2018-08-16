#include <list>
#include <iostream>
#include "../Collisions/CollisionPlayerPants.h"
void CollisionPlayerPants::Action(Entity* player, Entity* pants) {
    const int buttonTake = 121;
    const int buttonPut = 110;
    Health* healthPlayer = static_cast<Health*> (player->getComponent("health"));
    Health* healthPants = static_cast<Health*> (pants->getComponent("health"));
    Death* death = static_cast<Death*> (pants->getComponent("death"));
    Slots* slots = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slots->getSlots();
    Bag* bag = static_cast<Bag*> (player->getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    Entity entity;
    entity.add("active", new Active());
    entity.add("health", new Health(healthPants->getHealth()));
    entity.add("death", new Death());
    entity.setName("pants");
    listBag->push_front(entity);
    Engine* engine = Engine::getEngine();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    int change = cameraSystem->putThing(pants);
    if (change == buttonTake) {
        if (slots->getPants() == NULL) {
            listSlots->push_front(entity);
        }
    }
    death->setDeath(true);
}