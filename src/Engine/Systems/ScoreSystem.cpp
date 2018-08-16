#include <list>
#include <string>
#include "../Systems/ScoreSystem.h"
void ScoreSystem::update() {
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    for (list<Entity>::iterator it = entities->begin(); it != entities->end(); it++) {
        if (validate(&(*it))) {
            Score* score = static_cast<Score*> ((&(*it))->getComponent("score"));
            Health* health = static_cast<Health*> ((&(*it))->getComponent("health"));
            if (score->getScore() <= 0 || health->getHealth() <= 0) {
                CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
                list<string> scores;
                scores = engine->getReadOfTable()->read();
                cameraSystem->drawLooseScreen();
                cameraSystem->drawFinalTable(scores);
                engine->end();
            }
        }
    }
}

bool ScoreSystem::validate(Entity* entity) {
    return !(entity->getComponent("score") == NULL || entity->getComponent("sprite") == NULL);
}