#include "../Components/Component.h"
#ifndef _SPRITE_H
#define _SPRITE_H
class Sprite : public Component {
 private:
    char texture;
 public:
    explicit Sprite(char texture);
    void setTexture(char texture);
    const char getTexture();
};
#endif