#include <iostream>
using namespace std;

int assignment(int i) {
    if((i == 0) || (i == 1)) {
        return i;
    }
    return assignment(i-1) + assignment(i-2);
}

int main() {
    int t;
    cin >> t;
    int i = 1;
    while(t--) {
        int n;
        cin >> n;
        cout << "#" << i++ << " : " << assignment(n+2) << endl;
    }
    return 0;
}