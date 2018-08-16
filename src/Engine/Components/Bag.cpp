#include <list>
#include "../Components/Bag.h"
Bag::Bag(list<Entity>* things) {
    this->things = things;
}

list<Entity>* Bag::getThings() {
    return things;
}

Entity* Bag::getThingByNumber(int number) {
    int currentNumber = 0;
    for (list<Entity>::iterator it = things->begin(); it != things->end(); it++) {
        currentNumber++;
        if (currentNumber == number) {
            return &(*it);
        }
    }
    return NULL;
}
