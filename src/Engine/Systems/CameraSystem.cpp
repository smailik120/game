#include <list>
#include <string>
#include <iostream>
#include "../Systems/CameraSystem.h"
void CameraSystem::draw(string s, int posX, int posY) {
    for (int i = 0; i < s.length(); i++) {
        posY++;
        addch(s[i]);
        move(posX, posY);
    }
}
void CameraSystem::refreshScreen() {
    refresh();
}
void CameraSystem::clearScreen() {
    clear();
}
void CameraSystem::endwinScreen() {
    endwin();
}
void CameraSystem::update() {
    clear();
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    for (list<Entity>::iterator it = entities->begin(); it != entities->end(); it++) {
        if (validate(&(*it))) {
            Position* pos = static_cast<Position*> ((&(*it))->getComponent("position"));
            move(pos->getX(), pos->getY());
            Sprite* sprite = static_cast<Sprite*> (((&(*it))->getComponent("sprite")));
            addch(sprite->getTexture());
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
    information(20, 26, outScore);
    information(21, 26, outHealth);
    information(22, 26, outDamage);
}
void CameraSystem::screenInventory() {
    clear();
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
    information(posX, posY, "If you want exit press i, if you want change thing that press enter");
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
        information(posX, posY, info);
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
            printw("<-");
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
    information(18, 26, "Do you want take " + entity->getName() + "?");
    information(19, 26, "If you want take this press y else press n");
    int ch = getch();
    while (ch != 121 && ch != 110) {
        ch = getch();
    }
    return ch;
}
void CameraSystem::information(int posX, int posY, string text) {
    move(posX, posY);
    draw(text, posX, posY);
}
bool CameraSystem::validate(Entity* entity) {
    return !(entity->getComponent("position") == NULL || entity->getComponent("sprite") == NULL);
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
        draw(name + " " + record, posX, posY);
    }
    getch();
    clear();
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
void CameraSystem::screenAgain() {
    printw("If you want start again press Button");
    refresh();
    getch();
    clear();
}
void CameraSystem::loose() {
    clear();
    printw("you loose, press button that saw table scores");
    refresh();
    getch();
    clear();
}
