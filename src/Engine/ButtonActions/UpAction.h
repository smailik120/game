
#ifndef _UPACTION_H
#define _UPACTION_H
#include "../Entity/Entity.h"
#include "../Entity/Engine.h"
#include "../ButtonActions/ButtonAction.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
class UpAction : public ButtonAction {
 public:
    void Action(Entity* player);
};
#endif