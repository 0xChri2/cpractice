#include <iostream>

using namespace std;

class Getränk {
public:
    virtual int preis() = 0;
};
class kaffee : public Getränk{
public:
    int preis() override{
        return 2;
    };
};
class dekorierer : public Getränk{
protected:
    Getränk* Drink;
public:
    dekorierer(Getränk* Drink) : Drink(Drink){};
        int preis() override {
                return Drink->preis() +2;
        }
};

class test : public dekorierer{
public:
    test(Getränk* Drink) : dekorierer(Drink) {};
    int preis()override{
        return Drink->preis() +2;
    };
};

int main() {
    Getränk* kaffeen = new kaffee();
    kaffeen = new dekorierer(kaffeen);
    kaffeen = new test(kaffeen);
    cout << "Preis: " << kaffeen->preis();
    return 0;
}
