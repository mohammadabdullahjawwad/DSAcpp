template<typename T>
class Vector {
    int cs;
    int ms;
    T* arr;
public:
    Vector() {
        cs = 0;
        ms = 1;
        arr = new T[ms];
    }
    void push_back(const T d) {
        // If old array is full
        if(cs == ms) {
            T* oldArr = arr;
            arr = new T[2 * ms];
            ms *= 2;
            for(int i = 0; i<cs; i++) {
                arr[i] = oldArr[i];
            }
            // Clear old memory
            delete[] oldArr;
        }
        arr[cs] = d;
        cs++;
    }
    void pop_back() {
        cs--;
    }
    T front() const {
        return arr[0];
    }
    T back() const {
        return arr[cs-1];
    }
    bool empty() const {
        return cs == 0;
    }
    int capacity() const {
        return ms;
    }
    int size() const {
        return cs;
    }
    T at(const int i) {
        return arr[i];
    }
    // Operator overloading
    T operator[](const int i) {
        return arr[i];
    }
};