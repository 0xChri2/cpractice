#include <iostream>

using namespace std;
class Kategorie{
protected:
    int _basispreis;
    int _leihdauer;
    int _strafgebuehr;
public:
    Kategorie(int basispreis, int leihdauer, int strafgebuehr): _basispreis(basispreis), _leihdauer(leihdauer), _strafgebuehr(strafgebuehr){};
    virtual int preis(int tage) = 0;
};

class normal : public Kategorie{
public:
    normal(int basispreis, int leihdauer, int strafgebuehr): Kategorie(basispreis, leihdauer, strafgebuehr){};
    int preis(int tage) override{
        return _basispreis * tage;
    }
};

class Bestseller : public Kategorie{
public:
    Bestseller(int basispreis, int leihdauer, int strafgebuehr): Kategorie(basispreis, leihdauer, strafgebuehr){};
    int preis(int tage) override{
        return _basispreis * tage;
    };
};

class Angebot : public Kategorie{
public:
    Angebot(int basispreis, int leihdauer, int strafgebuehr): Kategorie(basispreis, leihdauer, strafgebuehr){};
    int preis(int tage) override{
        if(_leihdauer <= tage){
            return _basispreis * _leihdauer;
        } else {
            return _strafgebuehr * tage;
        }
    }
};

int main() {
    Kategorie* m[3] = {
            new normal(10, 10, 1000), new Bestseller(20,20,2000), new Angebot(30, 30 ,3000)
    };
    cout << "M1: " << m[0]->preis(10) << endl;
    cout << "M2: " << m[1]->preis(10) << endl;
    cout << "M3: " << m[2]->preis(10) << endl;
    return 0;
}
