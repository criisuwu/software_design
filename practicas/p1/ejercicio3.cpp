/* ------------------------------------------------
File: ejercicio3.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Check if the numbers are multiples
---------------------------------------------------*/

#include <iostream>

int main()
{
    int num1;
    int num2;

    std::cout << "Porfavor introduzca el primer numero: ";
    std::cin >> num1;
    std::cout << "Porfavor introduzca el segundo numero: ";
    std::cin >> num2;

    if((num1 % num2) == 0)
        std::cout << num1 << " es multiplo de " << num2 << "\n";
    else if((num2 % num1) == 0)
         std::cout << num2 << " es multiplo de " << num1 << "\n";
    else
        std::cout << "Ninguno es multiplo del otro \n";
    
    return 0;
}