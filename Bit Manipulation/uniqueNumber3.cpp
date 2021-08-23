#include <iostream>
using namespace std;

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
    int count[64] = {0};
    int n;
    cin >> n;
    int number;
    for(int i=0; i<n; i++) {
        cin >> number;
        int j = 0;
        while(number > 0) {
            int lbit = (number & 1);
            count[j] += lbit;
            j++;
            number >>= 1;
        }
    }
    int p = 1;
    int ans = 0;
    for(int i=0; i<64; i++) {
        count[i] %= 3;
        ans += count[i] * p;
        p <<= 1;
    }
    cout << ans << endl;
    return 0;
}