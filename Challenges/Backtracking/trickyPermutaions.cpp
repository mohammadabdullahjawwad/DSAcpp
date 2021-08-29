#include <bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

vector<string> output;

void permutations(string& str, int i) {
    if(i == str.length()) {
        output.push_back(str);
        return;
    }
    for(int j = i; j < str.length(); j++) {
        swap(str[i], str[j]);
        permutations(str, i + 1);
        swap(str[i], str[j]);
    }
}

int main() {
    OJ;
    FIO;
    string str;
    cin >> str;
    permutations(str, 0);
    sort(output.begin(), output.end());
    cout << output[0] << endl;
    for(int i = 1; i < output.size(); i++) {
        if(output[i] != output[i - 1]) {
            cout << output[i] << endl;
        }
    }
    return 0;
}