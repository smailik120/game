#include "../BuildersEntity/BuilderPants.h"
Entity* BuilderPants::build(int posX, int posY) {
    Entity* pants = new Entity();
    pants->setName("pants");
    pants->setLayer(1);
    pants->add("health", new Health(10));
    pants->add("sprite", new Sprite('p'));
    pants->add("death", new Death());
    pants->add("active", new Active());
    return pants;
}