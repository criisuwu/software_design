/* ---------------------------------
File: test.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Control sentences
------------------------------------*/

#include <iostream>
#include <memory> //libreria para memorias, es decir el unique pointer.
//podemos usar el using namespace, pero no lo recomienda

int main()
{
    std::unique_ptr n = std::make_unique<int>(50); //Esto es para crear un puntero con la libreria del memory, y libera la memoria no hace falta el uso del delete
    //y la palabra auto es una reservada y asume el tipo de datos que vayas a poner al otro lado.

    std::cout << *n << "\n";
    return 0;
}