#include "../Components/Component.h"
#ifndef _DEATH_H
#define _DEATH_H
class Death : public Component {
 private:
    bool death = false;
 public:
    void setDeath(bool death);
    bool getDeath();
};
#endif