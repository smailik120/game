#include <typeinfo>
#include <list>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include "../Systems/MoveSystem.h"
using namespace std;
MoveSystem::MoveSystem() {
}
void MoveSystem::collideAfterMove() {
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    list<Entity>* velocityEntities = engine->getCurrentScene()->getVelocityEntities();
    Entity* player = &entities->back();
    for (list<Entity>::iterator it = velocityEntities->begin(); it != velocityEntities->end(); it++) {
        Position* positionSecondEntity = static_cast<Position*> (it->getComponent("position"));
        Velocity* velocitySecondEntity = static_cast<Velocity*> (it->getComponent("velocity"));
        move(player, &(*it));
        for (list<Entity>::iterator it1 = entities->begin(); it1 != entities->end(); it1++) {
            Position* positionFirstEntity = static_cast<Position*> ((&(*it1))->getComponent("position"));
                string name = it->getName();
                string name1 = it1->getName();
                if (positionFirstEntity->getX() == positionSecondEntity->getX()) {
                    if (positionFirstEntity->getY() == positionSecondEntity->getY() && it->currentId != it1->currentId) {
                        if ((*collisions)[pair<string, string>(name1, name)] != 0) {
                            (*collisions)[pair<string, string>(name1, name)]->Action(&(*it), &(*it1));
                        }
                    }
                }
            }
        }
}
bool MoveSystem::distance(int distanceX, int distanceY, Entity* entity) {
    if (entity->getComponent("position") != NULL) {
        Anger* anger = static_cast<Anger*> (entity->getComponent("anger"));
        return max(std::abs(distanceX), std::abs(distanceY)) <= anger->getAnger();
    } else {
        return false;
    }
}
void MoveSystem::move(Entity* player, Entity* another) {
    Position* positionPlayer = static_cast<Position*> (player->getComponent("position"));
    Velocity* velocityPlayer = static_cast<Velocity*> (player->getComponent("velocity"));
    Position* positionSecondEntity = static_cast<Position*> (another->getComponent("position"));
    Velocity* velocitySecondEntity = static_cast<Velocity*> (another->getComponent("velocity"));
    int distanceX = positionSecondEntity->getX()-positionPlayer->getX();
    int distanceY = positionSecondEntity->getY()-positionPlayer->getY();
        if (distance(distanceX, distanceY, another)) {
            if (std::abs(distanceX) > std::abs(distanceY)) {
                if (positionPlayer->getX() > positionSecondEntity->getX()) {
                    velocitySecondEntity->setSpeedX(1);
                } else if (positionPlayer->getX() < positionSecondEntity->getX()) {
                    velocitySecondEntity->setSpeedX(-1);
                }
                velocitySecondEntity->setSpeedY(0);
                } else {
                    if (positionPlayer->getY() > positionSecondEntity->getY()) {
                        velocitySecondEntity->setSpeedY(1);
                    } else if (positionPlayer->getY() < positionSecondEntity->getY()) {
                        velocitySecondEntity->setSpeedY(-1);
                    }
                    velocitySecondEntity->setSpeedX(0);
                }
                positionSecondEntity->setX(positionSecondEntity->getX() + velocitySecondEntity->getSpeedX());
                positionSecondEntity->setY(positionSecondEntity->getY() + velocitySecondEntity->getSpeedY());
            }
}
void MoveSystem::update() {
    Engine* engine = Engine::getEngine();
    collisions = engine->getMapCollisions();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    cameraSystem->update();
    collide();
    collideAfterMove();
}
void MoveSystem::collide() {
    int k = 0;
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    list<Entity>* velocityEntities = engine->getCurrentScene()->getVelocityEntities();
    for (list<Entity>::iterator it = velocityEntities->begin(); it != velocityEntities->end(); it++) {
        for (list<Entity>::iterator it1 = entities->begin(); it1 != entities->end(); it1++) {
            k++;
            if (validate(&(*it)) && validate(&(*it1))) {
                string name = it->getName();
                string name1 = it1->getName();
                if ((*collisions)[pair<string, string>(name, name1)] != 0) {
                    Position* pos = static_cast<Position*> ((&(*it))->getComponent("position"));
                    Position* pos1 = static_cast<Position*> ((&(*it1))->getComponent("position"));
                    if (pos->getY() == pos1->getY() && pos1->getX() == pos->getX() && it->currentId != it1->currentId) {
                        (*collisions)[pair<string, string>(name, name1)]->Action(&(*it), &(*it1));
                    }
                }
            }
        }
    }
}

bool MoveSystem::validate(Entity* entity) {
    return !(entity->getComponent("position") == NULL);
}