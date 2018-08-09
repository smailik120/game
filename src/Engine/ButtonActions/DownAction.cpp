
#include "../Entity/Entity.h"
#include "../ButtonActions/DownAction.h"
#include "../Components/Position.h"
#include "../Components/Velocity.h"
void DownAction::Action(Entity* player) {
    Position* position = static_cast<Position*> (player->getComponent("position"));
    Velocity* velocity = static_cast<Velocity*> (player->getComponent("velocity"));
    Score* score = static_cast<Score*> (player->getComponent("score"));
    velocity->setSpeedY(0);
    velocity->setSpeedX(1);
    position->setX(position->getX() + velocity->getSpeedX());
}
