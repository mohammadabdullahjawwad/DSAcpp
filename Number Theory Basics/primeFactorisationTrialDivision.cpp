#include <iostream>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

// Naive Approach - O(n)
void primeFactor(int n) {
    for(int i=2; i<=n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n = n / i;
                cout << i << " ";
            }
        }
    }
    cout << endl;
}

// Optimized Approach : Factors appear in pairs - O(sqrtN)
void optimizedPrimeFactor(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n = n / i;
                cout << i << " ";
            }
        }
    }
    if(n != 1) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        exit(0);
    }
    primeFactor(n);
    optimizedPrimeFactor(n);
    return 0;
}