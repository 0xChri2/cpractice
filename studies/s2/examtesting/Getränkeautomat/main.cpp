#include <iostream>

using namespace std;
class Zustand;

class Automat {
friend class Zustand;
private:
    Zustand* zustand;
    void setState(Zustand* z){
        zustand = z;
    };
public:
    Automat();
    void muenzeEinwerfen() {
    zustand->muenzeEinwerfen(this);
    };
    void knopfDruecken(){
        zustand->ausgeben(this);
    };
};
class Zustand {
public:
    Zustand() = default;
    virtual ~Zustand() {}
    virtual void muenzeEinwerfen(Automat *a) = 0;
    virtual void ausgeben(Automat *a) = 0;
};

class KeineMuenzeZustand : public Zustand {
private:
    static KeineMuenzeZustand* _exemplar;
    KeineMuenzeZustand() = default;
public:
    static KeineMuenzeZustand* getInstance() {
        if (_exemplar == nullptr) {
            _exemplar = new HatMuenzeZustand();
        }
        return _exemplar;
    };
    void muenzeEinwerfen(Automat *a) override {
        cout << "Münze wurde eingeworfen: ";
    };
    void ausgeben(Automat *a) override {
        cout << "Münze wurde Augegeben: ";
    };
};
KeineMuenzeZustand* KeineMuenzeZustand::_exemplar = nullptr;
HatMuenzeZustand* HatMuenzeZustand::_exemplar = nullptr;
// 'KonkreterZustand' Klasse: Hat Münze (Singleton)
class HatMuenzeZustand : public Zustand {
private:
    static HatMuenzeZustand* _exemplar;
    HatMuenzeZustand() = default;
public:
    static HatMuenzeZustand* getInstance();
    void muenzeEinwerfen(Automat *a) override {
        cout << "Sie können keine weitere Münze einwerfen, bis die aktuelle Transaktion abgeschlossen ist.\n";
    };
    void ausgeben(Automat *a) override {
        cout << "Getränk ausgegeben. Sie können Ihr Getränk jetzt entnehmen.\n";
        setState(a);
    };
};



int main() {
    Automat automat;

    automat.knopfDruecken();
    automat.muenzeEinwerfen();
    automat.muenzeEinwerfen();
    automat.knopfDruecken();

    return 0;
}
