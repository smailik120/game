#include "../Loader/LoaderBuilders.h"
map<char, Builder*>* LoaderBuilders::load() {
    map<char, Builder*>* builders = new  map<char, Builder*>();
    BuilderPlayer* builderPlayer = new BuilderPlayer();
    BuilderMoney* builderMoney = new BuilderMoney();
    BuilderFloor* builderFloor = new BuilderFloor();
    BuilderBrick* builderBrick = new BuilderBrick();
    BuilderChest* builderChest = new BuilderChest();
    BuilderTower* builderTower = new BuilderTower();
    BuilderLevel* builderLevel = new BuilderLevel();
    builders->insert(pair<char, Builder*>('@', builderPlayer));
    builders->insert(pair<char, Builder*>('$', builderMoney));
    builders->insert(pair<char, Builder*>('.', builderFloor));
    builders->insert(pair<char, Builder*>('#', builderBrick));
    builders->insert(pair<char, Builder*>('X', builderChest));
    builders->insert(pair<char, Builder*>('E', builderTower));
    builders->insert(pair<char, Builder*>('>', builderLevel));
    return builders;
}