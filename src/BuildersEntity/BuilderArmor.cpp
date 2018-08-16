#include "../BuildersEntity/BuilderArmor.h"
Entity* BuilderArmor::build(int posX, int posY) {
    Entity* armor = new Entity();
    armor->setName("armor");
    armor->setLayer(1);
    armor->add("health", new Health(10));
    armor->add("sprite", new Sprite('a'));
    armor->add("death", new Death());
    armor->add("active", new Active());
    return armor;
}