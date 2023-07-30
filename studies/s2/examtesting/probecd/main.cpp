/*#include <iostream>
#include <vector>
#include <stdexcept> // Für std::invalid_argument
#include <algorithm> // Für std::transform
using namespace std;

class divided {
private:
    int divisor;
    vector<int> result;

public:
    divided(int d = 2) : divisor(d){};
   void operator()(int nums){
       if (divisor == 0) {
           throw invalid_argument("Fehler: Der Divisor darf nicht null sein!");
       }
       result.push_back(nums / divisor);

   }
   void print(){
       for (auto it = result.begin(); it < result.end(); it++) {
           cout << *it << endl;
       }
   }
};

int main(){
    vector<int> numbers_1 = {12,24,36,48,60,72,84,96};
    try{
        divided divdedBySix(6);
        for_each(numbers_1.begin(), numbers_1.end(),divdedBySix);
        divdedBySix.print();
    }catch(invalid_argument& e) {
        cout << e.what() << endl;
    }

}*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // Für std::find_if
using namespace std;


class IsSquareNumber{
public:
    bool operator()(int nums){
        double root = std::sqrt(nums);
        int intRoot = static_cast<int>(root);
        return intRoot * intRoot == nums;
    }
};

int main(){
    vector<int> numbers_2 = {25,36,49,64,81,100,121,143};
    IsSquareNumber isSquareNumber;
    vector<int>::reverse_iterator it2 = find_if(numbers_2.rbegin(),numbers_2.rend(),isSquareNumber);

    if (it2 != numbers_2.rbegin() ) {
        cout << "Erstes gerade Zahl im Vektor gefunden: " << *it2 << endl;
    } else {
        cout << "Keine gerade Zahl im Vektor gefunden." << endl;
    }
}