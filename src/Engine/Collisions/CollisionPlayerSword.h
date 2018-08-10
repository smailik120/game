#ifndef _COLLISIONPLAYERSWORD_H
#define _COLLISIONPLAYERSWORD_H
#include "../Collisions/Collision.h"
#include "../Entity/Entity.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
#include "../Components/Health.h"
#include "../Components/Damage.h"
#include "../Components/Slots.h"
#include "../Components/Bag.h"
#include "../Components/Velocity.h"
#include "../Entity/Engine.h"
class CollisionPlayerSword : public Collision {
 public:
    void Action(Entity* player, Entity* tower);
};
#endif