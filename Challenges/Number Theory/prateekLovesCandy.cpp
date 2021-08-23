#include<iostream>
#include<cstring>
using namespace std;

bool all[1000001];
int prime[1000001];

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main() {
    OJ;
    FIO;
    memset(all, true, sizeof(all));
    all[0] = false;
    all[1] = false;
    for(int i=2; i*i<=1000000; i++) {
        if(all[i] == true) {
            for(int j=i*i; j<=1000000; j+=i) {
                all[j] = false;
            }
        }
    }
    memset(prime, 0, sizeof(prime));
    int count = 0;
    for(int i=2; i<=1000000; i++) {
        if(all[i] == true) {
            prime[count] = i;
            count++;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << prime[n-1] << endl;
    }
    return 0;
}