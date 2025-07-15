#include <iostream>
using namespace std;

// Base class Shape
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape" << endl;
    }

    void describe() {
        cout << "This is a shape" << endl;
    }

    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle" << endl;
    }
};

int main() {
    // Part 1: Polymorphic call to overridden functions
    Shape* s1 = new Circle();
    Shape* s2 = new Rectangle();

    s1->draw(); // Calls Circle::draw()
    s2->draw(); // Calls Rectangle::draw()

    cout << "------------------------" << endl;

    // Part 2: Calling base function not overridden
    Shape* s3 = new Circle();
    s3->describe(); // Calls Shape::describe()

    // Cleanup
    delete s1;
    delete s2;
    delete s3;

    return 0;
}

