#include <iostream>
#include <string>
using namespace std;

class Product {
private: 
    int id;
    string name;
    float price;
    
public: 
   
    Product(int i, string n, float p) {
        id = i;
        name = n;
        price = p;
        cout << "Constructor called!" << endl;
    }
    

    Product() {
        id = 0;
        name = "";
        price = 0.0;
        cout << "Default constructor called!" << endl;
    }
    

    ~Product() {
        cout << "Destructor called!" << endl;
    }
    
    void printDetails() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() { 
    Product p1(101, "Notebook", 4.99);
    p1.printDetails();
    return 0;
}
