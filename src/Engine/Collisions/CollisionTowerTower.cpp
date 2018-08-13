#include "../Collisions/CollisionTowerTower.h"
void CollisionTowerTower::Action(Entity* tower, Entity* player) {
    Position* positionPlayer = static_cast<Position*> (player->getComponent("position"));
    Velocity* velocityPlayer = static_cast<Velocity*> (player->getComponent("velocity"));
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