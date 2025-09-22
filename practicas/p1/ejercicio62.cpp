/* ------------------------------------------------
File: ejercicio62.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Get the value at solving the constant 
        of number e
---------------------------------------------------*/

#include <iostream>
#include <cmath>

int doFactorial(int num)
{
    int total = 1;

    if(num == 0)
        std::cout << "El factorial de " << num << " es: 1\n";
    else if (num < 0) 
        std::cout << "Numero no valido\n";
    else
    {
        while(num > 0)
        {
            total *= num;
            num--;
        }
    }
    return total;
}

int main()
{
    float num;
    float total = 1;
    float temp;
    float fact;

    std::cout << "Introduzca cuantos terminos quiere que tenga la suma para calcular e: ";
    std::cin >> num;
    temp = num;

    while(num > 0)
    {
        fact = doFactorial(num);
        total += 1 / fact;
        num--;
    }
    std::cout << "El valor de e con precision " << temp << " es: " << total << "\n";
}