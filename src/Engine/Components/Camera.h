#ifndef _CAMERA_H
#define _CAMERA_H
#include "../Components/Component.h"
class Camera : public Component {
 private:
    float x;
    float y;
    float width;
    float height;
 public:
    Camera(float x, float y, float width, float height);
    float getX();
    float getY();
    float getWidth();
    float getHeight();
};
#endif