
#ifndef _DOWNACTION_H
#define _DOWNACTION_H
#include "../Entity/Entity.h"
#include "../Entity/Engine.h"
#include "../ButtonActions/ButtonAction.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
class DownAction : public ButtonAction {
 public:
    void Action(Entity* player);
};
#endif