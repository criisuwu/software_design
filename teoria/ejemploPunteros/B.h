#include "A.h"
#include <iostream>
#include <memory>

class B { // --------- A.h -----------------
public:
    B ();
    void initA(int);
    int getACounter (); // return no. objects
    void addACounter ();
    void printArray();
private:
    std::unique_ptr<A> a;
    std::unique_ptr<std::unique_ptr<A>[]> test;
};