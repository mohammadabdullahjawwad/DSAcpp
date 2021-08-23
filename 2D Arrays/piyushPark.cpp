#include <iostream>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void magic(vector<vector<char>> a, int r, int c, int k, int s) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(s < k) {
                cout << "No" << endl;
                return;
            }
            if(a[i][j] == '*') {
                s += 5;
            }
            else if(a[i][j] == '.') {
                s -= 2;
            }
            else {
                break;
            }
            if(j != c - 1) {
                s --;
            }
        }
    }
    cout << "Yes" << endl;
    cout << s << endl;
}

int main() {
    OJ;
    FIO;
    int r, c, k, init;
    cin >> r >> c >> k >> init;
    vector<vector<char>> a;
    for(int i=0; i<r; i++) {
        vector<char> v;
        for(int j=0; j<c; j++) {
            char x;
            cin >> x;
            v.push_back(x);
        }
        a.push_back(v);
    }
    magic(a, r, c, k, init);
    return 0;
}