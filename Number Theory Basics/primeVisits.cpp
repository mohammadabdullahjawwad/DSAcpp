#include <iostream>
using namespace std;

#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void primeSieve(bool* p) {
    // Mark all odd numbers as prime
    for(ll i=3; i<=1000006; i+=2) {
        p[i] = true;
    }
    for(ll i=3; i<=1000006; i+=2) {
        if(p[i] == true) { // If i is prime, mark all it's multiples as not prime
            for(ll j=i*i; j<=1000006; j+=i) {
                p[j] = false;
            }
        }
    }
    p[2] = true;
    p[1] = p[0] = false;
}


int main() {
    OJ;
    FIO;
    bool p[1000006] = {0};
    primeSieve(p);
    int csum[1000006] = {0};
    for(int i=0; i<1000006; i++) {
        csum[i] = csum[i-1] + p[i];
    }
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        cout << csum[b] - csum[a-1] << endl;
    }
    return 0;
}