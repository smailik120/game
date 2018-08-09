
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <typeinfo>
#include <map>
#include <list>
#include <iostream>
#include <utility>
#include "../WorkWithFiles/Reader.h"
#include "../WorkWithFiles/Writer.h"
#include "../Engine/Components/Component.h"
#include "../Engine/Components/Position.h"
#include "../Engine/Components/Velocity.h"
#include "../Engine/Components/Sprite.h"
#include "../Engine/Components/Raiting.h"
#include "../Engine/Components/Score.h"
#include "../Engine/Systems/SystemManager.h"
#include "../Engine/Entity/Entity.h"
#include "../Uploaded/Loader/LoaderOfFile.h"
#include "../Engine/Entity/Engine.h"
#include "../Engine/Entity/Scene.h"
#include "../Engine/Collisions/CollisionPlayerLevel.h"
#include "../Engine/Collisions/CollisionPlayerBrick.h"
#include "../Engine/Collisions/CollisionPlayerMoney.h"
#include "../Engine/Systems/MoveSystem.h"
#include "../Engine/Systems/CameraSystem.h"
#include "../Engine/Systems/DeleteSystem.h"
#include "../Engine/Systems/ScoreSystem.h"
#include "../Engine/ButtonActions/UpAction.h"
#include "../Engine/ButtonActions/LeftAction.h"
#include "../Engine/ButtonActions/DownAction.h"
#include "../Engine/ButtonActions/RightAction.h"
int main(int argc, char* argv[]) {
    map<int, ButtonAction*> buttonAction;
    buttonAction.insert(pair<int, ButtonAction*>(119, new UpAction));
    buttonAction.insert(pair<int, ButtonAction*>(97, new LeftAction));
    buttonAction.insert(pair<int, ButtonAction*>(115, new DownAction));
    buttonAction.insert(pair<int, ButtonAction*>(100, new RightAction));
    int i = 0;
    initscr();
    keypad(stdscr, true);
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    while (true) {
        engine->update();
        if (engine->getExit() == false) {
            break;
        }
        list<Entity>* entities = engine->getCurrentScene()->getEntities();
        refresh();
        int ch = getch();
        refresh();
        if (buttonAction[ch] != NULL) {
            buttonAction[ch]->Action(&entities->back());
        }
        clear();
    }
    endwin();
    return 0;
}
