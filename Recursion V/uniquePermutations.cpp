#include <iostream>
#include <set>
#include <string>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void permute(char* input, int i, set<string>& s) {
    // Base Case
    if(input[i] == '\0') {
        // cout << input << " ";
        string temp(input);
        s.insert(temp);
        return;
    }
    // Recursive Case
    for(int j=i; input[j]!='\0'; j++) {
        swap(input[i], input[j]);
        permute(input, i + 1, s);
        // Backtracking - To restore the original array
        swap(input[i], input[j]);
    }

}

int main() {
    OJ;
    FIO;
    char input[100];
    cin >> input;
    set<string> s;
    permute(input, 0, s);
    for(string el: s) {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}