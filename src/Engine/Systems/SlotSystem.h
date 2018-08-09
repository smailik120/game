#ifndef _SLOTSYSTEM_H
#define _SLOTSYSTEM_H
#include <unistd.h>
#include <ncurses.h>
#include "../Entity/Engine.h"
#include "../Systems/System.h"
#include "../Components/Sprite.h"
#include "../Components/Position.h"
#include "../Components/Slots.h"
class SlotSystem : public System {
 private:
    void update();
    bool validate(Entity* entity);
};
#endif