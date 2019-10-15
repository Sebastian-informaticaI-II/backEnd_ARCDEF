#include "ArchivoUsuarios.h"

ArchivoUsuarios::ArchivoUsuarios()
{
    verificarArchivoUsuarios();
    setting = new QSettings(ARCHIVO_USUARIOS,QSettings::IniFormat);
}

ArchivoUsuarios::~ArchivoUsuarios()
{
    delete setting;
}

bool ArchivoUsuarios::existeArchivoUsuarios()
{
    DIR *pdir;
    pdir = opendir(".");
    struct dirent *entry;
    string str;
    while ((entry = readdir(pdir))) {
        str = entry->d_name;
        if(str == ARCHIVO_USUARIOS){
            closedir(pdir);
            return true;
        }
    }
    closedir(pdir);
    return false;
}

void ArchivoUsuarios::verificarArchivoUsuarios()
{
    bool existe = existeArchivoUsuarios();
    if(!existe){
        std::ofstream (ARCHIVO_USUARIOS);
    }
}

bool ArchivoUsuarios::confirmarLogin(const QString &nombre, const QString &llave)
{
    bool ok = setting->contains(nombre);
    if(!ok){
        return false;
    }
    QString llaveReal = setting->value(nombre,"").toString();
    if(llaveReal != llave){
        return false;
    }
    return true;
}

void ArchivoUsuarios::registrarUsuario(const QString &nombre, const QString &llave)
{
    setting->setValue(nombre,llave);
}

bool ArchivoUsuarios::existeUsuario(const QString &nombre)
{
    return setting->contains(nombre);
}
