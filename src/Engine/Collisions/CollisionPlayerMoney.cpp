
#include "../Collisions/CollisionPlayerMoney.h"
void CollisionPlayerMoney::Action(Entity* player, Entity* money) {
        Score* scorePlayer = static_cast<Score*> (player->getComponent("score"));
        Score* scoreMoney = static_cast<Score*> (money->getComponent("score"));
        Death* death = static_cast<Death*> (money->getComponent("death"));
        if (scoreMoney->getScore() > 0)
            scorePlayer->setScore(scoreMoney->getScore() + scorePlayer->getScore());
        death->setDeath(true);
}
