#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[10000];
    cin >> a;
    int n = strlen(a);
    int currLen = 1;
    int maxLen = 1;
    int visited[256];
    // We initilize it to -1 to make sure that no character has been visited
    for(int i=0; i<256; i++) {
        visited[i] = -1;
    }
    visited[a[0]] = 0;
    for(int i=1; i<n; i++) {
        int lastOccurrence = visited[a[i]];
        // Expansion
        if(lastOccurrence == -1 || i-currLen > lastOccurrence) {
            currLen += 1;
            if(currLen > maxLen) {
                maxLen = currLen;
            }
        }
        // Expansion + Contraction
        else {
            if(currLen > maxLen) {
                maxLen = currLen;
            }
            currLen = i - lastOccurrence;
        }
        visited[a[i]] = i;
    }
    if(currLen > maxLen) {
        maxLen = currLen;
    }
    cout << maxLen << endl;
    return 0;
}



// eg: abcdefcghijkzyxz