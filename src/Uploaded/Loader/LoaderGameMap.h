#ifndef _LOADEROFFILE_H
#define _LOADEROFFILE_H
#include <list>
#include <string>
#include <cstring>
#include <utility>
#include <map>
#include <cstdlib>
#include "../../Engine/Systems/CameraSystem.h"
#include "../../Engine/Systems/MoveSystem.h"
#include "../../Engine/Systems/ScoreSystem.h"
#include "../../Engine/Entity/Scene.h"
#include "../../Engine/Systems/DeleteSystem.h"
#include "../../Engine/Systems/SlotSystem.h"
#include "../../Engine/Systems/DropSystem.h"
#include "../../Engine/Components/Raiting.h"
#include "../../Engine/Components/Position.h"
#include "../../Engine/Components/Death.h"
#include "../../Engine/Components/Slots.h"
#include "../../Engine/Components/Health.h"
#include "../../Engine/Components/Damage.h"
#include "../../Engine/Components/Sprite.h"
#include "../../Engine/Components/Bag.h"
#include "../../Engine/Components/Active.h"
#include "../../Engine/Components/Anger.h"
#include "../../Engine/Systems/SystemManager.h"
#include "../../Engine/ButtonActions/ButtonAction.h"
#include "../../Engine/Components/Velocity.h"
#include "../../Engine/ButtonActions/UpAction.h"
#include "../../Engine/ButtonActions/LeftAction.h"
#include "../../Engine/ButtonActions/DownAction.h"
#include "../../Engine/ButtonActions/RightAction.h"
#include "../../Engine/ButtonActions/InventoryAction.h"
#include "../../Engine/InventoryActions/WeaponAction.h"
#include "../../Engine/Collisions/Collision.h"
#include "../../BuildersEntity/BuilderHelmet.h"
class LoaderGameMap {
 private:
    Entity create(char s, int row, int column);
 public:
    map<char, Builder*>* builder;                                                                                                           
    LoaderGameMap(map<char, Builder*>* builder);
    list<Scene>* load(string path);
    Scene scene;
};
#endif
