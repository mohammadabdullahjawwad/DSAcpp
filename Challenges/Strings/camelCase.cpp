#include<bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void camelCase(char* S) {
    int ll=0, ul=0;
    if(strlen(S)) {
        cout << S[0];
    }
    for(int i=1; i<strlen(S); i++) {
        if(S[i] >= 'A' && S[i] <= 'Z') {
            cout << endl;
        }
        cout << S[i];
    }
}

int main() {
    OJ;
    FIO;
    char S[1000];
    cin >> S;
    camelCase(S);
	return 0;
}