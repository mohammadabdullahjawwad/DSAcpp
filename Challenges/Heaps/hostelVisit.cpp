#include <iostream>
#include <queue>
using namespace std;

#define ll long long int

ll dis(ll x, ll y) {
    return x*x + y*y;
}

int main() {
    int q, k;
    cin >> q >> k;
    priority_queue<ll> distance;
    while(q--) {
        int input;
        cin >> input;
        if(input == 1) {
            ll x, y;
            cin >> x >> y;
            if(distance.size() == k) {
                if(dis(x, y) < distance.top()) {
                    distance.pop();
                    distance.push(dis(x, y));
                }
            }
            else {
                distance.push(dis(x, y));
            }
        }
        else {
            cout << distance.top() << endl;
        }
    }
    return 0;
}