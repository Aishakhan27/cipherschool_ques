#include <iostream>
#include <cmath>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual float area() = 0; // Pure virtual function
    virtual ~Shape() {}       // Virtual destructor
};

// Derived class: Circle
class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}
    float area() override {
        return M_PI * radius * radius;
    }
    ~Circle() {
        cout << "Circle destructor called" << endl;
    }
};

// Derived class: Square
class Square : public Shape {
    float side;
public:
    Square(float s) : side(s) {}
    float area() override {
        return side * side;
    }
    ~Square() {
        cout << "Square destructor called" << endl;
    }
};

// Base class with virtual destructor
class Base {
public:
    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }
};

// Derived class with destructor
class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    // Part 1: Polymorphism
    Shape* s1 = new Circle(3.0);
    Shape* s2 = new Square(4.0);

    cout << "Circle area: " << s1->area() << endl;
    cout << "Square area: " << s2->area() << endl;

    delete s1; // Calls Circle and Shape destructors
    delete s2; // Calls Square and Shape destructors

    cout << "----------------------" << endl;

    // Part 2: Virtual destructor demo
    Base* b = new Derived();
    delete b; // Properly calls Derived then Base destructor

    return 0;
}

