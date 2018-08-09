#ifndef _COLLISIONTOWERPLAYER_H
#define _COLLISIONTOWERPLAYER_H
#include "../Collisions/Collision.h"
#include "../Entity/Entity.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
#include "../Components/Health.h"
#include "../Components/Damage.h"
#include "../Components/Velocity.h"
class CollisionTowerPlayer : public Collision {
 public:
    void Action(Entity* player, Entity* tower);
};
#endif