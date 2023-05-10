#include <iostream>
#include <functional>

using namespace std;

template<typename T>
T mine(T a, T b) {
    std::less<T> less;
    return less(a, b) ? a : b;
}

template <typename T>
void swape(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}


int main() {
    int a = 10;
    int b = 12;
    cout << "Min int: " << mine(a,b) << endl;
    cout << "a = " << a << " b = " << b << endl;
    swape(a,b);
    cout << "a = " << a << " b = " << b << endl;
    double c = 10.0;
    double d = 12.0;
    cout << "Min double: " << mine(c,d) << endl;
    cout << "c = " << c << " d = " << d << endl;
    swape(c,d);
    cout << "c = " << c << " d = " << d << endl;

}
