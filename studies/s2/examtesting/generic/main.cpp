#include <iostream>

using namespace std;

template<typename T>
T minmum(T a, T b){
    if(a >= b){
        return b;
    } else {
        return a;
    }
}
template<typename T>
void swapt (T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    double a = 1.00, b = 4.00;
    double i = minmum(1.00,4.00);
    cout << "Min von " << a << " ," << b << " = " << i << endl;
    swapt(a,b);
    cout << "Min von " << a << " ," << b << " = " << i << endl;
    return 0;
}
