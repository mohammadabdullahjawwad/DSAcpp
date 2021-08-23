#include <iostream>
#include <vector>
#include <string.h>
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
#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

class node {
public:
    char data;
    unordered_map<char, node*> children;
    bool terminal;
    node(int d) {
        data = d;
        terminal = false;
    }
};

class Trie {

public:

    node *root;
    int count; // No of words in the trie
    
    Trie() {
        root = new node('\0');
        count = 0;
    }

    void insert(string w) {
        node * temp = root;
        for(int i=0; i<w.size(); i++) {
            char ch = w[i];
            if(temp->children.count(ch)) {
                temp = temp->children[ch];
            }
            else {
                node* n = new node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    void helper(node* temp, string pre) {
        if(temp->terminal) {
            cout << pre << endl;
        }
        for(char i='a';i<='z';i++){
            if(temp->children.count(i)==1) {
                helper(temp->children[i], pre+i);
            }
        }
    }

    void display(string w) {
        string pre = w;
        node* temp = root;
        for(int i=0; i<w.length(); i++) {
            char ch = w[i];
            if(temp->children.count(ch)) {
                temp = temp->children[ch];
            }
            else {
                insert(pre);
                cout << "No suggestions" << endl;
                return;
            }
        }
        helper(temp, pre);
    }

};

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    Trie t;
    while (n--) {
        string str;
        cin >> str;
        t.insert(str);
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        t.display(s);
    }
    return 0;
}