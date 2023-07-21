#include <iostream>

using namespace std;

class Unikat{
private:
    Unikat() = default;
    static Unikat *n;
public:
    static Unikat* exemplare(){
        if(n == nullptr){
            n = new Unikat();
            return n;
        } else {
            return n;
        }
    };
    void print(){
        cout << "Dies ist ein Print test von :" << this << endl;
    };
};
Unikat* Unikat::n= nullptr;
int main() {
    Unikat* unikat1 = Unikat::exemplare();
    Unikat* unikat2 = Unikat::exemplare();

    unikat1->print();
    unikat2->print();
    return 0;
}
