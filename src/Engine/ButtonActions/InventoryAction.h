#ifndef _INVENTORYACTION_H
#define _INVENTORYACTION_H
#include "../Entity/Entity.h"
#include "../Entity/Engine.h"
#include "../ButtonActions/ButtonAction.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
class InventoryAction : public ButtonAction {
 public:
    void Action(Entity* player);
};
#endif