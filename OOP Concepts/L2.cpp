#include <iostream>
// #include <string.h>
using namespace std;

class Car {
public:
    int price;
    int model;
    char name[20];
    // string name;

    void start() {
        cout << "Starting the car " << name << "!!!" << endl;
    }
};

int main() {

    // Initialisation of data members
    Car C;
    C.price = 500;
    C.model = 1001;
    C.name[0] = 'B';
    C.name[1] = 'M';
    C.name[2] = 'W';
    C.name[3] = '\0';
    // C.name = "BMW";

    // Calling a member function
    C.start();
    return 0;
}