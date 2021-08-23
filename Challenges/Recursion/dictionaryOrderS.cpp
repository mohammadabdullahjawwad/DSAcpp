#include <bits/stdc++.h>
using namespace std;

vector<string> result;

void order(string input, string output, int i) {
    // Base Case
    if(input[i] == '\0') {
        output[i] = '\0';
        if(input > output) {
            result.push_back(output);
            return;
        }
    }
    // Recursive Case
    for(int j=i; output[j]!='\0'; j++) {
        swap(output[i], output[j]);
        order(input, output, i+1);
        // Backtracking
        swap(output[i], output[j]);
    }
}

int main() {
    string input;
    cin >> input;
    string output;
    output = input;
    order(input, output, 0);
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}