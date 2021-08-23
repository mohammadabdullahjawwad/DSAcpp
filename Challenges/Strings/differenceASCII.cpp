#include<iostream>
#include <cstring>
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
    char S[1000];
    cin >> S;
    int i = 0;
    while(i < strlen(S)-1) {
        cout << S[i] << S[i+1] - S[i];
        i++;
    }
    cout << S[i] << endl;
	return 0;
}