
#include "../Components/Component.h"
#ifndef _POSITION_H
#define _POSITION_H
class Position : public Component {
 private:
    float x;
    float y;
 public:
    bool operator == (const Position& position) const {
        return this->x == position.x && this->y == position.y;
    }
    Position(float x1, float y1);
    void setX(float x1);
    void setY(float y1);
    float getX();
    float getY();
};
#endif