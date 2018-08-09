#include <list>
#include "../Entity/Entity.h"
#include "../Components/Component.h"
#ifndef _SLOTS_H
#define _SLOTS_H
class Slots : public Component {
 private:
    list<Entity>* slots;
 public:
    explicit Slots(list<Entity>* slots);
    list<Entity>* getSlots();
    Entity* getHelmet();
    Entity* getArmor();
    Entity* getBridge();
};
#endif