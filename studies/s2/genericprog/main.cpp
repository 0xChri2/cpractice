#include <iostream>
#include <functional>

using namespace std;

template<typename T>
T min(T &a, T &b) {
    return a < b ? a : b;
}

template <typename T>
void swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}


int main() {
    int a = 10;
    int b = 12;
    cout << "Min int: " << min(a,b) << endl;
    swap(a,b);
    double c;
    double d;
    cout << "Min int: " << min(c,d) << endl;

}
