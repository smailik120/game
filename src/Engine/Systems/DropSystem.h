#ifndef _DROPSYSTEM_H
#define _DROPSYSTEM_H
#include <ncurses.h>
#include "../Systems/System.h"
#include "../Entity/Engine.h"
#include "../Components/Sprite.h"
#include "../Components/Position.h"
#include "../Components/Bag.h"
class DropSystem : public System {
 private:
    void update();
    bool validate(Entity* entity);
};
#endif