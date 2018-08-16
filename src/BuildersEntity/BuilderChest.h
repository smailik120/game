#ifndef _BUILDERCHEST_H
#define _BUILDERCHEST_H
#include <string>
#include "../BuildersEntity/Builder.h"
#include "../BuildersEntity/BuilderHelmet.h"
#include "../Engine/Components/Position.h"
#include "../Engine/Entity/Engine.h"
#include "../Engine/Components/Score.h"
#include "../Engine/Components/Sprite.h"
#include "../Engine/Components/Active.h"
#include "../Engine/Components/Health.h"
#include "../Engine/Components/Damage.h"
#include "../Engine/Components/Death.h"
#include "../Engine/Components/Slots.h"
#include "../Engine/Components/Bag.h"
#include "../Engine/Components/Velocity.h"
#include "../Engine//Entity/Entity.h"
class BuilderChest : public Builder {
 public:
    BuilderHelmet* builderHelmet = new BuilderHelmet();
    Entity* build(int posX, int posY);
};
#endif