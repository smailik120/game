#ifndef _SYSTEMMANAGER_H
#define _SYSTEMMANAGER_H
#include <map>
#include <string>
#include "../Systems/System.h"
class SystemManager {
 private:
    int priority;
    map<int, System*> systems;
    map<std::string, System*> names;
 public:
    void start();
    void addSystem(std::string name, System* system, int priority);
    void update();
    void removeSystem(System* system, int priority);
    void next();
    bool isEmpty();
    System* getSystem(int priority);
    System* getSystem(std::string name);
};
#endif