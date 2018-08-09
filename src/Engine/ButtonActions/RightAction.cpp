
#include "../Entity/Entity.h"
#include "../ButtonActions/RightAction.h"
#include "../Components/Position.h"
#include "../Components/Velocity.h"
void RightAction::Action(Entity* player) {
    Position* position = static_cast<Position*> (player->getComponent("position"));
    Velocity* velocity = static_cast<Velocity*> (player->getComponent("velocity"));
    Score* score = static_cast<Score*> (player->getComponent("score"));
    velocity->setSpeedY(1);
    velocity->setSpeedX(0);
    position->setY(position->getY() + velocity->getSpeedY());
}