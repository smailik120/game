#include "../Components/Velocity.h"
Velocity::Velocity(int speedX, int speedY, int boost) {
    this->speedX = speedX;
    this->speedY = speedY;
    this->boost = boost;
}
void Velocity::setSpeedX(int speedX) {
    this->speedX = speedX;
}
void Velocity::setSpeedY(int speedY) {
    this->speedY = speedY;
}
void Velocity::setBoost(int boost) {
    this->boost = boost;
}
int Velocity::getSpeedX() {
    return speedX;
}
int Velocity::getSpeedY() {
    return speedY;
}