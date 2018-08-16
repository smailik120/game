#include "../BuildersEntity/BuilderChest.h"
Entity* BuilderChest::build(int posX, int posY) {
    Entity* chest = new Entity();
    Entity helmet = *builderHelmet->build(posX, posY);
    chest->add("position", new Position(posX, posY));
    chest->add("sprite", new Sprite('X'));
    chest->add("death", new Death());
    chest->setName("chest");
    chest->setLayer(2);
    list<Entity>* things = new list<Entity>;
    things->push_back(helmet);
    chest->add("bag", new Bag(things));
    return chest;
}