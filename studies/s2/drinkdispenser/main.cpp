#include <iostream>
#include <string>
using namespace std;

class Automat {
protected:
    int _rueckgeld;
    int _preis;
    int _auswahl;
public:
    Automat(int auswahl, int preis) {
        _preis = preis;
        _auswahl = auswahl;
        _rueckgeld = 0;

    };
    void calcrueckgeld(int eingabe,int price){
        _rueckgeld = eingabe - price;
    };
    int getrueckgeld(){
        return _rueckgeld;
    };

};

class Zustand{
private:
    Zustand(){
    }
    int eingabe;
public:
    Zustand *exemplar(Zustand *zustand){
        if(zustand == nullptr){
            Zustand* newzustand = new Zustand();
            return newzustand;
        }else {
            return zustand;
        }

    };
    int work(){

    };
};

int Zustand* zustand = nullptr;

int main() {
    int eingabe = 0;
    do{
        int strinprice[4] = {0,60, 78, 45};
        cout << "Zustand: Breit\n \n (1) Kaffee: 60c \n (2) Suppe: 78c \n (3) Limonade: 45c" << endl;
        cin >> eingabe;
        if(eingabe == 0){
            return 0;
        } else if (eingabe >= 1 && eingabe <= 3){
            Automat a(eingabe, strinprice[eingabe]);
            int money;
            do{
                cout << "Geld noch zu Zahlen: " << strinprice[eingabe] << endl;
                cin >> money;
                if(money >= strinprice[eingabe]){
                    a.calcrueckgeld(money,strinprice[eingabe]);
                } else {
                    do{
                        int restmoney = 0;
                        cout << "Geld noch zu Zahlen: " << strinprice[eingabe] - money << endl;
                        cin >> restmoney;
                        money = money + restmoney;
                    }while(money >= strinprice[eingabe]);
                }
            }while(money < 0);
            string yorn;
            do{
            cout << "Getränk genommen: y/n" << endl;
            cin >> yorn;
            if(yorn.compare("y") == 0){
                cout << "Ihr Rückgeld beträgt: " << a.getrueckgeld() << endl;
                cout << "Geld ausgabe.... \n \n \n" << endl;
            } else if (yorn.compare("n") == 0){
                cout << "Bitte nehmen sie ihr Getränk." << endl;
            } else { throw("Fehlerhafte eingabe");}
            } while (yorn.compare("y"));
        }
    }while(true);
    return 0;
}
