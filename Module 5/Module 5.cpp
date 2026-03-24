#include <iostream>  
#include <cmath>     
using namespace std;

void addNumbers();
void multiplyNumbers();
void findSquareRoot();

int main() {
    int choice;


    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Add Two Numbers\n";
        cout << "2. Multiply Two Numbers\n";
        cout << "3. Find Square Root\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        
        switch(choice) {
            case 1:
                addNumbers();
                break;
            case 2:
                multiplyNumbers();
                break;
            case 3:
                findSquareRoot();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 4); 

    return 0;
}

void addNumbers() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Sum = " << a + b << endl;
}


void multiplyNumbers() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Product = " << a * b << endl;
}


void findSquareRoot() {
    double num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Square root = " << sqrt(num) << endl;
}