#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class date{
private:
    int _tag;
    int _monat;
    int _jahr;
public:
    date(int date){
        _jahr = date % 10000;
        date /= 10000;
        _monat = date % 100;
        date /= 100;
        _tag = date;
    }
    int gettag(){
        return _tag;
    };
    int getmonat(){
      return _monat;
    };
    int getjahr(){
      return _jahr;
    };
    void settag(int tag){
        _tag = tag;
    }
    void setmonat(int monat){
        _monat = monat;
    }
    void setjahr(int jahr){
        _jahr = jahr;
    }

};

class Fileextractor {
private:
    string _filename;
public:
    Fileextractor(string filename): _filename(filename){};
    string getfilename(){
        return _filename;
    };
    void setfilename(string filename){
        _filename = filename;
    };
    string readfile(vector<string> &vec){
        ifstream fread(_filename);
        if(!fread){
            cout << "Fehler beim Öffnen der Datei." << endl;
            return 0;
        }
        string line;
        do{
            getline(fread, line);
            vec.push_back(line);
        }while(!fread.eof());
        fread.close();
        return line;
    };
    void writefile(string line){
        ofstream outputFile(_filename);
        if(!outputFile){
            cout << "Fehler beim lesen von der Datei." << endl;
        } else {
            outputFile << line;
        }
        outputFile.close();
    };
};

class Verkauf{
private:
    date _datum;
    string Autos;
    int verkauft;
public:
    Verkauf(date datum, string autos, int verkauf): _datum(datum), Autos(autos), verkauft(verkauf){};
    date getdatum(){
        return _datum;
    };
    string getautos(){
        return Autos;
    };
    int getverkauft(){
        return verkauft;
    };
    void setdatum(date datum){
        _datum = datum;
    };
    void setautos(string autos){
        Autos = autos;
    };
    void setverkauft(int verkauf){
        verkauft = verkauf;
    };
    void tostring(){
       cout << "Datum: " << _datum.gettag() << "." << _datum.getmonat() << "." << _datum.getjahr() << endl;
    };

};

int main() {
   Fileextractor file("../test.txt");
    vector<string> vec;
    file.readfile(vec);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    //Test für die Klasse Date und fileextractor
    date date1(20191224);
    cout << date1.gettag() << "." << date1.getmonat() << "." << date1.getjahr() << endl;
    file.setfilename("../test.txt");
    file.writefile("Hallo Welt");
    //Test für die Klasse Verkauf
    Verkauf verkauf(date1, "Audi", 5);
    verkauf.tostring();

   return 0;
}
