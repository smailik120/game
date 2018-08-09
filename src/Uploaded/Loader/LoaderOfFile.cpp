#include <list>
#include <utility>
#include <map>
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include<cstdio>
#include "../Loader/LoaderOfFile.h"
LoaderOfFile::LoaderOfFile() {
}
Entity LoaderOfFile::create(char s, int row, int column) {
    Entity entity;
    if (s == '@') {
        entity.add("position", new Position(row, column));
        entity.add("sprite", new Sprite('@'));
        entity.add("velocity", new Velocity(1, 1, 1));
        entity.add("score", new Score(5));
        entity.add("raiting", new Raiting(0));
        entity.add("health", new Health(100));
        entity.add("damage", new Damage(10));
        entity.add("anger", new Anger(-10));
        entity.setName("player");
        entity.setLayer(10);
        list<Entity>* slots = new list<Entity>;
        list<Entity>* things = new list<Entity>;
        entity.add("slots", new Slots(slots));
        entity.add("bag", new Bag(things));
        entity.add("death", new Death());
    }
    if (s == '.') {
        entity.add("position", new Position(row, column));
        entity.add("sprite", new Sprite('.'));
        entity.setName("floor");
        entity.setLayer(0);
    }
    if (s == '#') {
        entity.add("position", new Position(row, column));
        entity.add("sprite", new Sprite('#'));
        entity.setName("brick");
        entity.setLayer(1);
    }
    if (s == '>') {
        entity.add("position", new Position(row, column));
        entity.add("sprite", new Sprite('>'));
        entity.setName("up");
        entity.setLayer(1);
    }
    if (s == 'T') {
        entity.add("position", new Position(row, column));
        entity.add("sprite", new Sprite('T'));
        entity.add("score", new Score(5));
        entity.add("velocity", new Velocity(0, 0, 1));
        entity.add("anger", new Anger(2));
        entity.add("health", new Health(10));
        entity.add("damage", new Damage(10));
        entity.setName("tower");
        entity.setLayer(10);
        list<Entity>* things = new list<Entity>;
        Entity helmet;
        Entity armor;
        Entity bridge;
        helmet.add("health", new Health(10));
        helmet.add("sprite", new Sprite('h'));
        helmet.setName("helmet");
        helmet.setLayer(1);
        helmet.add("death", new Death());
        armor.add("health", new Health(10));
        armor.add("sprite", new Sprite('a'));
        armor.setName("armor");
        armor.setLayer(1);
        armor.add("death", new Death());
        bridge.add("health", new Health(10));
        bridge.add("sprite", new Sprite('b'));
        bridge.setName("bridge");
        bridge.setLayer(1);
        bridge.add("death", new Death());
        things->push_back(bridge);
        things->push_back(armor);
        things->push_back(helmet);
        entity.add("bag", new Bag(things));
        entity.add("death", new Death());
    }
    if (s == '$') {
        entity.add("death", new Death());
        entity.add("position", new Position(row, column));
        entity.add("sprite", new Sprite('$'));
        entity.add("score", new Score(5));
        entity.add("health", new Health(1));
        entity.setName("money");
        entity.setLayer(1);
    }
    return entity;
}
map<int, ButtonAction*>* LoaderOfFile::createButtonAction() {
    map<int, ButtonAction*>* buttonAction = new  map<int, ButtonAction*>();
    UpAction* up = new UpAction();
    up->setName("move");
    DownAction* down = new DownAction();
    down->setName("move");
    LeftAction* left = new LeftAction();
    left->setName("move");
    RightAction* right = new RightAction();
    right->setName("move");
    buttonAction->insert(pair<int, ButtonAction*>(w, up));
    buttonAction->insert(pair<int, ButtonAction*>(a, left));
    buttonAction->insert(pair<int, ButtonAction*>(s, down));
    buttonAction->insert(pair<int, ButtonAction*>(d, right));
    return buttonAction;
}
SystemManager& LoaderOfFile::manager() {
    systemManager = new SystemManager();
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

list<Scene>* LoaderOfFile::load(string path) {
    list<Entity>* entities = new list<Entity>;
    list<Scene>* scenes = new list<Scene>;
    int levels;
    int currentLevelName = 0;
    ifstream fin(path);
    fin >> levels;
    for (int k = 1; k <= levels; k++) {
        char currentEntity;
        int rows, columns;
        fin >> rows >> columns;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= columns; j++) {
                fin >> currentEntity;
                if (currentEntity != '@') {
                    Entity entity = create(currentEntity, i, j);
                    Entity floor = create('.', i, j);
                    entities->push_back(floor);
                    entities->push_front(entity);
                } else {
                    Entity entity = create(currentEntity, i, j);
                    Entity floor = create('.', i, j);
                    entities->push_back(floor);
                    entities->push_back(entity);
                }
            }
        }
        currentLevelName++;
        Scene* scene = new Scene(entities, "src/Uploaded/Tables/"+to_string(currentLevelName)+".txt");
        scenes->push_back(*scene);
        entities = new list<Entity>;
    }
    fin.close();
    fin.clear();
    return scenes;
}
