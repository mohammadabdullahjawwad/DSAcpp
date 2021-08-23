#include <iostream>
using namespace std;

void parenthesis(char arr[], int o, int c, int i, int n) {
    if(i == 2*n) {
        arr[i] = '\0';
        cout << arr << endl;
        return;
    }
    if(c < o) {
        arr[i] = ')';
        parenthesis(arr, o, c+1, i+1, n);
    }
    if(o < n) {
        arr[i] = '(';
        parenthesis(arr, o+1, c, i+1, n);
    }
}

int main() {
    int n;
    cin >> n;
    char arr[25];
    parenthesis(arr, 0, 0, 0, n);
    return 0;
}