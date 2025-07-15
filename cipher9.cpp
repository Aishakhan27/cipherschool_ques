#include <iostream>
using namespace std;

// Base class Animal
class Animal {
public:
    Animal() {
        cout << "Animal constructor called." << endl;
    }
    ~Animal() {
        cout << "Animal destructor called." << endl;
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    Dog() {
        cout << "Dog constructor called." << endl;
    }
    ~Dog() {
        cout << "Dog destructor called." << endl;
    }
};

// Base class Person with parameterized constructor
class Person {
public:
    Person(string name) {
        cout << "Person constructor called for " << name << endl;
    }
    ~Person() {
        cout << "Person destructor called." << endl;
    }
};

// Derived class Student with constructor chaining
class Student : public Person {
public:
    Student(string name, int roll) : Person(name) {
        cout << "Student constructor called for Roll No: " << roll << endl;
    }
    ~Student() {
        cout << "Student destructor called." << endl;
    }
};

int main() {
    cout << "Creating Dog object..." << endl;
    Dog d;
    cout << "Dog object created.\n" << endl;

    cout << "--------------------------" << endl;

    cout << "Creating Student object..." << endl;
    Student s("Aisha", 101);
    cout << "Student object created." << endl;

    return 0;
}

