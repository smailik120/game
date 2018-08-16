#ifndef _ENGINE_H
#define _ENGINE_H
#include<list>
#include <map>
#include<iterator>
#include <string>
#include "../InventoryActions/HelmetAction.h"
#include "../InventoryActions/BridgeAction.h"
#include "../InventoryActions/ArmorAction.h"
#include "../Entity/Scene.h"
#include "../Components/Health.h"
#include "../../WorkWithFiles/Writer.h"
#include "../../WorkWithFiles/Reader.h"
#include "../../Uploaded/Loader/LoaderGameMap.h"
#include "../../Uploaded/Loader/LoaderCollisions.h"
#include "../../Uploaded/Loader/LoaderBuilders.h"
#include "../../Uploaded/Loader/LoaderButtons.h"
#include "../../Uploaded/Loader/LoaderSystemManager.h"
#include "../../Uploaded/Loader/LoaderInventoryActions.h"
#include "../../Uploaded/Loader/LoaderReaderRecords.h"
#include "../../Uploaded/Loader/LoaderWriterRecords.h"
#include "../ButtonActions/ButtonAction.h"
#include "../ButtonActions/LeftAction.h"
#include "../ButtonActions/UpAction.h"
#include "../ButtonActions/RightAction.h"
#include "../ButtonActions/DownAction.h"
#include "../Systems/SystemManager.h"
class Engine {
 private:
    map<int, ButtonAction*>* buttonAction;
    map<string, Collision*>* inventoryAction;
    char* playerName;
    bool exit = true;
    SystemManager *manager;
    list<Scene>* scenes;
    static Engine* engine;
    Engine(const Engine&);
    Engine();

 public:
    Writer<string>* writerToTable;
    Reader<string>* readerOfTable;
    Scene* currentScene;
    int numberScene = 1;
    std::map<pair<string, string>, Collision*>* collisionAction;
    std::map<char, Builder*>* builders;
    void update();
    std::map<string, Collision*>* getMapActionsInventory();
    std::map<pair<string, string>, Collision*>* getMapCollisions();
    void setCurrentScene(Entity *entity);
    void setScene(int temp);
    void setPlayerName(char* name);
    char* getPlayerName();
    Scene* getCurrentScene();
    int getNumberScene();
    int getSizeLevels();
    void start();
    static Engine* getEngine() {
        if ( !engine )
            engine = new Engine();
        return engine;
    }
    System* callSystem(std::string name);
    Writer<string>* getWriteToTable();
    Reader<string>* getReadOfTable();
    void end();
    bool getExit();
    SystemManager* getSystemManager();
    void gameLoop();
};
#endif
