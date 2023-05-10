#include <iostream>
#include "stackcom.h"

using namespace std;

int main() {
    // Erstellen eines Integer-Stacks
    mystack_t<int> stack;

    // Testen, ob der Stack leer ist
    std::cout << "Stack ist leer: " << stack.isEmpty() << std::endl;

    // Hinzufügen von Elementen zum Stack
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Testen, ob der Stack leer ist
    std::cout << "Stack ist leer: " << stack.isEmpty() << std::endl;

    // Entfernen von Elementen vom Stack
    std::cout << "Entferntes Element: " << stack.pop() << std::endl;
    std::cout << "Entferntes Element: " << stack.pop() << std::endl;
    std::cout << "Entferntes Element: " << stack.pop() << std::endl;

    // Testen, ob der Stack leer ist
    std::cout << "Stack ist leer: " << stack.isEmpty() << std::endl;

    return 0;
}