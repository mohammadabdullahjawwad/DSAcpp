#include <iostream>
using namespace std;

int fact(int n) {
    if(n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

int ncr(int n, int r) {
    return fact(n)/(fact(n-r)*fact(r));
}

int main() {
    int n;
    cin >> n;
    int bst = (ncr(2*n, n))/(n+1); // This is the number of BST as well as the number of unlabelled Binary Trees
    cout << bst << endl;
    int bt = fact(n) * bst; // This is the number of Binary Trees
    cout << bt << endl;
    return 0;
}