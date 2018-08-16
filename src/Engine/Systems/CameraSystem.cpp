#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <string>
#include <iostream>
#include "../Systems/CameraSystem.h"
void CameraSystem::drawText(string s, int posX, int posY) {
    for (int i = 0; i < s.length(); i++) {
        drawSymbol(s[i], posX, posY);
        posY++;
    }
}

void CameraSystem::drawSymbol(char s, int posX, int posY) {
    move(posX, posY);
    addch(s);
}
void CameraSystem::update() {
    drawWindow(18, 24, 15, 5, "Info");
    drawWindow(18, 40, 15, 5, "Log");
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    for (list<Entity>::iterator it = entities->begin(); it != entities->end(); it++) {
        if (validate(&(*it))) {
            Position* pos = static_cast<Position*> ((&(*it))->getComponent("position"));
            Sprite* sprite = static_cast<Sprite*> (((&(*it))->getComponent("sprite")));
            drawSymbol(sprite->getTexture(), pos->getX(), pos->getY());
        }
    }
    Score* score = static_cast<Score*> ((entities->back()).getComponent("score"));
    int currentScore = score->getScore();
    Health* health = static_cast<Health*> ((entities->back()).getComponent("health"));
    int currentHealth = health->getHealth();
    Damage* damage = static_cast<Damage*> ((entities->back()).getComponent("damage"));
    int currentDamage = damage->getDamage();
    string outScore = "Score:" + to_string(currentScore);
    string outHealth = "Health:" + to_string(currentHealth);
    string outDamage = "Damage:" + to_string(currentDamage);
    drawText(outScore, 20, 26);
    drawText(outHealth, 21, 26);
    drawText(outDamage, 22, 26);
    
}

void CameraSystem::screenInventory() {
    int posX = 0;
    int posY = 0;
    const int i = 105;
    const int up = 258;
    const int down = 259;
    const int enter = 10;
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    Entity* player = &entities->back();
    Bag* bag = static_cast<Bag*> (player->getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    Slots* slot = static_cast<Slots*> (player->getComponent("slots"));
    list<Entity>* listSlots = slot->getSlots();
    drawText("If you want exit press i, if you want change thing that press enter", posX, posY);
    posX++;
    for (list<Entity>::iterator it = listBag->begin(); it != listBag->end(); it++) {
        string info = "";
        if (it->getComponent("health") != NULL) {
            Health* health = static_cast<Health*> (it->getComponent("health"));
            info = info + it->getName() + " " + "health" + " " + to_string(health->getHealth());
        }
        if (it->getComponent("damage") != NULL) {
            Damage* damage = static_cast<Damage*> (it->getComponent("damage"));
            info = info + it->getName() + " " + "damage" + " " + to_string(damage->getDamage());
        }
        if (it->getComponent("active") != NULL) {
            Active* active = static_cast<Active*> (it->getComponent("active"));
            if (active->getActive() == true) {
                 info = info + " this thing is equip";
            }
        }
        drawText(info, posX, posY);
        posX++;
    }
    refresh();
    posX = 0;
    posY = 48;
    move(posX, posY);
    int ch = getch();
    while (ch != i) {
        if(ch == up){
            posX++;
            move(posX, posY);
        }
        if (ch == down) {
            posX--;
            move(posX, posY);
        }
        if (ch == enter) {
            Entity* entity = bag->getThingByNumber(posX);
            std::map<string, Collision*>* actions = engine->getMapActionsInventory();
            if (entity != NULL) { 
                (*actions)[entity->getName()]->Action(player, entity);
            }
            break;
        }
        ch = getch();
        refresh();
    }
    this->update();
}

int CameraSystem::putThing(Entity* entity) {
    drawText("Do you want take " + entity->getName() + "?", 18, 26);
    drawText("If you want take this press y else press n", 19, 26);
    int ch = getch();
    while (ch != 121 && ch != 110) {
        ch = getch();
    }
    return ch;
}

bool CameraSystem::validate(Entity* entity) {
    return !(entity->getComponent("position") == NULL || entity->getComponent("sprite") == NULL);
}

void CameraSystem::drawWindow(int posX, int posY, int sizeX, int sizeY, string name) {
    drawText(name , posX + 1, posY + 1);
    int tempX = 0;
    int tempY = 1;
    string up = "";
    while(tempX != sizeX) {
        up = up + "-";
        tempX++;
    }
    tempX = 1;
    drawText(up, posX, posY);
    drawText(up, posX + sizeY, posY);
    while(tempX != sizeY) {
        drawSymbol('|', tempX + posX,posY);
        tempX++;
    }
    tempX = 1;
    while(tempX != sizeY) {
        drawSymbol('|', tempX + posX, posY + sizeX - 1);
        tempX++;
    }
    refresh();
}

void CameraSystem::drawFinalTable(list<string> scores) {
    clear();
    printw("Table scores");
    int posX = 0;
    int posY = 0;
    for (std::list<string>::iterator it = scores.begin(); it !=scores.end(); it++) {
        posX++;
        move(posX, posY);
        string name = *it;
        it++;
        string record = *it;
        drawText(name + " " + record, posX, posY);
    }
    getch();
    posX++;
    move(posX, posY);
    printw("press button that exit");
    refresh();
}

char* CameraSystem::drawStartScreen() {
    printw("Enter your name");
    move(1, 0);
    char* name = new char[20];
    getstr(name);
    clear();
    noecho();
    return name;
}

void CameraSystem::drawLooseScreen() {
    clear();
    printw("you loose, press button that saw table scores");
    refresh();
    getch();
    clear();
}

void CameraSystem::clearScreen() {
    clear();
}

void CameraSystem::refreshScreen() {
    refresh();
}

void endGame() {
    endwin();
}
