#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
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

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
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

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
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

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string minWindowSubstring(string str, string pat) {
    int lstr = str.size();
    int lpat = pat.size();
    if(lstr < lpat) {
        cout << "No String" << endl;
        return "";
    }
    int hashstr[256] = {0};
    int hashpat[256] = {0};
    for(int i = 0; i < lpat; i++) {
        hashpat[pat[i]]++;
    }
    int start = 0, startIdx = -1, minLen = INT_MAX, count = 0;
    for(int i = 0; i < lstr; i++) {
        hashstr[str[i]]++;
        // Checking frequency of character in str and pat
        if(hashpat[str[i]] != 0 && hashstr[str[i]] <= hashpat[str[i]]) {
            count++;
        }
        if(count == lpat) {
            // Frequency of character should be > 0 & less than or equal to the frequency in pat string
            while(hashstr[str[start]] > hashpat[str[start]] || hashpat[str[start]] == 0) {
                if(hashstr[str[start]] > hashpat[str[start]]) {
                    // Decrease its frequency by 1 since we will shrink the window
                    hashstr[str[start]]--;
                }
                // Shrink the window
                start++;
            }
            // Length of window
            int length = i - start + 1;
            if(minLen > length) {
                minLen = length;
                // We change the answer string
                startIdx = start;
            }
        }
    }
    if(startIdx == -1) {
        cout << "No String" << endl;
        return "";
    }
    return str.substr(startIdx, minLen);
}

int main() {
    OJ;
    FIO;
    string str;
    getline(cin, str);
    string pat;
    getline(cin, pat);
    cout << minWindowSubstring(str, pat) << endl;
    return 0;
}