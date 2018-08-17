#ifndef _COLLISIONPLAYERTOWER_H
#define _COLLISIONPLAYERTOWER_H
#include "../Collisions/Collision.h"
#include "../Entity/Engine.h"
#include "../Entity/Entity.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
#include "../Components/Health.h"
#include "../Components/Velocity.h"
#include "../Components/Damage.h"
#include "../Components/Death.h"
class CollisionPlayerTower : public Collision {
 public:
    void Action(Entity* player, Entity* tower);
};
#endif