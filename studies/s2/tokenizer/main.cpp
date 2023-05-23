#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class token{
private:
    string _delimiter, _input;

public:
    token(string input, string delimiter){
        _delimiter = delimiter;
        _input = input;
    }
    ~token(){

    }
    string strtotoken()
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
