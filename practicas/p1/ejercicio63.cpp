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

// TODO terminar bien este codigo, porque se que estoy cerca pero no jaja
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

// ! Esta es una funcion para hacer el factorial con el exponente
int factorialExp(float num, float exp) //con esta funcion solo queda sumarle el uno del inicio de la sucesion y ya estaria
{
    // int num;
    int i;
    float total = 1;
    float fact;
    i = 1;

    while(num > 0)
    {
        fact = doFactorial(num);
        printf("fact: %f\n", fact);
        printf("pow: %f", pow(exp, 1));
        total += pow(exp, i) / fact;
        printf("total: %f\n", total);
        num--;
        i++;
    }
    return total;
}

// * Duda, preguntar si x es igual al numero de terminos en la suma o cada uno es independiente
void getValue()
{
    float num;
    float exp;
    float total = 1;
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
        total += 1 + fact;
        num--;
    }
    std::cout << "El valor de e con precision " << temp << " es: " << total << "\n";
}

int main()
{
    getValue();
    return 0;
}