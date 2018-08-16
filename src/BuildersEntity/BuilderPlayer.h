#ifndef _BUILDERPLAYER_H
#define _BUILDERPLAYER_H
#include <string>
#include "../BuildersEntity/Builder.h"
#include "../Engine/Components/Position.h"
#include "../Engine/Components/Score.h"
#include "../Engine/Components/Sprite.h"
#include "../Engine/Components/Active.h"
#include "../Engine/Components/Health.h"
#include "../Engine/Components/Damage.h"
#include "../Engine/Components/Death.h"
#include "../Engine/Components/Slots.h"
#include "../Engine/Components/Anger.h"
#include "../Engine/Components/Raiting.h"
#include "../Engine/Components/Bag.h"
#include "../Engine/Components/Velocity.h"
#include "../Engine//Entity/Entity.h"
class BuilderPlayer : public Builder {
 public:
    Entity* build(int posX, int posY);
};
#endif