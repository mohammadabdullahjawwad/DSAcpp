#include <iostream>
using namespace std;
float squareRoot(int n, int p) {
    int s = 0;
    int e = n;
    float ans = -1;
    // Integral Part
    while (s <= e) {
        int m = (s+e)/2;
        if(m*m == n) {
            return m;
        }
        if(m*m < n) {
            ans = m;
            s = m+1;
        }
        else {
            e = m-1;
        }
    }
    // Fractional Part
    float inc = 0.1;
    for(int i=0; i<p; i++) {
        while (ans*ans <= n) {
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }
    return ans;
}
int main() {
    int n, p;
    cin >> n >> p;
    cout << squareRoot(n, p) << endl;
    return 0;
}