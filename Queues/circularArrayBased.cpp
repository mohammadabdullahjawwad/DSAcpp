#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class Queue {

    int* arr;
    int ms; // Maximum Size
    int cs; // Current Size
    int frontEl;
    int rear;

public:
    
    Queue(int defaultSize = 7) {
        // this->arr = new int[this->ms]();
        arr = new int[defaultSize];
        cs = 0;
        ms = defaultSize;
        frontEl = 0;
        rear = ms - 1;
    }

    bool full() {
        return cs == ms;
    }

    bool empty() {
        return cs == 0;
    }

    void push(int data) {
        if(!full()) {
            rear = (rear + 1) % ms;
            arr[rear] = data;
            cs++;
        }
    }

    void pop() {
        if(!empty()) {
            frontEl = (frontEl + 1) % ms;
            cs--;
        }

    }

    int front() {
        return arr[frontEl];
    }

    ~Queue() {
        if(arr != NULL) {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main() {
    OJ;
    FIO;
    Queue q(10);
    for (int i = 1; i <= 6; i++) {
        q.push(i);
    }
    q.pop();
    q.push(8);
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}