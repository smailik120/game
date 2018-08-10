#ifndef _WEAPONACTION_H
#define _WEAPONACTION_H
#include "../Entity/Entity.h"
#include "../Components/Damage.h"
#include "../Collisions/Collision.h"
#include "../Components/Position.h"
#include "../Components/Active.h"
#include "../Components/Score.h"
#include "../Components/Health.h"
#include "../Systems/CameraSystem.h"
#include "../Systems/SlotSystem.h"
#include "../Components/Slots.h"
#include "../Components/Bag.h"
class WeaponAction : public Collision {
 public:
    void Action(Entity* player, Entity* thing);
};
#endif