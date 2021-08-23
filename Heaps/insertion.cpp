#include <iostream>
#include <vector>
using namespace std;

// For Max Heap
void upheapify(vector<int>& heap, int child) {
    if(child == 0) {
        return;
    }
    int parent = (child-1)/2;
    if(heap[child] > heap[parent]) {
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        upheapify(heap, parent);
    } else {
        return;
    }
}

void insert(vector<int> &heap, int key) {
    heap.push_back(key);
    upheapify(heap, heap.size() - 1);
}

void display(vector<int> heap) {
    for(int i=0; i<heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> heap;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        insert(heap, x);
    }
    display(heap);
    return 0;
}