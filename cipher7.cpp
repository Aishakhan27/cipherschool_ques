#include <iostream>
using namespace std;

// Base class: Account
class Account {
public:
    virtual void displayBalance() {
        cout << "Account balance: Not specified" << endl;
    }
    virtual ~Account() {}
};

// Derived class: SavingAccount
class SavingAccount : public Account {
public:
    void displayBalance() override {
        cout << "Saving Account balance: $5000" << endl;
    }
};

// Derived class: CurrentAccount
class CurrentAccount : public Account {
public:
    void displayBalance() override {
        cout << "Current Account balance: $10000" << endl;
    }
};

// General class hierarchy
class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // Part 1: Account hierarchy and virtual displayBalance
    Account* acc1 = new SavingAccount();
    Account* acc2 = new CurrentAccount();

    acc1->displayBalance(); // Calls SavingAccount::displayBalance
    acc2->displayBalance(); // Calls CurrentAccount::displayBalance

    delete acc1;
    delete acc2;

    cout << "------------------------" << endl;

    // Part 2: Animal hierarchy demonstrating dynamic dispatch
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak(); // Calls Dog::speak
    a2->speak(); // Calls Cat::speak

    delete a1;
    delete a2;

    return 0;
}

