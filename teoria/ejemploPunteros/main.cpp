#include <iostream>
#include <memory>
//#include "A.h" si añado esta línea, al no utilizar el #ifndef error por importar muchas veces lo mismo
#include "B.h"

int main(){
   //std::unique_ptr arr = std::make_unique<int[]>(10);
   //arr[0] = 5;
   //arr[1] = 10;
   B b = B();
   //std::cout << arr[0] << "\n";
   //std::cout << arr[1] << "\n";
   b.initA(10);
   std::cout << b.getACounter() << "\n";
   b.addACounter();
   std::cout << b.getACounter() << "\n";
   b.printArray();
}