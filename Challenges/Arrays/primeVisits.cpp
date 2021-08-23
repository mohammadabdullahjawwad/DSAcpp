#include<iostream>
using namespace std;
int primeVisit(int a, int b) {
    bool prime[b+1];
    prime[0] = 0;
    prime[1] = 0;
    for(int i=2; i<=b; i++) {
        if((i%2==0) || (i<a)) {
            prime[i] = 0;
        } else {
            prime[i] = 1;
        }
    }
    if(a<=2) {
        prime[2] = 1;
    }
    for(int i=3; i<b; i+=2) {
        int j=2;
        while(i*j <= b) {
            prime[i*j] =0;
            j++;
        }
    }
    int count=0;
    for(int i=0; i<=b; i++) {
        if(prime[i]) {
            count++;
        }
    }
    return count;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << primeVisit(a, b) << endl;
    }
    return 0;
}