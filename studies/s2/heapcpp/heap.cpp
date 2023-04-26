#include "heap.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

heap::heap(int size) {
    _data = new int[size];
    _size = size;
    _min = 0;
    _error = 0;
}

heap::~heap() {
    //delete(_data);
}
char heap::insert(int val){
    if (_min < _size) {
        _data[_min] = val;
    }
    else{
        _size = val;
        int *newArr = new int[val+1];
        memcpy(newArr, _data, 10 * sizeof(int));
        delete[] _data;
        _data = newArr;
    }

}

int heap::minimum(){
    return _data[_min];
}

char heap::extractMin(){
    if(_min >= _size){
        _error = 1;
        return -1;
    } else {
        int _min = _data[_min];
        for(int i = _min; i < _size -1; i++){
            _data[i] = _data[i + 1];
        }
        _size--;
        return _min;
    }
}

char heap::getError(){
    return _error;
}

string heap::toString(){
    stringstream ss;
    for(int i = 0; i < _size; i++){
        ss << _data[i] << " ";
    }
    return ss.str();
}

string heap::readFile(string filename) {
    ifstream file(filename);
    vector<string> lines;
    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return "";
    }
    stringstream buffer;
    while (getline(file, buffer, ';')) {
        lines.push_back(buffer);
    }

    file.close();
    return content;
}

string heap::writeFile(string filename) {
    ofstream outdata;
}