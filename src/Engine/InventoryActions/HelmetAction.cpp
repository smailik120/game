#include "../Entity/Entity.h"
#include "../InventoryActions/HelmetAction.h"
#include "../Components/Velocity.h"
#include "../Components/Position.h"
void HelmetAction::Action(Entity* player, Entity* thing) {
    Engine* engine = Engine::getEngine();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    SlotSystem* slotSystem = static_cast<SlotSystem*> (engine->callSystem("slot"));
    Bag* bag = static_cast<Bag*> (player->getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    Slots* slot = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slot->getSlots();
    Entity* temp = slot->getHelmet();
    Active* active = static_cast<Active*> (temp->getComponent("active"));
    active->setActive(false);
    Health* healthPlayer = static_cast<Health*> (player->getComponent("health"));
    Health* healthThing = static_cast<Health*> (temp->getComponent("health"));
    healthPlayer->setHealth(healthPlayer->getHealth() - healthThing->getHealth());
    slot->eraseByName(temp->getName());
    listSlots->push_back(*thing);
    slotSystem->update();
    cameraSystem->update();
}