
#include "../Components/Position.h"
Position::Position(float x1, float y1) {
    x = x1;
    y = y1;
}
void Position::setX(float x1) {
    x = x1;
}
void Position::setY(float y1) {
    y = y1;
}
float Position::getX() {
    return x;
}
float Position::getY() {
    return y;
}