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

void downheapifyHelper(vector<int>& heap, int parent, int heapSize) {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    if(left >= heapSize && right >= heapSize) {
        return;
    }
    int largest = parent;
    if(left < heapSize && heap[left] > heap[largest]) {
        largest = left;
    }
    if(right < heapSize && heap[right] > heap[largest]) {
        largest = right;
    }
    if(largest == parent) {
        return;
    }
    swap(heap[largest], heap[parent]);
    downheapifyHelper(heap, largest, heapSize);
}

void heapsort(vector<int>& a) {
    int heapSize  = a.size();
    buildHeapOptimised(a);
    for(int i=a.size()-1; i>=0; i--) {
        swap(a[0], a[i]);
        heapSize-=1;
        downheapifyHelper(a, 0, heapSize);
    }
}

void display(vector<int> heap) {
    for(int i=0; i<heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    heapsort(a);
    display(a);
    return 0;
}