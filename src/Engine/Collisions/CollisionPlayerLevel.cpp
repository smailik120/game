#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "../Collisions/CollisionPlayerLevel.h"
using namespace std;
void CollisionPlayerLevel::Action(Entity* player, Entity* level) {
    Engine* engine = Engine::getEngine();
    string path = engine->getCurrentScene()->getName();
    engine->setCurrentScene(player);
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    Entity* entity = &entities->back();
    Score* scorePlayer = static_cast<Score*> (player->getComponent("score"));
    Score* score = static_cast<Score*> (entity->getComponent("score"));
    score->setScore(scorePlayer->getScore());
    Raiting* raiting = static_cast<Raiting*> (entity->getComponent("raiting"));
    Raiting* raitingPlayer = static_cast<Raiting*> (player->getComponent("raiting"));
    raiting->setRaiting(raitingPlayer->getRaiting()+scorePlayer->getScore());
    if (engine->getNumberScene() == engine->getSizeLevels()) {
    int posX = 0;
    int posY = 0;
    int result;
    int index = 0;
    list<string> scores;
    Engine* engine = Engine::getEngine();
    scores = engine->getReadOfTable()->read();
    for (std::list<string>::iterator it = scores.begin(); it != scores.end(); it++) {
        try {
        if (std::stoi(*it) < raiting->getRaiting()) {
            it--;
            *it = engine->getPlayerName();
            it++;
            *it = to_string(raiting->getRaiting());
            break;
        }
        } catch(...) {
        }
    }
    engine->getWriteToTable()->write(scores);
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    cameraSystem->drawFinalTable(scores);
    cameraSystem->screenAgain();
    engine->playAgain();
    }
}


