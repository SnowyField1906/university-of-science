#ifndef MANGPS_H
#define MANGPS_H

#include "PhanSo.h"

class MangPS {
private:
    PhanSo* list;
    int size;

public:
    MangPS();
    ~MangPS();

    void input();
    void output() const;
    PhanSo sum() const;
    void sort();
    void write(const char*) const;
    void read(const char*);
};

#endif // MANGPS_H
