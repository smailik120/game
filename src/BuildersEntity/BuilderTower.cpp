#include "../BuildersEntity/BuilderTower.h"
Entity* BuilderTower::build(int posX, int posY) {
    Entity* tower = new Entity();
    Entity helmet = *builderHelmet->build(posX, posY);
    Entity armor = *builderArmor->build(posX, posY);
    Entity pants = *builderPants->build(posX, posY);
    Entity weapon = *builderWeapon->build(posX, posY);
    tower->add("score", new Score(5));
    tower->add("velocity", new Velocity(0, 0, 1));
    tower->add("anger", new Anger(2));
    tower->add("health", new Health(30));
    tower->add("damage", new Damage(10));
    tower->add("position", new Position(posX, posY));
    tower->add("sprite", new Sprite('E'));
    tower->add("death", new Death());
    tower->setName("tower");
    tower->setLayer(2);
    list<Entity>* things = new list<Entity>;
    things->push_back(helmet);
    things->push_back(armor);
    things->push_back(pants);
    things->push_back(weapon);
    tower->add("bag", new Bag(things));
    return tower;
}