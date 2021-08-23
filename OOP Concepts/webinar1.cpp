#include <iostream>
using namespace std;

class Complex {
    int real;
    int imag;
public:
    Complex() {
        real = 0;
        imag = 0;
    }
    Complex(const int r, const int i) {
        real = r;
        imag = i;
    }
    void setReal(const int r) {
        real = r;
    }
    void setImag(const int i) {
        imag = i;
    }
    int getReal() const {
        return real;
    }
    int getImag() const {
        return imag;
    }
    void print() {
        if(imag >= 0) {
            cout << real << " + " << imag << "i" << endl;
        } else {
            cout << real << " - " << -imag << "i" << endl;
        }
    }
    void add(const Complex &x) {
        real += x.real;
        imag += x.imag;
    }
    void operator+(const Complex &x) { // We can pass the object by value as well. For the case of a copy constructor, we need to pass it by reference only!
        real += x.real;
        imag += x.imag;
    }
    void operator~() {
        imag *= -1;
    }
    int operator[](string s) {
        // cout << real << " + " << imag << s << endl;
        if(s == "real") {
            return real;
        } else {
            return imag;
        }
    }
};

istream& operator>>(istream &is, Complex &c) { // we can use cin instead of is
    int r, i;
    is >> r >> i;
    c.setReal(r);
    c.setImag(i);
    return is;
}

ostream& operator<<(ostream &os, Complex &c) {
    c.print();
    return os;
}

int main() {
    /* Complex C1(3, 5);
    Complex C2;
    C2.setReal(2);
    C2.setImag(6);

    C1.print();
    C2.print();
    cout << endl;

    // C1.add(C2);
    C1 + C2; // Operator overloading. The result gets stored in C1 as defined by the function
    C1.print();

    ~C1;
    C1.print();

    cout << C1["real"] << endl;
    cout << C1["imag"] << endl; */

    Complex d1, d2;
    cin >> d1 >> d2;
    cout << d1 << d2;

    return 0;
}