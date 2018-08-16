#include "../BuildersEntity/BuilderLevel.h"
Entity* BuilderLevel::build(int posX, int posY) {
    Entity* level = new Entity();
    level->setName("up");
    level->add("position", new Position(posX, posY));
    level->setLayer(1);
    level->add("sprite", new Sprite('>'));
    return level;
}