#include "FilaDeCanones.h"

FilaDeCanones::FilaDeCanones()
{

}

void FilaDeCanones::apuntar(int angulo)
{
    cout << "Angulo apuntado " << angulo << endl;
    _anguloDisparo = angulo;
}

void FilaDeCanones::disparar()
{
    cout << "Angulo Disparo " << _anguloDisparo << endl;
}

void FilaDeCanones::recargar()
{
    cout << "reload" << endl;
}
