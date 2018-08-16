#include "../BuildersEntity/BuilderMoney.h"
Entity* BuilderMoney::build(int posX, int posY) {
    Entity* money = new Entity();
    money->add("death", new Death());
    money->add("position", new Position(posX, posY));
    money->add("sprite", new Sprite('$'));
    money->add("score", new Score(5));
    money->add("health", new Health(1));
    money->setName("money");
    money->setLayer(1);
    return money;
}