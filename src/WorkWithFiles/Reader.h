#ifndef _READER_H
#define _READER_H
#include <fstream>
#include <list>
#include <cstring>
#include <string>
template <typename T>
class Reader {
 private:
    std::string path;
 public:
std::list<T> read() {
std::string result;
std::list<T> scores;
std::ifstream fin(path);
while( fin>> result ) {
    scores.push_back(result);
}
fin.close();
return scores;
}
Reader(std::string path) {
    this->path = path;
}
};

#endif