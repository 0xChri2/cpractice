#ifndef HEAPCPP_HEAP_H
#define HEAPCPP_HEAP_H

#include <iostream>
using namespace std;

class heap{
private:

    int _size;
    int _min;
    int _error;
public:
    int *_data;
    heap(int size);
    ~heap();
    char insert(int val);
    int minimum();
    char extractMin();
    char getError();
    string toString();
    string readFile(string filename);
    string writeFile(string filename);
};

#endif //HEAPCPP_HEAP_H
