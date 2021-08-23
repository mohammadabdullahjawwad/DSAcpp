#include <iostream>
using namespace std;

// User defined vector
class Vector {
    int *arr;
    int currentSize;
    int maxSize;
public:
    Vector(int defaultSize=4) { // We can pass the required size a parameter and it will replace the defaultSize
        maxSize = defaultSize;
        currentSize = 0;
        arr = new int[maxSize];
    }

    // Functional Object
    void operator()(string s) {
        cout << s << " is my homie!" << endl;
    }

    void push_back(int data) {
        if(currentSize == maxSize) {
            // Doubling the size of vector
            int *oldArr = arr;
            arr = new int[2*maxSize];
            maxSize *= 2;
            for(int i=0; i<currentSize; i++) {
                arr[i] = oldArr[i];
            }
            delete [] oldArr;
        }
        arr[currentSize] = data;
        currentSize++;
    }
    bool empty() {
        return currentSize == 0;
    }
    int getSize() {
        return currentSize;
    }
    int getMaxSize() {
        return maxSize;
    }
    void pop_back() {
        if(!empty()) {
            currentSize--;
        }
    }
    void print() {
        for(int i=0; i<currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int at(int i) {
        return arr[i];
    }

    // Operator overloading
    int& operator [] (int i) {
        return arr[i];
    }
};

ostream& operator << (ostream &os, Vector &v) { // Cascading of operators
    os << "In << operator" << endl;
    v.print();
    return os;
}

istream& operator>>(istream &is, Vector &v) {
    // Take input and store it
    return is;
}

int main() {
    Vector v(12); // We can pass the required size as a parameter of v (Constructor)
    v("Eminem");
    Vector fun; // Defalult Copy constructor called - Shallow copy
    
    // It is an object which looks like a function. It is called 'Functor' or 'Functional Object' in C++
    fun("Billie Ellish");
    for(int i=0; i<4; i++) {
        v.push_back(i*i);
    }
    cout << v.getMaxSize() << endl;
    v.push_back(7);
    cout << v.getMaxSize() << endl;
    v.print();
    for(int i=0; i<v.getSize(); i++) {
    //     cout << v[i] << " ";
    }
    // cout << endl;
    fun = v; // Copy assignment operator - shallow copy
    cout << v << fun;
    v[2] = 8;
    v[2] <<= 6;
    cout << v[2] << endl;
    return 0;
}