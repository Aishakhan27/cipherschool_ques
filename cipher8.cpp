#include <iostream>
using namespace std;

// Engine class
class Engine {
public:
    void start() {
        cout << "Engine started." << endl;
    }
};

// Car class using Engine
class Car {
private:
    Engine engine; // Composition

public:
    void startCar() {
        cout << "Starting car..." << endl;
        engine.start(); // Call Engine's start
    }
};

// Printer class
class Printer {
public:
    void printDocument() {
        cout << "Printing document..." << endl;
    }
};

// SmartPrinter class inherits from Printer
class SmartPrinter : public Printer {
public:
    void scanDocument() {
        cout << "Scanning document..." << endl;
    }
};

int main() {
    // Part 1: Composition example
    Car myCar;
    myCar.startCar();

    cout << "------------------------" << endl;

    // Part 2: Inheritance example
    SmartPrinter sp;
    sp.printDocument();  // Inherited method
    sp.scanDocument();   // Own method

    return 0;
}

