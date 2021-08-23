#include <iostream>
#include <string.h>
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
    char a[1000];
    char ans[1000];
    cin.get(); // this let's us accept all n strings. without this, only n-1 strings are accepted as it will consider empty string terminated by '\n' as 1 string
    for(int i=0; i<n; i++) {
        cin.getline(a, 1000);
        // cout << a << endl;
        if(strlen(a) > strlen(ans)) {
            strcpy(ans, a); // contents of a are copied to ans
        }
    }
    cout << ans << endl;
    cout << strlen(ans) << endl;
    return 0;
}