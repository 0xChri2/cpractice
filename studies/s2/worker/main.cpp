#include <iostream>
#include <string>

using namespace std;

class worker{
protected:
    int _id;
    string _name;
    int _basesalary;
public:
    worker(int id, string name, int basesalary){
        _id = id;
        _name = name;
        _basesalary = basesalary;
    }
    ~worker(){}
    int salary(){
        return _basesalary;
    }
    int getID(){
        return _id;
    }
};

class manager : public worker {
private:
    int _bonus;
public:
    manager(int id, string name, int basesalary, int bonus) : worker(id, name, basesalary) {
        _bonus = bonus;
    }
    ~manager(){}
    int salary() {
        return (_basesalary + _bonus);
    }

};

class chef : public worker{
public:
    chef(int id, string name, int basesalary) : worker(id, name, basesalary){};
    ~chef(){}
    int salary(){
        return _basesalary;
    }
};

int main() {
    worker emp1(1, "John Doe", 5000);
    cout << "Employee ID: " << emp1.getID() << endl;
    cout << "Salary: " << emp1.salary() << endl;

    manager mgr1(2, "Jane Smith", 8000, 2000);
    cout << "Manager ID: " << mgr1.getID() << endl;
    cout << "Salary: " << mgr1.salary() << endl;

    chef chf1(3, "Mike Johnson", 6000);
    cout << "Chef ID: " << chf1.getID() << endl;
    cout << "Salary: " << chf1.salary() << endl;

    return 0;
}
