#include "AlmacenamientoPartidas.h"

AlmacenamientoPartidas::AlmacenamientoPartidas()
{

}

void AlmacenamientoPartidas::guardarPartida(const Partida &partida)
{
    string archivoSave = partida._usuario + TERMINACION_SAVE;
    verificarArchivoUsuarios(archivoSave);
    setting = new QSettings(QString::fromStdString(archivoSave),QSettings::IniFormat);
    setting->setValue(VIDA,partida._vida);
    setting->setValue(PUNTAJE,partida._puntos);
    setting->setValue(DIFICULTAD,partida._dificultad);
    delete setting;
}

Partida AlmacenamientoPartidas::cargarPartida(string usuario)
{
    string archivoSave = usuario + TERMINACION_SAVE;
    verificarArchivoUsuarios(archivoSave);
    setting = new QSettings(QString::fromStdString(archivoSave),QSettings::IniFormat);
    int vida = setting->value(VIDA,3).toInt();
    int puntos = setting->value(PUNTAJE,0).toInt();
    int dificultad = setting->value(DIFICULTAD,1).toInt();
    delete setting;
    Partida partida(vida,puntos,dificultad,usuario);
    return partida;
}

bool AlmacenamientoPartidas::existeArchivoUsuarios(const string &usuario)
{
    DIR *pdir;
    pdir = opendir(".");
    struct dirent *entry;
    string str;
    while ((entry = readdir(pdir))) {
        str = entry->d_name;
        if(str == usuario){
            closedir(pdir);
            return true;
        }
    }
    closedir(pdir);
    return false;
}

void AlmacenamientoPartidas::verificarArchivoUsuarios(const string &usuario)
{
    bool existe = existeArchivoUsuarios(usuario);
    if(!existe){
        std::ofstream usuario;
    }
}
