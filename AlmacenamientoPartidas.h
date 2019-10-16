#ifndef ALMACENAMIENTOPARTIDAS_H
#define ALMACENAMIENTOPARTIDAS_H

#include <QSettings>
#include <QString>
#include <stdio.h>
#include <dirent.h>
#include <fstream>
#include <Definiciones.h>

using namespace std;

class AlmacenamientoPartidas
{
public:
    AlmacenamientoPartidas();
    void guardarPartida(const Partida &partida);
    Partida cargarPartida(string usuario);
private:
    QSettings* setting;

    bool existeArchivoUsuarios(const string &usuario);
    void verificarArchivoUsuarios(const string &usuario);
};

#endif // ALMACENAMIENTOPARTIDAS_H
