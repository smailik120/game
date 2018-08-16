#include "../BuildersEntity/BuilderFloor.h"
Entity* BuilderFloor::build(int posX, int posY) {
    Entity* floor = new Entity();
    floor->add("position", new Position(posX, posY));
    floor->add("sprite", new Sprite('.'));
    floor->setName("floor");
    floor->setLayer(0);
    return floor;
}