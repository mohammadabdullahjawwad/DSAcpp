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

char* mystrtok(char* s, char delim) {
    static char* input = NULL;
    if(s) { // First call
        input = s;
    }
    // Base Case - After the final token has been returned
    if(!input) {
        return NULL;
    }
    // Start extracting tokens & store them in an array
    char* output = new char[strlen(input) + 1];
    int i = 0;
    for(; input[i]!='\0'; i++) {
        if(input[i] != delim) {
            output[i] = input[i];
        }
        else {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }
    // Corner case - Final token doesn't have a delimiter
    output[i] = '\0';
    input = NULL;
    return output;
}

int main() {
    OJ;
    FIO;
    char s[100] = "Today, is a rainy, day!";
    char* ptr = mystrtok(s, ' ');
    cout << ptr << endl;
    while(ptr) {
        ptr = mystrtok(NULL, ' ');
        cout << ptr << endl;
    }
    return 0;
}