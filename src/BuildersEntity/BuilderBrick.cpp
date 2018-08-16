#include "../BuildersEntity/BuilderBrick.h"
Entity* BuilderBrick::build(int posX, int posY) {
    Entity* brick = new Entity();
    brick->add("position", new Position(posX, posY));
    brick->add("sprite", new Sprite('#'));
    brick->setName("brick");
    brick->setLayer(1);
    return brick;
}