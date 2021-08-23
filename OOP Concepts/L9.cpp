#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    int price;
public:
    int model;
    char* name;
    const int tyres;

    // Constructor
    Car():name(NULL),tyres(4) { // This is initialization list. A constant data member must be initilized through it
        // Overriding the default constructor
        cout << "Making a car..." << endl;
        // tyres = 4; // This is assignment and not initialization. This will yield an error
    }

    // Parameterised Constructor
    Car(int p, int m, char* n, int t=4):price(p),model(m),tyres(t) {
        int len = strlen(n);
        name = new char[len+1];
        strcpy(name, n);
    }

    void start() const {
        cout << "Starting the car " << name << "!!!" << endl;
    }

    // Setter Function for name
    void setname(const char* n) {
        if(name == NULL) {
            name = new char[strlen(n)+1];
            strcpy(name, n);
        } else {
            // Delete the old array and allocate a new one

        }
    }

    // Copy Constructor - Makes a deep copy
    // Default copy constructor on the other hand makes a shallow copy
    Car(Car &X):tyres(X.tyres) {
        // cout << "Making a copy of car " << X.name << endl;
        int len = strlen(X.name);
        name = new char[len+1];
        strcpy(name, X.name);
        price = X.price;
        model = X.model;
    }

    // Deep Copy Assignment Operator
    void operator = (const Car &X) { // We can call this by reference as well as by value
        cout << "Inside Copy Assignment Operator" << endl;
        int len = strlen(X.name);
        name = new char[len+1];
        strcpy(name, X.name);
        price = X.price;
        model = X.model;
    }

    // Setter Function for price
    void setPrice(const int p) {
        if(p > 1000) {
            price = p;
        } else {
            price = 1000;
        }
    }

    // Getter Function for price
    int getPrice() const {
        return price;
    }

    void print() const {
        cout << name << endl;
        cout << model << endl;
        cout << price << endl << endl;
    }

    // Destructor
    ~Car() {
        cout << "Destroying the car " << name << endl;
        // Code to delete all dynamic data members
        if(name != NULL) {
            delete [] name;
        }
    }
};

int main() {

    // Initialisation of data members
    Car C;
    C.setPrice(2000);
    C.setname("BMW");
    C.model = 1001;
    // C.start();
    C.print();
    
    Car D(2500, 1000, "Lamborghini");

    Car E(4200, 101, "Audi"); // It calls the default copy constructor
    // E.name[0] = 'G';

    D = E; // Copy Assignment Operator - This will not call the copy constructor. This also makes shallow copy like default copy constructor
    D.name[0] = 'O';

    D.print();
    E.print();

    cout << E.tyres << endl;

    // We create a dynamic object
    // This heap memory does not get destroyed on exiting main() function. It has to be deleted using the 'delete' keyword
    // The destructor does not get called for a dynamic object
    Car *T = new Car(2500, 1000, "Dynamic Tesla");
    // The destructor is called here. We delete it before the other static car objects go out of scope and hence get deletd themselves
    delete T;

    return 0;
}