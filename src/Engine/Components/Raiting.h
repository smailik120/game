#include "../Components/Component.h"
#ifndef _RAITING_H
#define _RAITING_H
class Raiting : public Component {
 private:
    int rating;
 public:
    explicit Raiting(int rating);
    void setRaiting(int rating);
    int getRaiting();
};
#endif