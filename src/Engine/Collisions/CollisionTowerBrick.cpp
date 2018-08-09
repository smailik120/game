#include "../Collisions/CollisionTowerBrick.h"
void CollisionTowerBrick::Action(Entity* brick, Entity* tower) {
    Position* positionTower = static_cast<Position*> (tower->getComponent("position"));
    Velocity* velocityTower = static_cast<Velocity*> (tower->getComponent("velocity"));
    if (velocityTower->getSpeedY() > 0) {
        positionTower->setY(positionTower->getY() - velocityTower->getSpeedY());
    }
    if (velocityTower->getSpeedY() < 0) {
        positionTower->setY(positionTower->getY() - velocityTower->getSpeedY());
    }
    if (velocityTower->getSpeedX() > 0) {
        positionTower->setX(positionTower->getX() - velocityTower->getSpeedX());
        }
    if (velocityTower->getSpeedX() < 0) {
        positionTower->setX(positionTower->getX() - velocityTower->getSpeedX());
    }
}