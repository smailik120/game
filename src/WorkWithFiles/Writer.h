#ifndef _WRITER_H
#define _WRITER_H
#include <fstream>
#include <list>
#include <string>
template <typename T>
class Writer {
 private:
    std::string path;
 public:
void write(std::list<T> scores) {
    std::ofstream fout;
    fout.open(path);
    for (typename std::list<T>::iterator it = scores.begin(); it !=scores.end(); it++) {
            fout<< *it;
            fout<< "\n";
    }
    fout.close();
}
Writer(std::string path) {
    this->path = path;
}
};
#endif