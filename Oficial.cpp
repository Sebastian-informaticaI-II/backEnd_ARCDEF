#include "Oficial.h"

Oficial::Oficial(const string &nombre, const TipoDeOficial &tipo)
{
    _nivel = NIVEL_BASICO;
    _exp = EXP_INICIAL;
    _nextLevel = EXP_FOR_LEVEL_1;
    _tipo = tipo;
    _nombre = nombre;
}

void Oficial::addExp(int exp)
{
    _exp += exp;
    while(_exp >= _nextLevel){
        subirNivel();
    }
}

void Oficial::subirNivel()
{
    _nivel++;
    _exp -= _nextLevel;
    _nextLevel = expForLevel(_nivel);

}

int Oficial::expForLevel(int nivel)
{
    // Exp para el siguiente nivel = (nivel + BASE_CALCULO_NIVEL)^EXPONETE_EXPERIENCIA
    int base = (nivel + BASE_CALCULO_NIVEL);
    int expFinal = static_cast<int>(pow(base,EXPONETE_EXPERIENCIA));
    return expFinal;
}

int Oficial::nextLevel() const
{
    return _nextLevel;
}

int Oficial::exp() const
{
    return _exp;
}

void Oficial::setNivel(int nivel)
{
    _nivel = nivel;
}

int Oficial::nivel() const
{
    return _nivel;
}

TipoDeOficial Oficial::tipo() const
{
    return _tipo;
}

string Oficial::nombre() const
{
    return _nombre;
}

void Oficial::setNombre(const string &nombre)
{
    _nombre = nombre;
}


