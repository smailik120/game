#include "../Components/Component.h"
#ifndef _DAMAGE_H
#define _DAMAGE_H
class Damage : public Component {
 private:
    int damage;
 public:
    explicit Damage(int damage);
    void setDamage(int damage);
    int getDamage();
};
#endif