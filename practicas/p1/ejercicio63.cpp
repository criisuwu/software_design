/* ------------------------------------------------
File: ejercicio63.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Do a fcatorial of a number, get the precision
        at solving the constant of number e and get
        the precision at solving e^x
---------------------------------------------------*/

#include <iostream>
#include <cmath>

// * es una funcion para hacer el factorial del denominador
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

// * Esta es una funcion para hacer el factorial con el exponente
int factorialExp(int num, int exp)
{
    int i;
    float total = 0;
    int fact;
    i = num;

    while(num > 0)
    {
        fact = doFactorial(num);        // Lo estoy haciendo de mas grande a mas pequeño
        total += pow(exp, i) / fact;    // ! Aqui hago la suma en el orden inverso pero por alguna razon no me da bien el resultado de e^x
        num--;
        i--;
    }
    return total;
}

void getValue()
{
    int num;
    int exp;
    float total = 0;
    float temp;
    float fact;

    std::cout << "Introduzca cuantos terminos quiere que tenga la suma para calcular e: ";
    std::cin >> num;
    temp = num;
    std::cout << "Introduzca el valor del exponencial(es decir x): ";
    std::cin >> exp;

    while(num > 0)
    {
        fact = factorialExp(num, exp);
        total += fact;
        num--;
    }
    std::cout << "El valor de e con precision " << temp << " es: " << total << "\n"; // ! Me da demasiado alto y entiendo que el fallo puede ser en la forma en la que he plateado la formula
}

int main()
{
    getValue();
    return 0;
}