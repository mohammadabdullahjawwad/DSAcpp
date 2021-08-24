#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

vector<int> countingSort(vector<int>& a) {
    int maxm = INT_MIN;
    for(int i = 0; i < a.size(); i++) {
        maxm = max(maxm, a[i]);
    }
    vector<int> count(maxm + 1, 0);
    for(int i = 0; i < a.size(); i++) {
        count[a[i]]++;
    }
    for(int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    vector<int> res(a.size());
    for(int i = 0; i <a.size(); i++) {
        res[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    return res;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    a = countingSort(a);
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}