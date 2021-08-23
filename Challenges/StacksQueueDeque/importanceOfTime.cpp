#include <iostream>
#include <queue>
using namespace std;

// Approach 1 : Using Deque
int main() {
    deque<int> dq;
    int n;
    cin >> n;
    int a[n];
    // For calling order
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        dq.push_back(input);
    }
    // For ideal order
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int time = 0;
    int i = 0;
    while(i < n) {
        if(a[i] == dq.front()) {
            dq.pop_front();
            i++;
        }
        else {
            int x = dq.front();
            dq.pop_front();
            dq.push_back(x);
        }
        time++;
    }
    cout << time << endl;
    return 0;
}



// Approach 2 : Using Queue
int main() {
    queue<int> dq;
    int n;
    cin >> n;
    int a[n];
    // For calling order
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        dq.push(input);
    }
    // For ideal order
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int time = 0;
    int i = 0;
    while(i < n) {
        if(a[i] == dq.front()) {
            dq.pop();
            i++;
        }
        else {
            int x = dq.front();
            dq.pop();
            dq.push(x);
        }
        time++;
    }
    cout << time << endl;
    return 0;
}

// Both approaches are essentially the same