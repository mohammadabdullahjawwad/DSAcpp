#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool isValidConfig(int *book, int n, int m, int ans) {
    int student = 1;
    int pages = 0;
    for(int i=0; i<n; i++) {
        if(pages + book[i] > ans) {
            pages = book[i];
            student++;
            if(student > m) {
                return false;
            }
        }
        else {
            pages += book[i];
        }
    }
    return true;
}

int page(int *book, int n, int m) {
    int sum = 0;
    int s = 0;
    for(int i=0; i<n; i++) {
        sum += book[i];
        s = max(s, book[i]);
    }
    int e = sum;
    int ans = s;
    while(s <= e) {
        int mid = s + (e - s) / 2;
        if(isValidConfig(book, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int book[n];
        for(int i=0; i<n; i++) {
            cin >> book[i];
        }
        cout << page(book, n, m) << endl;
    }
}