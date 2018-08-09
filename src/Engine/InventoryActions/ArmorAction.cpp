#include "../Entity/Entity.h"
#include "../InventoryActions/ArmorAction.h"
#include "../Components/Velocity.h"
#include "../Components/Position.h"
void ArmorAction::Action(Entity* player, Entity* thing) {
    Bag* bag = static_cast<Bag*> (player->getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    Slots* slot = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slot->getSlots();
}