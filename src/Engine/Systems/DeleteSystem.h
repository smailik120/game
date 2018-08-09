#ifndef _DELETESYSTEM_H
#define _DELETESYSTEM_H
#include <ncurses.h>
#include "../Systems/System.h"
#include "../Entity/Engine.h"
#include "../Components/Sprite.h"
#include "../Components/Position.h"
class DeleteSystem : public System {
 private:
    void update();
    bool validate(Entity* entity);
};
#endif