#include "../Loader/LoaderInventoryActions.h"
map<string, Collision*>* LoaderInventoryActions::load() {
    map<string, Collision*>* inventoryAction = new  map<string, Collision*>();
    HelmetAction* helmet = new HelmetAction();
    inventoryAction->insert(pair<string, Collision*>("helmet", helmet));
    BridgeAction* bridge = new BridgeAction();
    inventoryAction->insert(pair<string, Collision*>("bridge", bridge));
    ArmorAction* armor = new ArmorAction();
    inventoryAction->insert(pair<string, Collision*>("armor", armor));
    WeaponAction* weapon = new WeaponAction();
    inventoryAction->insert(pair<string, Collision*>("weapon", weapon));
    return inventoryAction;
}