#include <bits/stdc++.h>
#include <vector>
using namespace std;

// For Max Heap
void upheapify(vector<int>& heap, int child) {
    if(child == 0) {
        return;
    }
    int parent = (child-1)/2;
    if(heap[child] > heap[parent]) {
        swap(heap[child], heap[parent]);
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

void downheapify(vector<int>& heap, int parent) {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    if(left >= heap.size() && right >= heap.size()) {
        return;
    }
    int largest = parent;
    if(left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }
    if(right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }
    if(largest == parent) {
        return;
    }
    swap(heap[largest], heap[parent]);
    downheapify(heap, largest);
}

void deletePeek(vector<int>& heap) {
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    downheapify(heap, 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> heap;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        insert(heap, x);
    }
    display(heap);
    deletePeek(heap);
    display(heap);
    return 0;
}
