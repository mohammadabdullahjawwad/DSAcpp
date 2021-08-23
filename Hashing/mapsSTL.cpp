#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define vi vector <int>
#define pii pair <int ,int>
#define all(v) v.begin(),v.end()
#define pub push_back
#define pob pop_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    OJ;
    map<string, int> m;

    // Insert
    // First way
    m.insert(mp("Mango", 100));
    // Second way
    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);
    // Third way
    m["Banana"] = 60;

    // Iterate and print all key value pairs. (keys are lexicographically sorted)
    // First way - Iterator
    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " : " << it->second << endl; // (*it).first and (*it).second will also work fine
    }
    // Second way - For each loop
    for(auto p : m) {
        cout << p.first << " : " << p.second << endl;
    }

    // Search
    string key;
    cin >> key;
    // First way
    auto it = m.find(key); // find() returns iterator not integer
    if(it != m.end()) {
        cout << "Price of " << key << " is " << m[key] << endl;
    } else {
        cout << key << " not present" << endl;
    }
    // m[key] += 25;
    // Second way
    if(m.count(key)) { // count() returns an integer value 0 or 1 whether key is present or not
        cout << "Price of " << key << " is " << m[key] << endl;
    } else {
        cout << key << " not present" << endl;
    }

    // Erase
    m.erase(key);

    // Update
    m[key] += 25;

    return 0;
}