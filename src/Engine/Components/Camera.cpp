
#include "../Components/Camera.h"
Camera::Camera(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}
float Camera::getX() {
    return x;
}
float Camera::getY() {
    return y;
}
float Camera::getWidth() {
    return width;
}
float Camera::getHeight() {
    return height;
}