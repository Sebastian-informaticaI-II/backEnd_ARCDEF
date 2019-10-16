#include "MenuDificultad.h"

MenuDificultad::MenuDificultad(QWidget *parent): QGraphicsView(parent)
{

}

MenuDificultad::~MenuDificultad()
{
    delete dificultad_1;
    delete dificultad_2;
    delete dificultad_3;
}

void MenuDificultad::setMenuDificultad()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,375,500);
    setBackgroundBrush(QBrush(QImage(":/images/fondo_sumergido")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(375,500);
    //------------ Crear Botones del menu ------------
    dificultad_1 = crearBotonMenu(37,50,":/images/facil"," Marinero\n      de\nAgua Dulce");
    dificultad_2 = crearBotonMenu(37,200,":/images/normal"," Capitan");
    dificultad_3 = crearBotonMenu(37,350,":/images/dificil","   Capitan\n        de\nMar y Guerra");
    connect(dificultad_1,SIGNAL(clicked()),this,SLOT(dificultadNivel_1()));
    connect(dificultad_2,SIGNAL(clicked()),this,SLOT(dificultadNivel_2()));
    connect(dificultad_3,SIGNAL(clicked()),this,SLOT(dificultadNivel_3()));
    show();
}

void MenuDificultad::dificultadNivel_1()
{
    emit dificultadElegida(1);
    close();
}

void MenuDificultad::dificultadNivel_2()
{
    emit dificultadElegida(2);
    close();
}

void MenuDificultad::dificultadNivel_3()
{
    emit dificultadElegida(3);
    close();
}

QPushButton *MenuDificultad::crearBotonMenu(int x, int y, const QString &icono, const QString &texto)
{
    QFont serifFont("DejaVu Serif Condensed", 20, QFont::Bold);
    QPushButton* nuevoBoton = new QPushButton(texto,this);
    nuevoBoton->setGeometry(QRect(x,y,300,100));
    nuevoBoton->setFont(serifFont);
    nuevoBoton->setIcon(QIcon(icono));
    nuevoBoton->setIconSize(QSize(96,96));
    nuevoBoton->setFlat(true);
    return nuevoBoton;
}
