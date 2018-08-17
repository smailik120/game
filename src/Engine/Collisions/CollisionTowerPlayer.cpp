#include <iostream>
#include "../Collisions/CollisionTowerPlayer.h"
void CollisionTowerPlayer::Action(Entity* tower, Entity* player) {
    Health* healthPlayer = static_cast<Health*> (player->getComponent("health"));
    Health* healthTower = static_cast<Health*> (tower->getComponent("health"));
    Position* positionPlayer = static_cast<Position*> (player->getComponent("position"));
    Velocity* velocityPlayer = static_cast<Velocity*> (player->getComponent("velocity"));
    Damage* damageTower = static_cast<Damage*> (tower->getComponent("damage"));
    Position* positionTower = static_cast<Position*> (tower->getComponent("position"));
    Velocity* velocityTower = static_cast<Velocity*> (tower->getComponent("velocity"));
    Score* scorePlayer = static_cast<Score*> (player->getComponent("score"));
    Score* scoreTower = static_cast<Score*> (tower->getComponent("score"));
    Damage* damagePlayer = static_cast<Damage*> (player->getComponent("damage"));
    healthTower->setHealth(healthTower->getHealth() - damagePlayer->getDamage());
    refresh();
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