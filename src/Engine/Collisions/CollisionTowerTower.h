#ifndef _COLLISIONTOWERTOWER_H
#define _COLLISIONTOWERTOWER_H
#include "../Collisions/Collision.h"
#include "../Entity/Entity.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
#include "../Components/Health.h"
#include "../Components/Damage.h"
#include "../Components/Velocity.h"
class CollisionTowerTower : public Collision {
 public:
    void Action(Entity* towerFirst, Entity* towerSecond);
};
#endif