#ifndef _COLLISIONTOWERBRICK_H
#define _COLLISIONTOWERBRICK_H
#include "../Collisions/Collision.h"
#include "../Entity/Entity.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
#include "../Components/Health.h"
#include "../Components/Velocity.h"
#include "../Components/Damage.h"
class CollisionTowerBrick : public Collision {
 public:
    void Action(Entity* player, Entity* tower);
};
#endif