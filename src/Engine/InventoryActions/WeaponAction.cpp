#include "../Entity/Entity.h"
#include "../InventoryActions/WeaponAction.h"
#include "../Components/Velocity.h"
#include "../Components/Position.h"
void WeaponAction::Action(Entity* player, Entity* thing) {
    Engine* engine = Engine::getEngine();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    SlotSystem* slotSystem = static_cast<SlotSystem*> (engine->callSystem("slot"));
    Bag* bag = static_cast<Bag*> (player->getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    Slots* slot = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slot->getSlots();
    Entity* temp = slot->getWeapon();
    Active* active = static_cast<Active*> (temp->getComponent("active"));
    active->setActive(false);
    Damage* damagePlayer = static_cast<Damage*> (player->getComponent("damage"));
    Damage* damageThing = static_cast<Damage*> (temp->getComponent("damage"));
    damagePlayer->setDamage(damagePlayer->getDamage() - damageThing->getDamage());
    slot->eraseByName(temp->getName());
    listSlots->push_back(*thing);
    slotSystem->update();
    cameraSystem->update();
}