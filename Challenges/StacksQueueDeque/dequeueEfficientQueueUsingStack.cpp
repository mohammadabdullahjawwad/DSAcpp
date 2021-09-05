#include <iostream>
#include <stack>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class queue {
    stack<int> a;
    stack<int> b;

public:

    void enqueue(int i) {
        while(!a.empty()) {
            b.push(a.top());
            a.pop();
        }
        a.push(i);
        while(!b.empty()) {
            a.push(b.top());
            b.pop();
        }
    }

    void dequeue() {
        int i = a.top();
        a.pop();
        cout << i << " ";
    }
};

int main() {
    OJ;
    FIO;
    queue q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        q.enqueue(i);
    }
    for(int i=0; i<n; i++) {
        q.dequeue();
    }
    cout << endl;
    return 0;
}