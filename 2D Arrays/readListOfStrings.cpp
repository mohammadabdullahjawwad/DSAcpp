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
    char a[100][1000];
    int n;
    cin >> n;
    cin.get(); // To consume the extra space followed by n above
    for(int i=0; i<n; i++) {
        cin.getline(a[i], 1000);
    }
    for(int i=0; i<n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}