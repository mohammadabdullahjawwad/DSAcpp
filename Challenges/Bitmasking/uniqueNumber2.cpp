// Linear time and constant space solution
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
    int n;
    cin >> n;
    int a[n];
    int number;
    int result = 0;
    for(int i=0; i<n; i++) {
        cin >> number;
        a[i] = number;
        result ^= number;
    }
    int temp = result;
    int pos = 0;
    while((temp & 1) == 0) {
        pos++;
        temp >>= 1;
    }
    int mask = (1 << pos);
    int x = 0;
    int y = 0;
    for(int i=0; i<n; i++) {
        if((a[i] & mask) > 0) {
            x ^= a[i];
        }
    }
    y = result ^ x;
    cout << min(x, y) << " " << max(x, y) << endl;
    return 0;
}