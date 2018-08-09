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
    string outScore = "Score:" + to_string(currentScore);
    string outHealth = "Health:" + to_string(currentHealth);
    information(20, 26, outScore);
    information(21, 26, outHealth);
}
void CameraSystem::screenInventory() {
    clear();
    int posX = 0;
    int posY = 0;
    const int i = 105;
    Engine* engine = Engine::getEngine();
    list<Entity>* entities = engine->getCurrentScene()->getEntities();
    Entity player = entities->back();
    Bag* bag = static_cast<Bag*> (player.getComponent("bag"));
    list<Entity>* listBag = bag->getThings();
    for (list<Entity>::iterator it = listBag->begin(); it != listBag->end(); it++) {
        string damageThing = "";
        string healthThing = "";
        if (it->getComponent("health") != NULL) {
            Health* health = static_cast<Health*> (it->getComponent("health"));
            information(posX, posY, it->getName() + " health: " + to_string(health->getHealth()));
        }
        posX++;
    }
    information(posX, posY, "If you want exit press i");
    refresh();
    while (getch() != i) {
    }
    this->update();
}
int CameraSystem::putThing(Entity* entity) {
    information(18, 26, "Do you want put " + entity->getName() + "?");
    information(19, 26, "If you want put this press y else press n");
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
