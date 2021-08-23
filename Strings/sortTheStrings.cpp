#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <map>
#include <list>
#include <queue>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define pob pop_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

string extractToken(string str, int key) {
    char* s = strtok((char *)str.c_str(), " "); // (char* )s.c_str() converts s from a string to a character array
    while(key > 1) {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

bool num(pair<string, string> &s1, pair<string, string> &s2) {
    return stoi(s1.second) < stoi(s2.second);
}

bool lex(pair<string, string> &s1, pair<string, string>&s2) {
    return s1.second < s2.second;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    cin.get();
    string a[n];
    for(int i=0; i<n; i++) {
        getline(cin, a[i]);
    }
    int key;
    string reversed;
    string comparison;
    cin >> key >> reversed >> comparison;
    pair<string, string> strPair[100];
    for(int i=0; i<n; i++) {
        strPair[i].first = a[i];
        strPair[i].second = extractToken(a[i], key);
    }
    if(comparison == "numeric") {
        sort(strPair, strPair + n, num);
    }
    else {
        sort(strPair, strPair + n, lex);
    }
    if(reversed == "true") {
        for(int i=0; i<n/2; i++) {
            swap(strPair[i], strPair[n-i-1]);
        }
    }
    for(int i=0; i<n; i++) {
        cout << strPair[i].first << endl;
    }
    return 0;
}