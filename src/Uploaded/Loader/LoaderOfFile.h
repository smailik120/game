#ifndef _LOADEROFFILE_H
#define _LOADEROFFILE_H
#include <list>
#include <string>
#include <cstring>
#include <cstdlib>
#include "../../Engine/Systems/CameraSystem.h"
#include "../../Engine/Systems/MoveSystem.h"
#include "../../Engine/Systems/ScoreSystem.h"
#include "../../Engine/Entity/Scene.h"
#include "../../Engine/Systems/DeleteSystem.h"
#include "../../Engine/Systems/GenerateSystem.h"
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
#include "../../Engine/Components/Velocity.h"
class LoaderOfFile {
 private:
    Entity create(char s, int row, int column);
 public:
    SystemManager* systemManager;
    LoaderOfFile();
    list<Scene>* load(string path);
    SystemManager& manager();
    Scene scene;
};
#endif
