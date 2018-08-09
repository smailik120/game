#ifndef _CAMERASYSTEM_H
#define _CAMERASYSTEM_H
#include <ncurses.h>
#include <string>
#include <list>
#include "../Systems/System.h"
#include "../Entity/Engine.h"
#include "../Components/Camera.h"
#include "../Components/Sprite.h"
#include "../Components/Position.h"
class CameraSystem : public System {
 private:
    Camera* camera;
 public:
    void update();
    void draw(string s, int posX, int posY);
    bool validate(Entity* entity);
    void drawFinalTable(list<string> scores);
    char* drawStartScreen();
    void screenAgain();
    void loose();
    void information(int posX, int posY, string text);
    int putThing(Entity* entity);
    void screenInventory();
    void refreshScreen();
    void clearScreen();
    void endwinScreen();
};
#endif
