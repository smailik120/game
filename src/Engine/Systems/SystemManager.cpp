#include <utility>
#include <map>
#include <string>
#include "../Systems/SystemManager.h"
    void SystemManager::start() {
        this->priority = 0;
    }
    void SystemManager::addSystem(std::string name, System* system, int priority) {
        systems.insert(pair<int, System*>(priority, system));
        names.insert(pair<std::string, System*>(name, system));
    }
    void SystemManager::update() {
        System* system = systems[priority];
        system->update();
    }
    void SystemManager::removeSystem(System* system, int priority) {
        systems.erase(priority);
    }
    void SystemManager::next() {
        priority++;
    }
    bool SystemManager::isEmpty() {
        return systems.size() == priority;
    }
    System* SystemManager::getSystem(int priority) {
        System* system = systems[priority];
        return system;
    }
    System* SystemManager::getSystem(std::string name) {
        System* system = names[name];
        return system;
    }