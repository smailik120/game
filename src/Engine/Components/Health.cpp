#include "../Components/Health.h"
Health::Health(int health) {
    this->health = health;
}

void Health::setHealth(int health) {
    this->health = health;
}

int Health::getHealth() {
    return health;
}

bool Health::isDeath() {
    return this->health <= 0;
}