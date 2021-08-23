#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    int price;
public:
    int model;
    char* name;

    // Constructor
    Car() {
        // Overriding the default constructor
        name = NULL;
        cout << "Making a car..." << endl;
    }

    // Parameterised Constructor
    Car(int p, int m, char* n) {
        price = p;
        model = m;
        int len = strlen(n);
        name = new char[len+1];
        strcpy(name, n);
    }

    void start() {
        cout << "Starting the car " << name << "!!!" << endl;
    }

    // Setter Function for name
    void setname(char* n) {
        if(name == NULL) {
            name = new char[strlen(n)+1];
            strcpy(name, n);
        } else {
            // Delete the old array and allocate a new one

        }
    }

    // Copy Constructor - Makes a deep copy
    // Default copy constructor on the other hand makes a shallow copy
    Car(Car &X) {
        // cout << "Making a copy of car " << X.name << endl;
        int len = strlen(X.name);
        name = new char[len+1];
        strcpy(name, X.name);
        price = X.price;
        model = X.model;
    }

    // Setter Function for price
    void setPrice(int p) {
        if(p > 1000) {
            price = p;
        } else {
            price = 1000;
        }
    }

    // Getter Function
    int getPrice() {
        return price;
    }

    void print() {
        cout << name << endl;
        cout << model << endl;
        cout << price << endl << endl;
    }
};

int main() {

    // Initialisation of data members
    Car C;
    C.setPrice(2000);
    C.setname("Audi");
    C.model = 1001;
    // C.start();
    C.print();
    
    Car D(2500, 1000, "Lamborghini");

    Car E(D); // It calls the default copy constructor
    E.name[0] = 'G';

    D.print();
    E.print();

    return 0;
}