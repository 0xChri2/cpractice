#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class token {
private:
    string _input;
    string _delimiter;
    size_t pos;
public:
    token(const std::string& input, string delim)
            : _input(input), _delimiter(delim), pos(0) {}

    ~token() {}

    string getNextToken() {
        // Sucht das nächste Vorkommen des Trennzeichens ab der aktuellen Position
        size_t start = _input.find_first_not_of(_delimiter, pos);
        size_t end = _input.find_first_of(_delimiter, start);

        // Überprüft, ob das Trennzeichen gefunden wurde
        if (end == std::string::npos) {
            // Wenn kein weiteres Trennzeichen gefunden wurde, gibt den Rest des Strings zurück
            string token = _input.substr(start);
            // Setzt die Position auf das Ende des Strings, um den Abbruch der Schleife zu signalisieren
            pos = _input.length();
            return token;
        }

        // Aktualisiert die Position für den nächsten Aufruf
        pos = end + 1;

        // Gibt das gefundene Token zurück
        return _input.substr(start, end - start);
    }
};

int main() {
    std::string input = "Hello, World! This is a sample string.";
    string delimiter = " ";

    token tkn(input, delimiter);

    std::string token;
    while ((token = tkn.getNextToken()) != "") {
        std::cout << "Token: " << token << std::endl;
    }

    return 0;
}
