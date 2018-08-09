
#ifndef _RIGHTACTION_H
#define _RIGHTACTION_H
#include "../Entity/Entity.h"
#include "../Entity/Engine.h"
#include "../ButtonActions/ButtonAction.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
class RightAction : public ButtonAction {
 public:
    void Action(Entity* player);
};
#endif