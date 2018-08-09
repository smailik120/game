#include "../Components/Component.h"
#ifndef _SCORE_H
#define _SCORE_H
class Score : public Component {
 private:
    int score;
 public:
    explicit Score(int score);
    void setScore(int score);
    int getScore();
    bool isDeath();
    void step();
};
#endif