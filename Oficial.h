#ifndef OFICIAL_H
#define OFICIAL_H

#include <iostream>
#include <Definiciones.h>
#include <math.h>

using namespace std;

class Oficial
{
public:
    Oficial(const string &nombre, const TipoDeOficial &tipo);

    void setNivel(int nivel);
    void setNombre(const string &nombre);

    void addExp(int exp);
    void subirNivel();

    string nombre() const;
    TipoDeOficial tipo() const;
    int nivel() const;
    int exp() const;
    int nextLevel() const;

private:
    int expForLevel(int nivel);

    string _nombre;
    TipoDeOficial _tipo;
    int _nivel;
    int _exp;
    int _nextLevel;
};

#endif // OFICIAL_H
