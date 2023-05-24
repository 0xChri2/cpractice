#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

class date {
private:
    int _tag;
    int _monat;
    int _jahr;

public:
    date(int tag, int monat, int jahr) : _tag(tag), _monat(monat), _jahr(jahr) {}

    int diff(date& other) {
        // Unterschied in Jahren berechnen
        int jahrdiff = other._jahr - _jahr;

        // Überprüfen, ob der Geburtstag im aktuellen Jahr bereits stattgefunden hat
        if (other._monat < _monat || (other._monat == _monat && other._tag < _tag)) {
            jahrdiff--;
        }

        return jahrdiff;
    }
};

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
private:
    date _birthdate{1,1,1900};
public:
    chef(int id, string name, int basesalary, date birthdate ) : worker(id, name, basesalary) {
        _birthdate = birthdate;
    }
    ~chef(){}
    int salary() {
        auto currentdate1 = chrono::system_clock::now();
        time_t currentdate_time = chrono::system_clock::to_time_t(currentdate1);
        tm* currentdate_tm = localtime(&currentdate_time);
        date currentdate(currentdate_tm->tm_mday, currentdate_tm->tm_mon + 1, currentdate_tm->tm_year + 1900);
        int age = _birthdate.diff(currentdate);

        int additionalSalary = (age > 23) ? (age - 23) * 50 : 0;

        return _basesalary + additionalSalary;
    }

    int getAge(date& currentdate) {
        return _birthdate.diff(currentdate);
    }
};

int main() {
    worker emp1(1, "John Doe", 5000);
    cout << "Employee ID: " << emp1.getID() << endl;
    cout << "Salary: " << emp1.salary() << endl;

    manager mgr1(2, "Jane Smith", 8000, 2000);
    cout << "Manager ID: " << mgr1.getID() << endl;
    cout << "Salary: " << mgr1.salary() << endl;

    chef chf1(3, "Mike Johnson", 3000, date(10, 2, 1997));
    cout << "Chef ID: " << chf1.getID() << endl;
    cout << "Salary: " << chf1.salary() << endl;

    return 0;
}
