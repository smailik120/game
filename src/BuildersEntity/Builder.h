#ifndef _BUILDER_H
#define _BUILDER_H
#include <string>
#include "../Engine//Entity/Entity.h"
class Builder {
 public:
    virtual Entity* build(int posX, int posY) = 0;
};
#endif