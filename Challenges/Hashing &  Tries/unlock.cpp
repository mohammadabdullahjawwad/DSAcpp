#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void unlock(int*& a, int n, int k) {
    unordered_map<int, int> um;
    for(int i=0; i<n; i++) {
        um.insert(mp(a[i], i));
    }
    for(int i=0; i<n; i++) {
        if(k) {
            int num = n - i; // We start by pushing largest number to its correct place
            int pos = um[num]; // Finding initial index of number
            int best = n - num; // Finding best possible index for number
            if(pos != best) {
                swap(a[pos], a[best]);
                swap(um[a[pos]], um[a[best]]); // Reflect the change in indices in the unordered_map as well
                k--;
            }
        }
    }
}

int main() {
    OJ;
    FIO;
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    unlock(a, n, k);
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}