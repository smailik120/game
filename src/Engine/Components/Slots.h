#include <list>
#include <string>
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
    Entity* getPants();
    Entity* getWeapon();
    void eraseByName(std::string name);
};
#endif