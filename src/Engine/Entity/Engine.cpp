#include <ncurses.h>
#include <list>
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
    list<Scene>::iterator it = Engine::scenes->begin();
    currentScene = &scenes->front();
    CameraSystem* camerSystem = static_cast<CameraSystem*> (this->callSystem("camera"));
    playerName = camerSystem->drawStartScreen();
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

