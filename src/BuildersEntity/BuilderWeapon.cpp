#include "../BuildersEntity/BuilderWeapon.h"
Entity* BuilderWeapon::build(int posX, int posY) {
    Entity* weapon = new Entity();
    weapon->setName("weapon");
    weapon->setLayer(1);
    weapon->add("damage", new Damage(10));
    weapon->add("sprite", new Sprite('p'));
    weapon->add("death", new Death());
    weapon->add("active", new Active());
    return weapon;
}