#include <iostream>
using namespace std;

// Point class
class Point {
private:
    int x, y;

public:
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    // Const member function to display coordinates
    void display() const {
        cout << "Point Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

// Class A
class B;  // Forward declaration

class A {
private:
    int valueA;

public:
    A(int val) : valueA(val) {}

    // Declare friend function
    friend void printSum(const A&, const B&);
};

// Class B
class B {
private:
    int valueB;

public:
    B(int val) : valueB(val) {}

    // Declare friend function
    friend void printSum(const A&, const B&);
};

// Friend function definition
void printSum(const A& aObj, const B& bObj) {
    int sum = aObj.valueA + bObj.valueB;
    cout << "Sum of A and B's private members: " << sum << endl;
}

// Main function
int main() {
    // Part 1: Const object and const member function
    const Point p1(3, 4);
    p1.display();

    // Part 2: Friend function accessing private members
    A objA(10);
    B objB(20);
    printSum(objA, objB);

    return 0;
}

