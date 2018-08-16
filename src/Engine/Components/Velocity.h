#include "../Components/Component.h"
#ifndef _VELOCITY_H
#define _VELOCITY_H
class Velocity : public Component {
 private:
    int speedX;
    int speedY;
    int boost;
 public:
    Velocity(int speedX, int speedY, int boost);
    void setSpeedX(int speedX);
    void setSpeedY(int speedY);
    int getSpeedX();
    int getSpeedY();
};
#endif