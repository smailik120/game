#include "../BuildersEntity/BuilderPlayer.h"
Entity* BuilderPlayer::build(int posX, int posY) {
    Entity* player = new Entity();
    player->add("position", new Position(posX, posY));
    player->add("sprite", new Sprite('@'));
    player->add("velocity", new Velocity(1, 1, 1));
    player->add("score", new Score(5));
    player->add("raiting", new Raiting(0));
    player->add("health", new Health(100));
    player->add("damage", new Damage(10));
    player->add("anger", new Anger(-10));
    player->setName("player");
    player->setLayer(10);
    list<Entity>* slots = new list<Entity>;
    list<Entity>* things = new list<Entity>;
    player->add("slots", new Slots(slots));
    player->add("bag", new Bag(things));
    player->add("death", new Death());
    return player;
}