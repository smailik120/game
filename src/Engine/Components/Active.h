#include "../Components/Component.h"
#ifndef _ACTIVE_H
#define _ACTIVE_H
class Active : public Component {
 private:
    bool active = false;
 public:
    void setActive(bool active);
    bool getActive();
};
#endif