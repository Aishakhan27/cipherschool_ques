#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    // Constructor
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    // Overload + operator
    Time operator+(const Time& other) {
        Time temp;
        temp.minutes = minutes + other.minutes;
        temp.hours = hours + other.hours + (temp.minutes / 60);
        temp.minutes %= 60;
        return temp;
    }

    // Display function
    void display() {
        cout << hours << " hours " << minutes << " minutes" << endl;
    }
};

int main() {
    Time t1(2, 50), t2(1, 30);
    Time result = t1 + t2;

    cout << "Sum of time durations: ";
    result.display();
    return 0;
}

