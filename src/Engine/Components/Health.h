#include "../Components/Component.h"
#ifndef _HEALTH_H
#define _HEALTH_H
class Health : public Component {
 private:
    int health;
 public:
    explicit Health(int health);
    void setHealth(int health);
    int getHealth();
    bool isDeath();
};
#endif