#ifndef OFICIAL_H
#define OFICIAL_H

#include <iostream>
#include <Definiciones.h>

using namespace std;

class Oficial
{
public:
    Oficial();
    void addExp(int exp);
    void subirNivel();
private:
    string _nombre;
    TipoDeOficial _tipo;
    int _nivel;
    int _exp;
    int _nextLevel;
    pair <int, int> _bono;
};

#endif // OFICIAL_H
