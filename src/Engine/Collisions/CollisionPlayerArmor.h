#ifndef _COLLISIONPLAYERARMOR_H
#define _COLLISIONPLAYERARMOR_H
#include "../Collisions/Collision.h"
#include "../Entity/Engine.h"
#include "../Entity/Entity.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
#include "../Components/Health.h"
#include "../Components/Damage.h"
#include "../Components/Slots.h"
#include "../Components/Bag.h"
#include "../Components/Velocity.h"
#include "../Entity/Engine.h"
class CollisionPlayerArmor : public Collision {
 public:
    void Action(Entity* player, Entity* tower);
};
#endif