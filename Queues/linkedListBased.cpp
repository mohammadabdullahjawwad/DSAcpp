#include <iostream>
#include <list>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class Queue {
    int cs;
    list<int> l;
public:
    Queue() {
       cs = 0;
    }
    // No need for isFull() function as list STL keeps evergrowing and will never be full
    bool isEmpty() {
        return cs == 0;
    }
    void push(int data) {
        l.push_back(data);
        cs++;
    }
    void pop() {
        if(!isEmpty()) {
            l.pop_front();
            cs--;
        }
    }
    int front() {
       return l.front();
    }
};

int main(int argc, char const *argv[]) {
    OJ;
    FIO;
    Queue q;
    for (int i = 1; i <= 10; i++) {
        q.push(i);
    }
    while (!q.isEmpty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}

// This code has compilation error. It needs to be reviewed.