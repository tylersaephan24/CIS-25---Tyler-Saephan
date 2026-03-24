#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Item {
public:
    string name;
    double price;
    int quantity;


    double getTotalPrice() {
        return price * quantity;
    }

   
    void saveToFile() {
        ofstream out("cart.txt", ios::app);

        if (out.is_open()) {
            out << name << " " << price << " " << quantity << endl;
            cout << "Item saved to file." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }

        out.close();
    }
};

int main() {
    int choice;

    do {
        cout << "\n==== SHOPPING CART MENU ====\n";
        cout << "1. Add item to cart\n";
        cout << "2. View checkout\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            Item item;

            cout << "Enter item name: ";
            cin >> item.name;

            cout << "Enter item price: ";
            cin >> item.price;

            cout << "Enter item quantity: ";
            cin >> item.quantity;

            item.saveToFile();

            cout << "Item added to cart.\n";
        }
        else if (choice == 2) {
            ifstream in("cart.txt");

            if (!in.is_open()) {
                cout << "Unable to open file.\n";
                continue;
            }

            string name;
            double price;
            int quantity;
            double total = 0;

            cout << "\n==== CHECKOUT ====\n";

            while (in >> name >> price >> quantity) {
                double itemTotal = price * quantity;

                cout << name << " - $" << price
                     << " x " << quantity
                     << " = $" << itemTotal << endl;

                total += itemTotal;
            }

            cout << "Total: $" << total << endl;

            in.close(); 
        }
        else if (choice == 3) {
            cout << "Thank you for shopping!" << endl;
            cout << "Exiting program safely...\n";
        }
        else {
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}