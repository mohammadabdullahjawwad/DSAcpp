#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void primeSieve(vector<bool>& p) {
    p[0] = p[1] = false;
    p[2] = true;
    // Mark all odd numbers as prime
    for(ll i=3; i<=1000006; i+=2) {
        p[i] = true;
    }
    for(ll i=3; i<=1000006; i+=2) { // Iterate only over odd numbers
        if(p[i] == true) { // If i is prime, mark all it's multiples as not prime
            for(ll j=i*i; j<=1000006; j+=i) {
                p[j] = false;
            }
        }
    }
}

void factor(int n, vector<int>& prime) {
    int no = prime[0];
    int i = 0;
    while(no * no <= n) {
        if(n % no == 0) {
            while(n % no == 0) {
                cout << no << " ";
                n = n / no;
            }
        }
        i++;
        no = prime[i];
    }
    if(n != 1) {
        cout << n << " ";
    }
    cout << endl;
}


int main() {
    OJ;
    FIO;
    vector<bool> p(1000006, 0);
    primeSieve(p);
    vector<int> prime;
    for(int i=0; i<1000006; i++) {
        if(p[i]) {
            prime.push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        factor(n, prime);
    }
    return 0;
}