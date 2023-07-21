#include <iostream>

using namespace std;

class Buch {
protected:
    string title;
    double basisAusleihGebuehr;
public:
    virtual double ausleihGebuehr(int tage){
        return basisAusleihGebuehr * tage;
    };
    virtual string getAusleihZeitraum(){
        return "2 Monate";
    };

};

class Roman : public Buch{
public:
    double ausleihGebuehr(int tage){
        if((basisAusleihGebuehr * tage) <= 5){
            return basisAusleihGebuehr * tage;
        } else {
            return 5;
        }
    };
    string getAusleihZeitraum(){
        return "1 Monat";
    };
};

class Fachbuch : public Buch{
    double ausleihGebuehr(int tage){
        return 2;
    };
    string getAusleihZeitraum(){
        return "2 Wochen";
    };
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
