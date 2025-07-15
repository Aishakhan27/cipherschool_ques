#include <iostream>
using namespace std;

// Car Class
class Car {
private:
    string brand;
    string model;
    int year;

public:
    // Constructor
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    // Method to display details
    void displayInfo() {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Car Year : " << year << endl;
    }
};

// Timer Class
class Timer {
public:
    // Constructor
    Timer() {
        cout << "Timer started" << endl;
    }

    // Destructor
    ~Timer() {
        cout << "Timer stopped" << endl;
    }
};

int main() {
    {
        Timer t; // Timer starts here

        // Car object
        Car myCar("Toyota", "Corolla", 2020);
        myCar.displayInfo();
    } // Timer object goes out of scope here – destructor called

    return 0;
}

