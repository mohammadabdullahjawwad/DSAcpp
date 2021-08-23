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

void primeSieve(int* p) {
    p[0] = p[1] = 0;
    p[2] = 1;
    for(ll i=3; i<1000006; i+=2) {
        p[i] = 1;
    }
    for(ll i=3; i<1000006; i+=2) {
        if(p[i] == 1) { // If i is prime, mark all it's multiples as not prime
            for(ll j=i*i; j<1000006; j+=i) {
                p[j] = 0;
            }
        }
    }
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int p[1000006] = {0};
    primeSieve(p);
    ll ans = 0;
    ll i = 0;
    while(n != 0) {
        if(p[i] == 1) {
            ans = i;
            n--;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}