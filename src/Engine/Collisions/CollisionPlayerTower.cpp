#include "../Collisions/CollisionPlayerTower.h"
void CollisionPlayerTower::Action(Entity* tower, Entity* player) {
    Position* positionPlayer = static_cast<Position*> (player->getComponent("position"));
    Velocity* velocityPlayer = static_cast<Velocity*> (player->getComponent("velocity"));
    Position* positionTower = static_cast<Position*> (tower->getComponent("position"));
    Velocity* velocityTower = static_cast<Velocity*> (tower->getComponent("velocity"));
    Score* scorePlayer = static_cast<Score*> (player->getComponent("score"));
    Score* scoreTower = static_cast<Score*> (tower->getComponent("score"));
    Health* healthPlayer = static_cast<Health*> (player->getComponent("health"));
    Health* healthTower = static_cast<Health*> (tower->getComponent("health"));
    Damage* damagePlayer = static_cast<Damage*> (player->getComponent("damage"));
    Damage* damageTower = static_cast<Damage*> (tower->getComponent("damage"));
    Death* death = static_cast<Death*> (tower->getComponent("death"));
    if (healthTower->isDeath()) {
        scorePlayer->setScore(scorePlayer->getScore() + scoreTower->getScore());
        death->setDeath(true);
    } else {
        healthPlayer->setHealth(healthPlayer->getHealth() - damageTower->getDamage());
    }
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