#include<iostream>
#include<cstring>
using namespace std;

bool prime[100000001];

int main() {
    memset(prime, true, sizeof(prime));
    for(int i=2; i*i<=100000000; i++) {
        if(prime[i] == true) {
            for(int j=i*i; j<=100000000; j+=i) {
                prime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    int ans = 0;
    for(int i=2; i<=100000000; i++) {
        if(n && prime[i] == true) {
            ans = i;
            n--;
        }
    }
    cout << ans << endl;
    return 0;
}