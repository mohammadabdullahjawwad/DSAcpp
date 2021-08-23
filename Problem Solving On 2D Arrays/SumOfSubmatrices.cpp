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

// Approach 1 - Brute force
// int bruteForce(int** arr, int n, int m) {
int bruteForce(vector<vector<int>> arr, int n, int m) {
    int sum = 0;
    for(int li=0; li<n; li++) { // first 2 loops find TL
        for(int lj=0; lj<m; lj++) {
            for(int bi=li; bi<n; bi++) { // these 2 loops find BR
                for(int bj=lj; bj<m; bj++) {
                    for(int i=li; i<=bi; i++) { // traversal from TL to BR
                        for(int j=lj; j<=bj; j++) {
                            sum += arr[i][j];
                        }
                    }
                }
            }
        }
    }
    return sum;
}

// Approach 2 - Prefix sum matrix
// int prefixSum(int** arr, int n, int m) {
int prefixSum(vector<vector<int>> arr, int n, int m) {
    for(int i=0; i<n; i++) {
        for(int j=1; j<m; j++) {
            arr[i][j] += arr[i][j-1];
        }
    }
    for(int j=0; j<m; j++) {
        for(int i=1; i<n; i++) {
            arr[i][j] += arr[i-1][j];
        }
    }
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int sum = 0;
    for(int li=0; li<n; li++) { // first 2 loops find TL
        for(int lj=0; lj<m; lj++) {
            for(int bi=li; bi<n; bi++) { // these 2 loops find BR
                for(int bj=lj; bj<m; bj++) {
                    sum += arr[bi][bj];
                    if(li > 0) {
                        sum -= arr[li-1][bj];
                    }
                    if(lj > 0) {
                        sum -= arr[bi][lj-1];
                    }
                    if(li > 0 && lj > 0) {
                        sum += arr[li-1][lj-1];
                    }
                }
            }
        }
    }
    return sum;
}

// Approach 3 - Optimized solution (Contribution of each cell in final output)
// int sumOfSubmatrix(int **arr, int n, int m) {
int sumOfSubmatrix(vector<vector<int>> arr, int n, int m) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int tl = (i + 1) * (j + 1); // No of matrices for which this cell will be BR (there can be tl TLs for this cell as BR)
            int br = (n - i) * (m - j); // No of matrices for which this cell will be TL
            sum += (tl * br) * arr[i][j];
        }
    }
    return sum;
}

int main() {
    OJ;
    FIO;
    int n, m;
    cin >> n >> m;
    // int **arr = new int*[n];
    // for(int i=0; i<n; i++) {
    //     arr[i] = new int[m];
    // }
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << bruteForce(arr, n, m) << endl;
    cout << prefixSum(arr, n, m) << endl;
    cout << sumOfSubmatrix(arr, n, m) << endl;
    return 0;
}