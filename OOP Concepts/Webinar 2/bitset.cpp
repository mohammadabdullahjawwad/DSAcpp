#include <iostream>
#include <bitset>
using namespace std;

bitset<30> b;

int main() {
    b[3] = b[5] = 1; // Rest all bits are set to 0
    cout << b << endl;
    return 0;
}