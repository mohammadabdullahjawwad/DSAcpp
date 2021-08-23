#include <iostream>
using namespace std;

class Car {
private:
    int price;
public:
    int model;
    char name[20];

    void start() {
        cout << "Starting the car " << name << "!!!" << endl;
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
};

int main() {

    // Initialisation of data members
    Car C;
    // C.price = -500;
    C.setPrice(2000);
    C.model = 1001;
    C.name[0] = 'B';
    C.name[1] = 'M';
    C.name[2] = 'W';
    C.name[3] = '\0';
    C.start();
    cout << C.getPrice() << endl;

    Car D;
    D.setPrice(800);
    cout << D.getPrice() << endl;
    return 0;
}