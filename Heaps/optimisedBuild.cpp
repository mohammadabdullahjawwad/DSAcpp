#include <iostream>
#include <vector>
using namespace std;

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

void buildHeapOptimised(vector<int>& heap) {
    for(int i=heap.size()-1; i>=0; i--) {
        downheapify(heap, i);
    }
}

void display(vector<int> heap) {
    for(int i=0; i<heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> heap;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        heap.push_back(x);
    }
    buildHeapOptimised(heap);
    display(heap);
    return 0;
}