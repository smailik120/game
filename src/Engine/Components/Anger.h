#include "../Components/Component.h"
#ifndef _ANGER_H
#define _ANGER_H
class Anger : public Component {
 private:
    int anger;
 public:
    explicit Anger(int anger);
    void setAnger(int anger);
    int getAnger();
};
#endif