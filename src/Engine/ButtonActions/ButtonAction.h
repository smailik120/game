#ifndef _BUTTONACTION_H
#define _BUTTONACTION_H
#include <string>
#include "../Entity/Entity.h"
class ButtonAction {
 private:
    std::string nameAction;
 public:
    virtual void setName(std::string name);
    virtual std::string getName();
    virtual void Action(Entity *player) = 0;
};
#endif
