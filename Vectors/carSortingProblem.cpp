#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class Car {
public:
    string name;
    int x, y;
    Car() {

    }
    Car(string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }
    int distance() {
        return x * x + y * y;
    }
};

bool compare(Car A, Car B) {
    int da = A.distance();
    int db = B.distance();
    if(da == db) {
        return A.name.length() < B.name.length();
    }
    return da < db;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<Car> cab(n);
    for(int i=0; i<n; i++) {
        string name;
        int x, y;
        cin >> name >> x >> y;
        Car temp(name, x, y);
        cab[i] = temp;
    }
    sort(cab.begin(), cab.end(), compare);
    for(auto c: cab) {
        cout << "Car:" << c.name << ", Distance:" << c.distance() << ", Location:(" << c.x << ", " << c.y << ")" << endl;
    }
    cout << endl;
    return 0;
}