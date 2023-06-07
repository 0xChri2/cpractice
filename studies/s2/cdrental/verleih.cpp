#include "verleih.h"

void verleih::hinzuCD(cd cd, int cdnummer){
    if(_acd[cdnummer] != nullptr){
        _acd[cdnummer] = &cd;
    }else{
        for(int i = 0; i < 10; i++){
        if(_acd[i] == nullptr){
            _acd[i] = &cd;
        }

        }
    }
}

void verleih::hinzuKunde(kunde& k, int kundennr) {
    if(_akunde[kundennr] == nullptr){
        _akunde[kundennr] = &k;
    } else {
        for(int i = 0; i < 10; i++){
                if(_akunde[i] != nullptr){
                        _akunde[i] = &k;
                }
        }
    }
}

string * verleih::gibKundenliste(){

}
string * verleih::gibAusleiheVon(int kunde){

}