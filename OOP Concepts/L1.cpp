#include <iostream>
using namespace std;

class Car {
public :
    int price;
    int model;
    char name[20];
};

int main() {
    int x;
    Car C1;
    cout << sizeof(C1) << endl; // It is an actual object and it takes space in memory
    cout << sizeof(Car) << endl; // It does not take up space. It just says that any object of this class will take up this much amount of space in memory
    Car C[100]; // It creates an array of objects of class Car
    cout << sizeof(C) << endl; // Each index of this array takes up the said amount of space in memory
    return 0;
}