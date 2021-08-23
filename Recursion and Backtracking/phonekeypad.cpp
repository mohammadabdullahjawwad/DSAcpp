#include <iostream>
using namespace std;

int keypad(int n) {
    if(n == 0) {
        return 1;
    }
    int digit = n%10;
    if((digit == 0) || (digit == 1)) {
        return keypad(n/10);
    } else if((digit == 7) || (digit == 9)) {
        return 4*keypad(n/10);
    } else {
        return 3*keypad(n/10);
    }
}

int main() {
    int n;
    cin >> n;
    cout << keypad(n) << endl;
    return 0;
}