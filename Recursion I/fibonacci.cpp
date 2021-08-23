#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}    

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}