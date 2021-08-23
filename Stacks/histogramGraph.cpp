#include <iostream>
#include <stack>
using namespace std;

int histogram(int a[], int n) {
    stack<int> s;
    int maxarea = 0;
    int i = 0;
    while(i < n) {
        if(s.empty() || a[i] >= a[s.top()]) {
            s.push(i++);
        }
        else {
            int height = s.top();
            s.pop();
            int area = a[height] * (s.empty() ? i : (i-s.top()-1));
            if(maxarea < area) {
                maxarea = area;
            }
        }
    }
    while(!s.empty()) {
        int height = s.top();
        s.pop();
        int area = a[height] * (s.empty() ? i : (i-s.top()-1));
        if(maxarea < area) {
            maxarea = area;
        }
    }
    return maxarea;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << histogram(a, n) << endl;
    return 0;
}