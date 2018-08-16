#ifndef _BUILDERTOWER_H
#define _BUILDETOWER_H
#include <string>
#include "../BuildersEntity/Builder.h"
#include "../BuildersEntity/BuilderArmor.h"
#include "../BuildersEntity/BuilderWeapon.h"
#include "../BuildersEntity/BuilderHelmet.h"
#include "../BuildersEntity/BuilderPants.h"
#include "../Engine/Components/Position.h"
#include "../Engine/Components/Score.h"
#include "../Engine/Components/Sprite.h"
#include "../Engine/Components/Active.h"
#include "../Engine/Components/Anger.h"
#include "../Engine/Components/Health.h"
#include "../Engine/Components/Damage.h"
#include "../Engine/Components/Death.h"
#include "../Engine/Components/Slots.h"
#include "../Engine/Components/Bag.h"
#include "../Engine/Components/Velocity.h"
#include "../Engine//Entity/Entity.h"
class BuilderTower : public Builder {
 public:
    BuilderHelmet* builderHelmet = new BuilderHelmet();
    BuilderArmor* builderArmor = new BuilderArmor();
    BuilderPants* builderPants = new BuilderPants();
    BuilderWeapon* builderWeapon = new BuilderWeapon();
    Entity* build(int posX, int posY);
};
#endif