#ifndef _COLLISION_H
#define _COLLISION_H
#include "../Entity/Entity.h"
class Collision {
 public:
    virtual void Action(Entity* player, Entity* another) = 0;
};
#endif