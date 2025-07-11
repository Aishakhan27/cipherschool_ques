#include <iostream>
using namespace std;

// Counter class
class Counter {
private:
    static int objectCount; // Static variable to track object count

public:
    Counter() {
        objectCount++;
    }

    // Static function to get the object count
    static int getObjectCount() {
        return objectCount;
    }
};

// Definition of static member outside the class
int Counter::objectCount = 0;

// MyArray class
class MyArray {
private:
    int arr[5];

public:
    void setValue(int index, int val) {
        if (index >= 0 && index < 5) {
            arr[index] = val;
        } else {
            cout << "Index out of range!" << endl;
        }
    }

    int getValue(int index) {
        if (index >= 0 && index < 5) {
            return arr[index];
        } else {
            cout << "Index out of range!" << endl;
            return -1;
        }
    }
};

int main() {
    // Create some Counter objects
    Counter c1, c2, c3;

    // Print object count without creating an object
    cout << "Number of Counter objects created: " << Counter::getObjectCount() << endl;

    // Using MyArray
    MyArray arr;
    arr.setValue(0, 10);
    arr.setValue(1, 20);
    arr.setValue(2, 30);

    cout << "Value at index 0: " << arr.getValue(0) << endl;
    cout << "Value at index 1: " << arr.getValue(1) << endl;
    cout << "Value at index 2: " << arr.getValue(2) << endl;

    return 0;
}

