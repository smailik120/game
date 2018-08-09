#ifndef _GENERATESYSTEM_H
#define _GENERATESYSTEM_H
#include <ncurses.h>
#include "../Systems/System.h"
#include "../Entity/Engine.h"
#include "../Components/Sprite.h"
#include "../Components/Position.h"
class GenerateSystem : public System {
 private:
    void update();
    bool validate(Entity* entity);
};
#endif