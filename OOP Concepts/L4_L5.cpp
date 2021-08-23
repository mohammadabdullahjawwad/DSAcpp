#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    int price;
public:
    int model;
    string name;

    // Constructor
    Car() {
        // Overriding the default constructor
        cout << "Making a car..." << endl;
    }

    // Parameterised Constructor
    Car(int p, int m, string n) {
        price = p;
        model = m;
        name = n;
    }

    void start() {
        cout << "Starting the car " << name << "!!!" << endl;
    }

    // Copy Constructor
    Car(Car &X) {
        cout << "Making a copy of car " << X.name << endl;
        name = X.name;
        price = X.price;
        model = X.model;
    }

    // Setter Function
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
    C.model = 1001;
    C.name = "BMW";
    C.start();
    cout << C.getPrice() << endl << endl;

    Car D;
    D.setPrice(800);
    cout << D.getPrice() << endl << endl;

    Car E(4500, 205, "Maruti");
    E.print();

    // Copy constructor - Used to create a copy of a given object of the same type
    // Car F(E); // 1st way of calling the copy constructor
    Car F = E; // 2nd way of calling the copy constructor
    F.setPrice(2000);
    F.print();

    Car G(F);
    G.print();

    return 0;
}