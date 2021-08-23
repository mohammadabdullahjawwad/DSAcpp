#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
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

class node {
public:
    char data;
    unordered_map<char, node*> children;
    bool terminal;
    int cnt; // Stores the total occurrences of the node as prefix in all strings of the array
    node(char d) {
        data = d;
        terminal = false;
        cnt = 0;
    }
};

class Trie {
public:
    node* root;
    int count; // Number of words in the trie
    Trie() {
        root = new node('\0');
        count = 0;
    }
    void insert(char* w) {
        node* temp = root;
        for(int i=0; w[i]!='\0'; i++) {
            char ch = w[i];
            if(temp->children.count(ch)) {
                temp = temp->children[ch];
            }
            else {
                node* n = new node(ch);
                temp->children[ch] = n;
                temp = n;
            }
            temp->cnt++;
        }
        temp->terminal = true;
    }
    bool find(char* w) {
        node* temp = root;
        for(int i=0; w[i]!='\0'; i++) {
            char ch = w[i];
            if(temp->children.count(ch) == 0) {
                return false;
            }
            else {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};

vector<string> uniquePrefix(vector<string> input) {
    Trie t;
    vector<string> output;
    int n = input.size();
    for(int i=0; i<n; i++) {
        int m = input[i].length();
        char charr[m+1];
        strcpy(charr, input[i].c_str()); // Converts string to character array since we have defined Trie functions for character array
        t.insert(charr);
    }
    for(int i=0; i<n; i++) {
        string str = input[i];
        vector<char> v;
        node* temp = t.root;
        bool flag = 0;
        for(int j=0; str[j]!='\0'; j++) {
            if(!temp->children[str[j]]) {
                break;
            }
            else {
                v.push_back(str[j]);
                if(temp->children[str[j]]->cnt == 1) {
                    flag = 1;
                    break;
                }
                else {
                    temp = temp->children[str[j]];
                }
            }
        }
        if(!flag) {
            v.clear();
        }
        v.push_back('\0');
        string s(v.begin(), v.end()-1); // Last character is '\0'. Hence we don't include it in string
        output.push_back(s);
    }
    return output;
}

int main() {
    OJ;
    int n;
    cin >> n;
    vector<string> input;
    for(int i=0; i<n; i++) {
        string in;
        cin >> in;
        input.push_back(in);
    }
    vector<string> output = uniquePrefix(input);
    for(int i=0; i<n; i++) {
        cout << output[i] << endl;
    }
    return 0;
}