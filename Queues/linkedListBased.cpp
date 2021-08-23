#include <iostream>
#include <list>
using namespace std;

class Queue {
    int cs;
    list<int> queue;
public:
    Queue() {
        this->cs = 0;
    }
    // No need for isFull() function as list STL keeps evergrowing
    bool isEmpty() {
        return this->cs == 0;
    }
    void enqueue(int data) {
        this->queue.push_back(data);
        this->cs += 1;
    }
    void dequeue() {
        if(!isEmpty()) {
            this->queue.pop_front();
            this->cs -= 1;
        }
    }
    int getFront() {
       this->queue.front();
    }
};

int main(int argc, char const *argv[]) {
    Queue q(10);
    for (int i = 1; i <= 6; i++) {
        q.enqueue(i);
    }
    q.dequeue();
    q.enqueue(8);
    while (!q.isEmpty()) {
        cout << q.getFront() << endl;
        q.dequeue();
    }
    return 0;
}

// This code has compilation error. It needs to be reviewed.