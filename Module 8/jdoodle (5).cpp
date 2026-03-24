#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

int binarySearch(Patient patients[], int size, int searchID) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (patients[mid].id == searchID)
            return mid;

        if (patients[mid].id < searchID)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void addPatient(Patient patients[], int &count) {
    cout << "Enter Patient ID: ";
    cin >> patients[count].id;

    cout << "Enter Name: ";
    cin >> patients[count].name;

    cout << "Enter Age: ";
    cin >> patients[count].age;

    cout << "Enter Gender: ";
    cin >> patients[count].gender;

    cout << "Enter Diagnosis: ";
    cin >> patients[count].diagnosis;

    count++;
}


void displayPatients(Patient patients[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "\nID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << endl;
    }
}


void updatePatient(Patient patients[], int count) {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    int index = binarySearch(patients, count, id);

    if (index != -1) {
        cout << "Enter new name: ";
        cin >> patients[index].name;

        cout << "Enter new age: ";
        cin >> patients[index].age;

        cout << "Enter new gender: ";
        cin >> patients[index].gender;

        cout << "Enter new diagnosis: ";
        cin >> patients[index].diagnosis;
    } else {
        cout << "Patient not found\n";
    }
}


void saveToFile(Patient patients[], int count) {
    ofstream file("patients.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        file << patients[i].id << " "
             << patients[i].name << " "
             << patients[i].age << " "
             << patients[i].gender << " "
             << patients[i].diagnosis << endl;
    }

    file.close();
    cout << "Data saved to file.\n";
}

void loadFromFile(Patient patients[], int &count) {
    ifstream file("patients.txt");

    if (!file) return;

    while (file >> patients[count].id
                >> patients[count].name
                >> patients[count].age
                >> patients[count].gender
                >> patients[count].diagnosis) {
        count++;
    }

    file.close();
}


int main() {
    Patient* patients = new Patient[100]; 
    int count = 0;
    int choice;

    loadFromFile(patients, count); 

    do {
        cout << "\n==== HOSPITAL MENU ====\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient\n";
        cout << "5. Save to File\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient(patients, count);
                break;

            case 2:
                displayPatients(patients, count);
                break;

            case 3: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;

                int result = binarySearch(patients, count, id);

                if (result != -1) {
                    cout << "\nPatient Found\n";
                    cout << "ID: " << patients[result].id << endl;
                    cout << "Name: " << patients[result].name << endl;
                    cout << "Age: " << patients[result].age << endl;
                } else {
                    cout << "\nPatient not found\n";
                }
                break;
            }

            case 4:
                updatePatient(patients, count);
                break;

            case 5:
                saveToFile(patients, count);
                break;

            case 6:
                cout << "Good Bye!\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 6);

    delete[] patients; 
    return 0;
}