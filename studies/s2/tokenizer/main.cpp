#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class token{
private:
    string _input;
    char _delimiter;

public:
    token(string input, char delimiter){
        _delimiter = delimiter;
        _input = input;
    }
    ~token(){

    }
    string strtotoken(){

        for(int i = 0; i<= _input.length();i++){
            if(_input[i] == _delimiter){

            }
        }
    };
};



int main() {
    char input[] = "Hello, World! This is a test.";
    const char* delimiter = " ,.!";  // Trennzeichen: Leerzeichen, Komma, Punkt, Ausrufezeichen

    char* token = strtok(input, delimiter);

    while (token != NULL) {
        std::cout << "Token: " << token << std::endl;
        token = strtok(NULL, delimiter);
    }

    return 0;
}
