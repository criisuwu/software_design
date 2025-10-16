#include "A.h"
#include <iostream>
#include <memory>

class B { // --------- A.h -----------------
public:
    B ();
    void initA(int);
    int getACounter (); // return no. objects
    void addACounter ();
private:
    std::unique_ptr<A> a;
};