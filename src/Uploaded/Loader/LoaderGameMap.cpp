#include <list>
#include <utility>
#include <map>
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include<cstdio>
#include "../Loader/LoaderGameMap.h"
LoaderGameMap::LoaderGameMap(map<char, Builder*>* builder) {
    this->builder = builder;
}

Entity LoaderGameMap::create(char s, int row, int column) {
    return *(*builder)[s]->build(row, column);
}

list<Scene>* LoaderGameMap::load(string path) {
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
        Scene* scene = new Scene(entities, "Tables/"+to_string(currentLevelName)+".txt");
        scenes->push_back(*scene);
        entities = new list<Entity>;
    }
    fin.close();
    fin.clear();
    return scenes;
}
