
#include "../Collisions/CollisionPlayerMoney.h"
void CollisionPlayerMoney::Action(Entity* player, Entity* money) {
        Score* scorePlayer = static_cast<Score*> (player->getComponent("score"));
        Score* scoreMoney = static_cast<Score*> (money->getComponent("score"));
        Death* death = static_cast<Death*> (money->getComponent("death"));
        if (scoreMoney->getScore() > 0)
            scorePlayer->setScore(scoreMoney->getScore() + scorePlayer->getScore());
        Engine* engine = Engine::getEngine();
        CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
        pair<int, int>* coordinates = cameraSystem->log;
        engine->logs->push_front("The player took money");
        death->setDeath(true);
}
