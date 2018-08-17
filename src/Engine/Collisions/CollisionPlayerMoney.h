#ifndef _COLLISIONPLAYERMONEY_H
#define _COLLISIONPLAYERMONEY_H
#include "../Collisions/Collision.h"
#include "../Entity/Engine.h"
#include "../Entity/Entity.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
#include "../Components/Death.h"
class CollisionPlayerMoney : public Collision {
 public:
    void Action(Entity* player, Entity* level);
};
#endif
