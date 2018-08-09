
#ifndef _LEFTACTION_H
#define _LEFTACTION_H
#include "../Entity/Entity.h"
#include "../Entity/Engine.h"
#include "../ButtonActions/ButtonAction.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
class LeftAction : public ButtonAction {
 public:
    void Action(Entity* player);
};
#endif