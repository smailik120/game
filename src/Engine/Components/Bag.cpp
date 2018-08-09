#include <list>
#include "../Components/Bag.h"
Bag::Bag(list<Entity>* things) {
    this->things = things;
}
list<Entity>* Bag::getThings() {
    return things;
}