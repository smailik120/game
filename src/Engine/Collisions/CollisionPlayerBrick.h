#ifndef _COLLISIONPLAYERBRICK_H
#define _COLLISIONPLAYERBRICK_H
#include "../Collisions/Collision.h"
#include "../Entity/Entity.h"
class CollisionPlayerBrick : public Collision {
 public:
    void Action(Entity* player, Entity* level);
};
#endif
