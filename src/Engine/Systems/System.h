#ifndef _SYSTEM_H
#define _SYSTEM_H
#include "../Entity/Entity.h"
class System {
 public:
  virtual void update() = 0;
  virtual bool validate(Entity *entity) = 0;
};
#endif