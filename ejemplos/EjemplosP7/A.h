#ifndef A_H
#define A_H

#include <sqlite3.h>
#include <string>
#include <iostream>

class A {
protected:
    int id;
    sqlite3 * db;
public:
    A(int);
    ~A() = default; // virtual para herencia segura
    void getPerson();

    // En el futuro podrías poner aquí un método virtual login()
};

#endif // USER_H