/*
  Vector Class
  Demonstrates:
     Good example of copy control
     Dynamic arrays and pointer arithmetic
     Square bracket operator
     Implementation of an important data structure
 */
#include <iostream>
using namespace std;

class Vector {
public:
    Vector() {
        theSize = 0;
        theCapacity = 0;
        data = nullptr;
    }
    explicit Vector(size_t size, int value = 0) {
        theSize = theCapacity = size;
        data = new int[theSize];
        for (size_t index = 0; index < theSize; ++index) {
            data[index] = value;
        }
    }

    //
    // Copy control
    //

    // Destructor
    ~Vector() {
        //delete data; // No, wrong
        delete[] data;
    }

    // Copy Constructor
    // Vector(const Vector& rhs);
    Vector(const Vector& rhs) {
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];
        for (size_t index = 0; index < theSize; ++index) {
            //*(data + index) = *(rhs.data + index);
            data[index] = rhs.data[index];
        }
    }
   
    // Assignment operator
    // Vector& operator=(const Vector& rhs);
    Vector& operator=(const Vector& rhs) {
        // 0. check for self assignment
        if (&rhs != this) {
            // 1. Free up the old resources
            delete[] data;

            // 2. Allocate and copy
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            data = new int[theCapacity];
            for (size_t index = 0; index < theSize; ++index) {
                data[index] = rhs.data[index];
            }
        }
        // 3. return yourself
        return *this;
    }

    // void push_back(int val);
    void push_back(int val) {
        // Handle resize issues
        if (theSize == theCapacity) {
            // What if they are zero?
            if (theSize == 0) {
                delete [] data;
                ++theCapacity;
                data = new int[theCapacity];
            } else {

                // Remember the old array
                int* old = data;

                // Allocate an array with twice the capacity, doubling the
                // capacity.
                theCapacity *= 2;
                data = new int[theCapacity];

                // Copy over the data elements
                for (size_t index = 0; index < theSize; ++index) {
                    data[index] = old[index];
                }

                // free up the old array
                delete[] old;
            }
        }

        // Ok, size is less than capacity
        data[theSize] = val;
        ++theSize;
    }

    // size_t size() const;
    size_t size() const {
        return theSize;
    }
    
    // void pop_back();
    void pop_back() {
        --theSize;
    }

    // void clear();
    void clear() {
        theSize = 0;
    }

    // Square brackets
    int operator[](size_t index) const { return data[index]; }

    int& operator[](size_t index) { return data[index]; }
    
    //
    // Ranged for support
    //    Note this code NEEDS TO BE improved
    //
    //int* begin() { return &data[0]; }
    //int* begin() { return data; }
    //int* begin() const { return data; }
    const int* begin() const { return data; }
    int* begin() { return data; }
    //int* end() { return &data[theSize]; }
    //int* end() const  { return data + theSize; }
    const int* end() const  { return data + theSize; }
    int* end() { return data + theSize; }

private:
    size_t theSize;
    size_t theCapacity;
    int* data;
};

void printVector(const Vector& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
        //v[i] = 17;
    }
    for (int val : v) {
        cout << val << ' ';
    }
    //*v.begin() = 17;
    cout << endl;
    
}

int main() {

    Vector v;  // Not templated.  Our Vector class can only hold ints.
    v.push_back(17);
    v.push_back(42);
    v.push_back(6);
    v.push_back(28);

    Vector v2(v);
    Vector v3;
    v3 = v;

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    v[0] = 100;

    //v = 17;
    //v = Vector(17);

    for (int val : v) {
    // for (const int* p = v.begin(); p != v.end(); ++p) {
    //     int val = *p;
        cout << val << ' ';
    }
    cout << endl;

    for (int& val : v) {
    //for (const int* p = v.begin(); p != v.end(); ++p) {
    //   int& val = *p;
        val *= 2;
    }

}

