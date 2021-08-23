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

int main() {
    OJ;
    FIO;
    char s[100] = "Today is a rainy day!";
    char* ptr = strtok(s, " "); // Surprising fact : we cannot use ' ' instead of " " because the required argument is a character array (i.e. a string) not a single character accorfing to strtok() function definition
    while(ptr) {
        cout << ptr << endl;
        ptr = strtok(NULL, " ");
    }
    return 0;
}