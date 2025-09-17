/* ---------------------------------
File: main.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: The first try to C++ 
------------------------------------*/

#include <iostream>
#include "library.h"

//la quiere sin _ y con una mayusc, lo mismo para las variables. Y con un verbo y un noun
int getTotal(int a, int &b)
{
    b = 7; //no la duplica, si no la modifica en el hueco de memoria original
    return a + b;
}


int main()
{
    int n = 5;
    int n2 = 6;
    float d1 = 5.523;
    //char c = 'C';
    std::cout << d1 << "\n";
    std::cout << "Introduce un numero: ";
    std::cin >> n;
    std::cout << "Tu numero es " << n << "\n";
    std::cout << "La suma es: " << getTotal(n, n2) << "\n";
    return 0;
}