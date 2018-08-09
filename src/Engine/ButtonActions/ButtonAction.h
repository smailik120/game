#ifndef _BUTTONACTION_H
#define _BUTTONACTION_H
#include "../Entity/Entity.h"
class ButtonAction {
 public:
    virtual void Action(Entity *player) = 0;
};
#endif