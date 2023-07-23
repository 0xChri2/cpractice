#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Mitarbeiter{
private:
    int _id;
    string _Name;
    string _Abteilung;
    double _Gehalt;
public:
    Mitarbeiter(int id,string name,string abteilung, double gehalt ) : _id(id), _Name(name), _Abteilung(abteilung), _Gehalt(gehalt) {};
    ~Mitarbeiter(){};
};
void storeMitarbeiterData(string filename, Mitarbeiter mitarbeiter[], int size){
    ofstream output;
    output.open(filename,ofstream::out);
    if (output.is_open()){
        for(int i = 0; i < size;i++){
            output << mitarbeiter[i] << endl;
        }
    }


}


int main() {
    Mitarbeiter mitarbeiter[] = {
            {12345, "Maxmustermann", "Vertrib", 50000.0},
            {23456, "Erika Musterfrau", "IT", 55000.0},
            {34567, "Otto Normalverbaucher", "Marketing", 48000.0},
            {45678, "Anna Normal", "Finanzen", 52000.0}
    };
    Mitarbeiter m1(mitarbeiter[1]);
    return 0;
}
