#include <iostream>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void insertionSort(vector<int>& a) {
    int n = a.size();
    for(int i=0; i<n; i++) {
        int j = i-1;
        int number = a[i];
        while(j>=0 && a[j]>number) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = number;
    }
}

int main() {
    OJ;
    FIO;
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0; i<n; i++) {
	    int x;
        cin >> x;
        a.push_back(x);
	}
    insertionSort(a);
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
	return 0;
}
