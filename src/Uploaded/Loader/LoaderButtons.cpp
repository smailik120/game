#include "../Loader/LoaderButtons.h"
map<int, ButtonAction*>* LoaderButtons::load() {
    map<int, ButtonAction*>* buttonAction = new  map<int, ButtonAction*>();
    UpAction* up = new UpAction();
    up->setName("move");
    DownAction* down = new DownAction();
    down->setName("move");
    LeftAction* left = new LeftAction();
    left->setName("move");
    RightAction* right = new RightAction();
    right->setName("move");
    InventoryAction* inventory = new InventoryAction();
    inventory->setName("inventory");
    buttonAction->insert(pair<int, ButtonAction*>(buttonUp, up));
    buttonAction->insert(pair<int, ButtonAction*>(buttonLeft, left));
    buttonAction->insert(pair<int, ButtonAction*>(buttonDown, down));
    buttonAction->insert(pair<int, ButtonAction*>(buttonRight, right));
    buttonAction->insert(pair<int, ButtonAction*>(buttonInventory, inventory));
    return buttonAction;
}