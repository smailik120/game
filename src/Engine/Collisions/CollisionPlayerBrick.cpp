#include "../Collisions/Collision.h"
#include "../Collisions/CollisionPlayerBrick.h"
#include "../Entity/Entity.h"
#include "../Components/Position.h"
#include "../Components/Score.h"
#include "../Components/Velocity.h"
void CollisionPlayerBrick::Action(Entity* player, Entity* brick) {
    Position* positionPlayer = static_cast<Position*> (player->getComponent("position"));
    Velocity* velocityPlayer = static_cast<Velocity*> (player->getComponent("velocity"));
    Score* scorePlayer = static_cast<Score*> (player->getComponent("score"));
    if (velocityPlayer->getSpeedY() > 0) {
        positionPlayer->setY(positionPlayer->getY() - velocityPlayer->getSpeedY());
    }
    if (velocityPlayer->getSpeedY() < 0) {
        positionPlayer->setY(positionPlayer->getY() - velocityPlayer->getSpeedY());
    }
    if (velocityPlayer->getSpeedX() > 0) {
        positionPlayer->setX(positionPlayer->getX() - velocityPlayer->getSpeedX());
    }
    if (velocityPlayer->getSpeedX() < 0) {
        positionPlayer->setX(positionPlayer->getX() - velocityPlayer->getSpeedX());
    }
    }