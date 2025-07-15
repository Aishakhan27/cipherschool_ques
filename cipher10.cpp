#include <iostream>
#include <string>
using namespace std;

// Person class
class Person {
protected:
    string name;
    int age;
public:
    void setPersonDetails(string n, int a) {
        name = n;
        age = a;
    }
};

// Student class
class Student : public Person {
private:
    int rollNo;
public:
    void setStudentDetails(string n, int a, int r) {
        name = n;
        age = a;
        rollNo = r;
    }

    void displayDetails() {
        cout << "Name     : " << name << endl;
        cout << "Age      : " << age << endl;
        cout << "Roll No. : " << rollNo << endl;
    }
};

// Vehicle base class
class Vehicle {
protected:
    int speed;
public:
    virtual void displaySpeed() = 0; // Pure virtual
};

// Car class
class Car : public Vehicle {
public:
    Car() {
        speed = 180;
    }
    void displaySpeed() override {
        cout << "Car max speed: " << speed << " km/h" << endl;
    }
};

// Bike class
class Bike : public Vehicle {
public:
    Bike() {
        speed = 120;
    }
    void displaySpeed() override {
        cout << "Bike max speed: " << speed << " km/h" << endl;
    }
};

int main() {
    cout << "---- Student Details ----" << endl;
    Student s;
    s.setStudentDetails("Aisha", 20, 101);
    s.displayDetails();

    cout << "\n---- Vehicle Speeds ----" << endl;
    Car c;
    Bike b;

    c.displaySpeed();
    b.displaySpeed();

    return 0;
}

