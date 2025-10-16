#include "A.h"

A::A (int c) { 
    counter = c; 
}

void A::addCounter (int n) { 
    counter = counter + n;
}

int A::getCounter () { 
    return counter; 
}