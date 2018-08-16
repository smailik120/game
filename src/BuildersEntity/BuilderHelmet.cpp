
#include "../BuildersEntity/BuilderHelmet.h"
Entity* BuilderHelmet::build(int posX, int posY) {
    Entity* helmet = new Entity();
    helmet->setName("helmet");
    helmet->setLayer(1);
    helmet->add("health", new Health(10));
    helmet->add("sprite", new Sprite('h'));
    helmet->add("death", new Death());
    helmet->add("active", new Active());
    return helmet;
}
