#include "../Entity/Entity.h"
#include "../ButtonActions/InventoryAction.h"
#include "../Components/Position.h"
#include "../Components/Velocity.h"
void InventoryAction::Action(Entity* player) {
    Engine* engine = Engine::getEngine();
    CameraSystem* cameraSystem = static_cast<CameraSystem*> (engine->callSystem("camera"));
    cameraSystem->screenInventory();
}
