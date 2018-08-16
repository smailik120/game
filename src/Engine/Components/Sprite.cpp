#include "../Components/Sprite.h"
Sprite::Sprite(char texture) {
    this->texture = texture;
}

void Sprite::setTexture(char texture) {
    this->texture = texture;
}

const char Sprite::getTexture() {
    return texture;
}