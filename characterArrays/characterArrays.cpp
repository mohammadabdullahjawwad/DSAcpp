#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main() {
    OJ;
    FIO;
    int b[] = {1, 2, 3};
    cout << b << endl; // Prints the addres of b[0] (starting address) [default behaviour]
    char a[] = { 'a', 'b', 'c', 'd', 'e', '\0'};
    cout << a << endl; // Prints the contents of the array till we find a '\0'. This is due to << operator overloading [special behaviour]

    char s[10];
    cin.getline(s, 10); // Loop not required to accept characters one by one. '\0' automatically added at the end of s. s = string taken as input, 10 = maximum size of s
    cout << s << endl;

    char s1[] = {'h', 'e', 'l', 'l', 'o'};
    char s2[] = "hello";
    cout << s1 << " : " << sizeof(s1) << endl; // size = 5
    cout << s2 << " : " << sizeof(s2) << endl; // size = 6

    char s3[10] = "hello";

    return 0;
}