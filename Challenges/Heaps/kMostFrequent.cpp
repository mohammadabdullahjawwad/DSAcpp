#include <bits/stdc++.h>
#include <vector>
using namespace std;

void kMostFrequent(int* v, int n, int k) {
    // Vector of size k+1 to store elements
    vector<int> top(k+1);
    unordered_map<int, int> map;
    // Iterate over the stream
    for(int j=0; j<n; j++) {
        map[v[j]]++;
        // Store the element in top vector
        top[k] = v[j];
        // Search in top vector for another instance of same element
        auto it = find(top.begin(), top.end()-1, v[j]);
        // Iterate from the position of element to zero
        for(int i=distance(top.begin(), it)-1; i>=0; i--) {
            // Compare frequency. Swap if higher frequency element stored next to it
            if(map[top[i]] < map[top[i+1]]) {
                swap(top[i], top[i+1]);
            }
            // If frequency is same, swap if next element is low
            else if(map[top[i]] == map[top[i+1]] && top[i] > top[i+1]) {
                swap(top[i], top[i+1]);
            }
            else {
                break;
            }
        }
        // Print top k elements
        for(int i=0; i<k && top[i] != 0; i++) {
            cout << top[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int *a = new int[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        kMostFrequent(a, n, k);
        delete[] a;
    }
    return 0;
}

// Heap based solution

// #include<bits/stdc++.h>
// using namespace std;

// class abc{
//     public:
//     int freq,num;
//     abc(int freq,int num)
//     {
//         this->freq=freq;
//         this->num=num;
//     }
// };
// class functor{
//     public:
//     bool operator()(abc x1,abc x2)
//     {
//         if(x1.freq==x2.freq)
//         return x1.num>x2.num;//When frequency of 2 elements is same, the smaller of the 2 elements will be at the top of the heap.
//         else 
//         return x1.freq<x2.freq;//Max heap based on frequency count
//     }
// };
// int main() {
//     int t;int n,k;
//     cin>>t;
//     int *arr;
//     while(t--)
//     {
//      priority_queue<abc,vector<abc>,functor>pq;//Preparing a priority queue of abc type(ie. based on the number and on the frequency)
//      cin>>n>>k;
//      arr=new int[n];int nn;
//      int count[100]={0};//To maintain frequency count of each number
//      for(int i=0;i<n;i++)
//      cin>>arr[i];

//      for(int i=0;i<n;i++)
//      {
//      count[arr[i]]++;
//      nn=k;
//      for(int j=0;j<=i;j++){
//      abc y(count[arr[j]],arr[j]);
//      pq.push(y);//Pushing an object of class abc(containg the number and its frequency) to the heap
//      }
//      while(!pq.empty()&&nn--)
//      {  
//          abc yy=pq.top();
//          cout<<yy.num<<" ";
//          int l1=yy.freq;
//          while(l1--)//Emptying the heap
//          pq.pop();
//      }
//      while(!pq.empty())
//      pq.pop();    
//      }
//      cout<<endl;
//     }
// 	return 0;
// }