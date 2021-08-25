#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int assignment(int i) {
    if(i == 0 || i == 1) {
        return i;
    }
    return assignment(i - 1) + assignment(i - 2);
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    int i = 1;
    while(t--) {
        int n;
        cin >> n;
        cout << "#" << i++ << " : " << assignment(n + 2) << endl;
    }
    return 0;
}