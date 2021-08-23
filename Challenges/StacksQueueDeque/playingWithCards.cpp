#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

void nthPrime(vector<int> &primes) {
    bool IsPrime[100005];
    memset(IsPrime, true, sizeof(IsPrime));
    for(int p=2; p*p<100005; p++) {
        if(IsPrime[p] == true) { 
            for(int i=p*p; i<100005; i+=p) {
                IsPrime[i] = false;
            }
        }
    }
    for(int p=2; p<100005; p++) {
       if(IsPrime[p]) {
           primes.push_back(p);
        }
    }
}

int main() {
    stack<int> ao;
    stack<int> ai;
    stack<int> bi;
    vector<int> primes;
    nthPrime(primes);
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++) {
        int val;
        cin >> val;
        ai.push(val);
    }
    for(int i=1; i<=q; i++) {
        ao.swap(ai);
        while(!ao.empty()) {
            if(ao.top()%primes[i-1] == 0) {
                bi.push(ao.top());
            }
            else {
                ai.push(ao.top());
            }
            ao.pop();
        }
        while(!bi.empty()) {
            cout << bi.top() << endl;
            bi.pop();
        }
    }
    while(!ai.empty()) {
        cout << ai.top() << endl;
        ai.pop();
    }
    return 0;
}