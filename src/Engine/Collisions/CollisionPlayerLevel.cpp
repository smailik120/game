#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "../Collisions/CollisionPlayerLevel.h"
using namespace std;
void CollisionPlayerLevel::Action(Entity* player, Entity* level) {
    Engine* engine = Engine::getEngine();
    if (engine->getNumberScene() == engine->getSizeLevels()) {
        Raiting* raitingPlayer = static_cast<Raiting*> (player->getComponent("raiting"));
        int posX = 0;
        int posY = 0;
        int result;
        int index = 0;
        list<string> scores;
        Engine* engine = Engine::getEngine();
        scores = engine->getReadOfTable()->read();
        for (std::list<string>::iterator it = scores.begin(); it != scores.end(); it++) {
            try {
                if (std::stoi(*it) < raitingPlayer->getRaiting()) {
                    it--;
                    *it = engine->getPlayerName();
                    it++;
                    *it = to_string(raitingPlayer->getRaiting());
                    break;
                }
            } catch(...) {
            }
        }
        engine->getWriteToTable()->write(scores);
        CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
        cameraSystem->drawFinalTable(scores);
        engine->end();
    } else {
        engine->setCurrentScene(player);
        string path = engine->getCurrentScene()->getName();
        list<Entity>* entities = engine->getCurrentScene()->getEntities();
        Entity* entity = &entities->back();
        Score* scorePlayer = static_cast<Score*> (player->getComponent("score"));
        Score* score = static_cast<Score*> (entity->getComponent("score"));
        score->setScore(scorePlayer->getScore());
        Raiting* raiting = static_cast<Raiting*> (entity->getComponent("raiting"));
        Raiting* raitingPlayer = static_cast<Raiting*> (player->getComponent("raiting"));
        raiting->setRaiting(raitingPlayer->getRaiting()+scorePlayer->getScore());
    }
}


