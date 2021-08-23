#include <iostream>
#include <vector>
#include <unordered_map>
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

class Student {
public:
    string firstname;
    string lastname;
    string rollno;
    Student(string f, string l, string r) {
        firstname = f;
        lastname = l;
        rollno = r;
    }
    bool operator==(const Student &s) const { // We make this function constant because we are not changing the data members of the class inside this function
        return rollno == s.rollno; // 2 students can have the same name but will always have different rollno
    }
};

// Custom hashfunction
class HashFunction {
public:
    size_t operator()(const Student &s) const { // size_t is an unsigned int kind of data type in C++. It represents size of memory in bytes.
        return s.firstname.length() + s.lastname.length(); // Converting string to int
    }
};

int main() {
    OJ;
    unordered_map<Student, int, HashFunction> student_map;
    Student s1("Mohammad", "Jawwad", "006");
    Student s2("Shoyeb", "Akhtar", "011");
    Student s3("Albab", "Ali", "038");
    // Student s4("Zubair", "Ahmad", "079");
    Student s5("Mohammad", "Jawwad", "106");

    // Add students and their marks to the hashmap
    student_map[s1] = 70;
    student_map[s2] = 80;
    student_map[s3] = 100;
    // student_map[s4] = 90;
    student_map[s5] = 75;

    // Get marks of a student
    cout << student_map[s5] << endl;

    // Iterate over all students
    for(auto s : student_map) {
        cout << s.first.firstname << "(" << s.first.rollno << ")" << " : " << s.second << endl;
    }

    return 0;
}