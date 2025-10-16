#include <iostream>
#include <memory>
//#include "A.h" si añado esta línea, al no utilizar el #ifndef error por importar muchas veces lo mismo
#include "B.h"

int main(){
   B b = B();
   b.initA(10);
   std::cout << b.getACounter() << "\n";
   b.addACounter();
   std::cout << b.getACounter() << "\n";
}