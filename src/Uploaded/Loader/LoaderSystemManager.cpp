#include "../Loader/LoaderSystemManager.h"
SystemManager& LoaderSystemManager::load() {
    SystemManager* systemManager = new SystemManager();
    MoveSystem* move = new MoveSystem;
    CameraSystem* camera = new CameraSystem;
    systemManager->addSystem("camera", camera, 5);
    systemManager->addSystem("move", move, 0);
    systemManager->addSystem("score", new DropSystem, 1);
    systemManager->addSystem("delete", new DeleteSystem, 3);
    systemManager->addSystem("slot", new SlotSystem, 2);
    systemManager->addSystem("score", new ScoreSystem, 4);
    return *systemManager;
}