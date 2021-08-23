#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

// Naive Approach - O(sqrtN) to find one number
bool isPrime(int n) {
    if(n == 1) {
        return false;
    }
    if(n == 2) {
        return false;
    }
    for(int i=2; i*i<n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

// Sieve of Eratosthenes - O(loglogN) to find n numbers
void primeSieve(int* p, int n) {
    // Mark all odd numbers as prime
    for(int i=3; i<=n; i+=2) {
        p[i] = 1;
    }
    for(int i=3; i<=n; i+=2) {
        if(p[i] == 1) { // If i is prime, mark all it's multiples as not prime
            for(int j=i*i; j<=n; j+=i) {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
}


int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int p[n+1] = {0};
    primeSieve(p, n);
    for(int i = 0; i<=n; i++) {
        if(p[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}