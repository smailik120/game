#include "../Components/Raiting.h"
Raiting::Raiting(int rating) {
    this->rating = rating;
}

void Raiting::setRaiting(int rating) {
    this->rating = rating;
}

int Raiting::getRaiting() {
    return rating;
}