#include <bits/stdc++.h>
using namespace std;

void duplicate(char *S, int n) {
    if(n == 1) {
        cout << S[strlen(S)-n];
        return;
    }
    if(S[strlen(S)-n] == S[strlen(S)-n+1]) {
        duplicate(S, n-1);
        return;
    }
    cout << S[strlen(S)-n];
    duplicate(S, n-1);
}

int main() {
    char S[1000];
    cin >> S;
    int n = strlen(S);
    duplicate(S, n);
    cout << endl;
    return 0;
}