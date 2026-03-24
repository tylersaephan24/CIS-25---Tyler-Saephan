#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string username;

public:
    User(string name) {
        username = name;
    }

    virtual void accessLevel() {
        cout << username << ": General Access" << endl;
    }
};

class Employee : public User {
public:
    Employee(string name) : User(name) {}

    void accessLevel() override {
        cout << username << ": View Inventory" << endl;
    }
};


class Manager : public Employee {
public:
    Manager(string name) : Employee(name) {}

    void accessLevel() override {
        cout << username << ": View and Update Inventory" << endl;
    }
};


class Admin : public Manager {
public:
    Admin(string name) : Manager(name) {}

    void accessLevel() override {
        cout << username << ": Full Access (Add, Update, Delete Inventory)" << endl;
    }
};

int main() {
    Employee emp("Alice");
    Manager mgr("Bob");
    Admin adm("Charlie");

    emp.accessLevel();
    mgr.accessLevel();
    adm.accessLevel();

    return 0;
}