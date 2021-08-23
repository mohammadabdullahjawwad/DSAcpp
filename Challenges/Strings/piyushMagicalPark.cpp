#include<iostream>
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
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    char ch[100][100];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ch[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(s >= k) {
                if(ch[i][j] == '#') {
                    break;
                }
                else if(ch[i][j] == '.') {
                    s -= 2;
                }
                else if(ch[i][j] == '*') {
                    s += 5;
                }
                if(j < m-1) {
                    s--;
                }
            }
            
        }
    }
    if(s <= k) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        cout << s << endl;
    }
	return 0;
}