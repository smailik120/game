#ifndef _COLLISIONPLAYERLEVEL_H
#define _COLLISIONPLAYERLEVEL_H
#include<cstdio>
#include "../Collisions/Collision.h"
#include "../Entity/Entity.h"
#include "../Systems/System.h"
#include "../Systems/CameraSystem.h"
#include "../Entity/Engine.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
#include "../../WorkWithFiles/Reader.h"
#include "../../WorkWithFiles/Writer.h"
class CollisionPlayerLevel : public Collision {
 public:
    void Action(Entity* player, Entity* level);
};
#endif
