#include <iostream>

using namespace std;
class Mitarbeiter {
protected:
    int _id;
    string _name;
    int _basisgehalt;
public:
    Mitarbeiter(int id, string name, int basisgehalt): _id(id), _name(name), _basisgehalt(basisgehalt){};
    virtual int gehalt(){
        return _basisgehalt;
    };
    int getID(){
        return _id;
    };
};

class Manager : public Mitarbeiter{
private:
    int bonus();
public:
    Manager(int id, string name, int basisgehalt) : Mitarbeiter( id, name, basisgehalt) {};
    int gehalt() override {
        return _basisgehalt *4;
    };
};

class Leitend : public Mitarbeiter{
public:
    Leitend(int id, string name, int basisgehalt) : Mitarbeiter( id, name, basisgehalt) {};
    int gehalt() override{
        return _basisgehalt *2;
    };
};

int main() {
    Mitarbeiter* m[3] = { new Mitarbeiter(10, "Mitarbeiter",10 ),new Leitend(10, "Leitend",100 ), new Manager(10, "Manager",1000 )
    };
    cout << "Gehalt von Mitarbeiter: " << m[0]->gehalt() << endl;
    cout << "Gehalt von Leitend: " << m[1]->gehalt() << endl;
    cout << "Gehalt von Manager: " << m[2]->gehalt() << endl;

    return 0;
}
