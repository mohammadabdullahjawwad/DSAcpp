#include<iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void WavePrint(int a[][10], int m, int n) {
    for(int j=0; j<n; j++) {
        if(j & 1) {
            for(int i=m-1; i>=0; i--) {
                cout << a[i][j] << ", ";
            }
        } else {
            for(int i=0; i<m; i++) {
                cout << a[i][j] << ", ";
            }
        }
    }
    cout << "END" << endl;
}

int main() {
    OJ;
    FIO;
    int m, n;
    cin >> m >> n;
    int a[10][10];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    WavePrint(a, m, n);
	return 0;
}