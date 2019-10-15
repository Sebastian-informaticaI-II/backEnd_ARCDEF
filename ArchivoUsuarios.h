#ifndef ARCHIVOUSUARIOS_H
#define ARCHIVOUSUARIOS_H

#include <QSettings>
#include <stdio.h>
#include <dirent.h>
#include <Definiciones.h>
#include <fstream>

using namespace std;

class ArchivoUsuarios
{
public:
    ArchivoUsuarios();
    ~ArchivoUsuarios();
    bool confirmarLogin(const QString &nombre,const QString &llave);
    void registrarUsuario(const QString &nombre,const QString &llave);
    bool existeUsuario(const QString &nombre);

private:
    bool existeArchivoUsuarios();
    void verificarArchivoUsuarios();

    QSettings* setting;

};

#endif // ARCHIVOUSUARIOS_H
