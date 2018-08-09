#include <ncurses.h>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include "../Entity/Engine.h"
Engine* Engine::engine = 0;
Engine::Engine() {
    start();
}
void Engine::update() {
    currentScene->update(this->manager);
}
void Engine::setMapButtonAction(std::map<int, ButtonAction*>* buttonAction) {
    this->buttonAction = buttonAction;
}
void Engine::setCurrentScene(Entity* entity) {
    numberScene++;
    int temp = numberScene;
    list<Scene>::iterator it = scenes->begin();
    while (temp != 1) {
        it++;
        temp--;
    }
    if (entity != NULL) {
        list<Entity>* entities = (*it).getEntities();
    }
    Engine::currentScene = &(*it);
}
void Engine::playAgain() {
    start();
    numberScene = 1;
}
void Engine::setPlayerName(char* name) {
    playerName = name;
}
char* Engine::getPlayerName() {
    return playerName;
}
void Engine::start() {
    LoaderOfFile* loader = new LoaderOfFile();
    Engine::scenes = loader->load("src/Uploaded/Levels/map.tx");
    manager = &loader->manager();
    buttonAction = loader->createButtonAction();
    list<Scene>::iterator it = Engine::scenes->begin();
    currentScene = &scenes->front();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (this->callSystem("camera"));
    playerName = cameraSystem->drawStartScreen();
}
int Engine::getNumberScene() {
    return numberScene;
}
int Engine::getSizeLevels() {
return scenes->size();
}
Scene* Engine::getCurrentScene() {
    return currentScene;
}
Writer<string>* Engine::getWriteToTable() {
    return writerToTable;
}
Reader<string>* Engine::getReadOfTable() {
    return readerOfTable;
}
System* Engine::callSystem(std::string name) {
    return manager->getSystem(name);
}
bool Engine::getExit() {
    return exit;
}
SystemManager* Engine::getSystemManager() {
    return manager;
}
void Engine::end() {
    exit = false;
    clear();
    endwin();
}
void Engine::gameLoop() {
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (this->callSystem("camera"));
    while (true) {
        engine->update();
        if (engine->getExit() == false) {
            break;
        }
        list<Entity>* entities = engine->getCurrentScene()->getEntities();
        refresh();
        int ch = getch();
        refresh();
        while ((*buttonAction)[ch] != NULL) {
            if ((*buttonAction)[ch]->getName() == "move") {
                (*buttonAction)[ch]->Action(&entities->back());
                break;
            } else {
                (*buttonAction)[ch]->Action(&entities->back());
                ch = getch();
            }
            }
        }
        cameraSystem->clearScreen();
    endwin();
}

