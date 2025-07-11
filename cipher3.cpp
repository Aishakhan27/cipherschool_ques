#include <iostream>
#include <string>
using namespace std;

// Account class
class Account {
private:
    double balance;
public:
    Account() : balance(0.0) {}

    // Method that supports method chaining
    Account& setBalance(double amount) {
        balance = amount;
        return *this;
    }

    void displayBalance() const {
        cout << "Account Balance: $" << balance << endl;
    }
};

// Movie class
class Movie {
public:
    string title;
    float rating;

    Movie(string t, float r) : title(t), rating(r) {}

    void display() const {
        cout << "Movie Title: " << title << endl;
        cout << "Rating: " << rating << "/10" << endl;
    }
};

int main() {
    // Using Account class with method chaining
    Account acc;
    acc.setBalance(2500.50).displayBalance();

    // Dynamic allocation of Movie object
    Movie* myMovie = new Movie("Inception", 8.8);
    myMovie->display();

    // Freeing memory
    delete myMovie;

    return 0;
}

