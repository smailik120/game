#include "../Components/Damage.h"
Damage::Damage(int damage) {
    this->damage = damage;
}

void Damage::setDamage(int damage) {
    this->damage = damage;
}

int Damage::getDamage() {
    return damage;
}