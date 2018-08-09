#ifndef _SCORESYSTEM_H
#define _SCORESYSTEM_H
#include <unistd.h>
#include <ncurses.h>
#include "../Entity/Engine.h"
#include "../Systems/System.h"
#include "../Components/Sprite.h"
#include "../Components/Position.h"
class ScoreSystem : public System {
 private:
    void update();
    bool validate(Entity* entity);
};
#endif