#include <iostream>
#include <cstring>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn[] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void check(char* output) {
    int lenout = strlen(output);
    for(int i=0; i<sizeof(searchIn)/sizeof(string); i++) {
        int len = searchIn[i].length();
        for(int j=0; j<len-lenout; j++) {
            int k;
            for(k=0; k<lenout; k++) {
                if(searchIn[i][j+k] != output[k]) {
                    break;
                }
            }
            if(k == lenout) {
                cout << searchIn[i] << endl;
            }
        }
    }
    return;
}

void keys(char* input, char* output, int i, int j) {
    if(input[i] == '\0') {
        output[j] = '\0';
        check(output);
        return;
    }
    int digit = input[i] - '0';
    for(int k=0; table[digit][k]!='\0'; k++) {
        output[j] = table[digit][k];
        keys(input, output, i+1, j+1);
    }
}

int main() {
    OJ;
    FIO;
    char input[100];
    char output[100];
    cin >> input;
    keys(input, output, 0, 0);
    return 0;
}