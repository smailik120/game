#include <list>
#include "../Components/Slots.h"
Slots::Slots(list<Entity>* slots) {
    this->slots = slots;
}
list<Entity>* Slots::getSlots() {
    return slots;
}
Entity* Slots::getHelmet() {
    for (list<Entity>::iterator it = slots->begin(); it != slots->end(); it++) {
        if (it->getName() == "helmet") {
            return &(*it);
            break;
        }
    }
    return NULL;
}
Entity* Slots::getArmor() {
    for (list<Entity>::iterator it = slots->begin(); it != slots->end(); it++) {
        if (it->getName() == "armor") {
            return &(*it);
            break;
        }
    }
    return NULL;
}
Entity* Slots::getBridge() {
    for (list<Entity>::iterator it = slots->begin(); it != slots->end(); it++) {
        if (it->getName() == "bridge") {
            return &(*it);
            break;
        }
    }
    return NULL;
}