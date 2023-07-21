#include <iostream>

using namespace std;

class Automat;

class Zustand {
public:
    Zustand() = default;
    virtual ~Zustand() {}
    virtual void muenzeEinwerfen(Automat *a) = 0;
    virtual void ausgeben(Automat *a) = 0;
    void setState(Automat *a);
};

class Automat {
    friend class Zustand;
private:
    Zustand* zustand;
public:
    Automat();
    void muenzeEinwerfen();
    void knopfDruecken();
};

class KeineMuenzeZustand : public Zustand {
private:
    static KeineMuenzeZustand* _exemplar;
    KeineMuenzeZustand() = default;
public:
    static KeineMuenzeZustand* getInstance();
    void muenzeEinwerfen(Automat *a) override;
    void ausgeben(Automat *a) override;
};

class HatMuenzeZustand : public Zustand {
private:
    static HatMuenzeZustand* _exemplar;
    HatMuenzeZustand() = default;
public:
    static HatMuenzeZustand* getInstance();
    void muenzeEinwerfen(Automat *a) override;
    void ausgeben(Automat *a) override;
};

void Zustand::setState(Automat *a) {
    a->zustand = this;
}

Automat::Automat() {
    zustand = KeineMuenzeZustand::getInstance();
}

void Automat::muenzeEinwerfen() {
    zustand->muenzeEinwerfen(this);
}

void Automat::knopfDruecken() {
    zustand->ausgeben(this);
}

KeineMuenzeZustand* KeineMuenzeZustand::_exemplar = nullptr;
HatMuenzeZustand* HatMuenzeZustand::_exemplar = nullptr;

KeineMuenzeZustand* KeineMuenzeZustand::getInstance() {
    if (_exemplar == nullptr) {
        _exemplar = new KeineMuenzeZustand();
    }
    return _exemplar;
}

void KeineMuenzeZustand::muenzeEinwerfen(Automat *a) {
    cout << "Münze wurde eingeworfen." << endl;
    setState(a);
}

void KeineMuenzeZustand::ausgeben(Automat *a) {
    cout << "Münze wurde ausgegeben." << endl;
}

HatMuenzeZustand* HatMuenzeZustand::getInstance() {
    if (_exemplar == nullptr) {
        _exemplar = new HatMuenzeZustand();
    }
    return _exemplar;
}

void HatMuenzeZustand::muenzeEinwerfen(Automat *a) {
    cout << "Sie können keine weitere Münze einwerfen, bis die aktuelle Transaktion abgeschlossen ist." << endl;
}

void HatMuenzeZustand::ausgeben(Automat *a) {
    cout << "Getränk ausgegeben. Sie können Ihr Getränk jetzt entnehmen." << endl;
    setState(a);
}

int main() {
    Automat automat;

    automat.knopfDruecken();
    automat.muenzeEinwerfen();
    automat.muenzeEinwerfen();
    automat.knopfDruecken();

    return 0;
}
