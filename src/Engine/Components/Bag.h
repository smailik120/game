#include <list>
#include "../Entity/Entity.h"
#include "../Components/Component.h"
#ifndef _BAG_H
#define _BAG_H
class Bag : public Component {
 private:
    list<Entity>* things;
 public:
    explicit Bag(list<Entity>* things);
    list<Entity>* getThings();
    Entity* getThingByNumber(int number);
};
#endif