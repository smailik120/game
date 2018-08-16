#include "../Components/Score.h"
Score::Score(int score) {
    this->score = score;
}

void Score::setScore(int score) {
    this->score = score;
}

int Score::getScore() {
    return score;
}

bool Score::isDeath() {
    return this->score < 0;
}
