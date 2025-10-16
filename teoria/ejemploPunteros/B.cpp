#include "B.h"


B::B(){
    //a = std::make_unique<A>(c); Si quisieramos definir a en el constructor
    //deberíamos añadir el parámetro c al constructor
    test = std::make_unique<std::unique_ptr<A>[]>(10);
    
}

void B::initA(int c){
    a = std::make_unique<A>(c);
    test[0] = std::make_unique<A>(42);
}
void B::addACounter () { 
    a->addCounter(10);
}

int B::getACounter () { 
    return a->getCounter();
}

void B::printArray(){
    std::cout << test[0]->getCounter() << "\n";
}