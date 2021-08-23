#include<bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

char frequency(char ch[]) {
    int size = strlen(ch);
    int max = 0;
    char result;
    int freq[128] = {0};
    for(int i=0; i<size; i++) {
        freq[ch[i]]++;
        if(max < freq[ch[i]]) {
            max = freq[ch[i]];
            result = ch[i];
        }
    }
    return result;
}

int main() {
    OJ;
    FIO;
    char ch[1000];
    cin >> ch;
    cout << frequency(ch) << endl;
	return 0;
}