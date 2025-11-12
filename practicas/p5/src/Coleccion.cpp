/* Coleccion.cpp
Practical exercise 5.
Coleccion class member -and friend- function definitions.
*/
#include <iostream>
#include <iomanip>                  // I/O manipulation library
#include "../import/Coleccion.h"    // Coleccion class definition

using namespace std;

// default constructor for class Coleccion (default size 10)
// considering arraySize > 0 , otherwise an exception should be thrown
Coleccion::Coleccion(int arraySize)
    : size(arraySize > 0 ? arraySize : 10),
      ptr(new int[size]) {
    for (int i = 0; i < size; ++i)
        ptr[i] = 0; // set pointer - based array element
}   // end Coleccion default constructor

// copy constructor for class Coleccion ; must receive a reference to a Coleccion
Coleccion::Coleccion(const Coleccion &arrayToCopy)
    : size(arrayToCopy.size),
      ptr(new int[size]) {
    for (int i = 0; i < size; ++i)
        ptr[i] = arrayToCopy.ptr[i];    // copy into object
}   // end Coleccion copy constructor

// destructor for class Coleccion
Coleccion::~Coleccion() {
    delete[] ptr;   // release pointer - based array space
}   // end destructor

// getSize: returns number of elements
size_t Coleccion::getSize() const {
    return size;
}

// assignment operator
const Coleccion &Coleccion::operator=(const Coleccion &right) {
    if (&right != this) {
        if (size != right.size) {
            delete[] ptr;
            size = right.size;
            ptr = new int[size];
        }
        for (int i = 0; i < size; ++i)
            ptr[i] = right.ptr[i];
    }
    return *this;
}

// equality operator
bool Coleccion::operator==(const Coleccion &right) const {
    if (size != right.size)
        return false;
    for (int i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return false;
    return true;
}

// subscript operator (non-const)
int &Coleccion::operator[](int subscript) {
    if (subscript < 0 || static_cast<size_t>(subscript) >= size) {
        cerr << "Error: subscript " << subscript << " out of range." << endl;
        exit(1);
    }
    return ptr[subscript];
}
// subscript operator (const)
int Coleccion::operator[](int subscript) const {
    if (subscript < 0 || static_cast<size_t>(subscript) >= size) {
        cerr << "Error: subscript " << subscript << " out of range." << endl;
        exit(1);
    }
    return ptr[subscript];
}

// stream extraction operator >>
istream &operator>>(istream &input, Coleccion &a) {
    for (size_t i = 0; i < a.size; ++i)
        input >> a.ptr[i];
    return input;
}

// stream insertion operator <<
ostream &operator<<(ostream &output, const Coleccion &a) {
    for (size_t i = 0; i < a.size; ++i) {
        output << setw(12) << a.ptr[i];
        if ((i + 1) % 4 == 0)
            output << endl;
    }
    if (a.size % 4 != 0)
        output << endl;
    return output;
}
