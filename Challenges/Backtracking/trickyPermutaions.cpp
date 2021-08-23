#include <bits/stdc++.h>
using namespace std;

vector<string> output;

void permutations(char str[], int i) {
    if(str[i] == '\0') {
        output.push_back(str);
        return;
    }
    for(int j=i; str[j]!='\0'; j++) {
        swap(str[i], str[j]);
        permutations(str, i+1);
        swap(str[i], str[j]);
    }
}

int main() {
    char str[9];
    cin >> str;
    permutations(str, 0);
    sort(output.begin(), output.end());
    cout << output[0] << endl;
    for(int i=1; i<output.size(); i++) {
        if(output[i] != output[i-1]) {
            cout << output[i] << endl;
        }
    }
    return 0;
}