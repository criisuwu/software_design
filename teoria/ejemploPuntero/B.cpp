#include "B.h"


B::B(){
    //a = std::make_unique<A>(c); Si quisieramos definir a en el constructor
    //deberíamos añadir el parámetro c al constructor
}

void B::initA(int c){
    a = std::make_unique<A>(c);
}
void B::addACounter () { 
    a->addCounter(10);
}

int B::getACounter () { 
    return a->getCounter();
}