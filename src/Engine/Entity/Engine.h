#ifndef _ENGINE_H
#define _ENGINE_H
#include<list>
#include <map>
#include<iterator>
#include <string>
#include "../Entity/Scene.h"
#include "../../WorkWithFiles/Writer.h"
#include "../../WorkWithFiles/Reader.h"
#include "../../Uploaded/Loader/LoaderOfFile.h"
#include "../ButtonActions/ButtonAction.h"
#include "../ButtonActions/LeftAction.h"
#include "../ButtonActions/UpAction.h"
#include "../ButtonActions/RightAction.h"
#include "../ButtonActions/DownAction.h"
#include "../Systems/SystemManager.h"
class Engine {
 private:
    map<int, ButtonAction*>* buttonAction;
    char* playerName;
    bool exit = true;
    Writer<string>* writerToTable = new Writer<string>("src/Uploaded/Tables/2.txt");
    Reader<string>* readerOfTable = new Reader<string>("src/Uploaded/Tables/2.txt");
    SystemManager *manager;
    list<Scene>* scenes;
    static Engine* engine;
    Engine(const Engine&);
    Engine();
    Engine& operator = (Engine&);

 public:
    Scene* currentScene;
    int numberScene = 1;
    void update();
    void setMapButtonAction(std::map<int, ButtonAction*>* buttonAction);
    void setCurrentScene(Entity *entity);
    void setScene(int temp);
    void setPlayerName(char* name);
    char* getPlayerName();
    Scene* getCurrentScene();
    int getNumberScene();
    int getSizeLevels();
    void playAgain();
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
