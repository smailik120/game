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
    void drawText(string s, int posX, int posY);
    bool validate(Entity* entity);
    void drawFinalTable(list<string> scores);
    char* drawStartScreen();
    void drawSymbol(char s, int posX, int posY);
    void drawLooseScreen();
    int putThing(Entity* entity);
    void screenInventory();
    void endGame();
    void clearScreen();
    void refreshScreen();
    void drawWindow(int posX, int posY, int sizeX, int sizeY,string name);
};
#endif
