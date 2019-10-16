#include "Menu.h"
#include <QMessageBox>
Menu::Menu(QWidget *parent)
{
    QFont serifFont("Helvetica", 20, QFont::Bold);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,375,500);
    setBackgroundBrush(QBrush(QImage(":/images/fondo_sumergido")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(375,500);
    //------------ Agregar elementos a escena ------------
    iniciarNuevaPartida = crearBotonMenu(37,50,":/images/agregar","   Nueva Partida");
    salvarPartida = crearBotonMenu(37,150,":/images/salvar","Guardar Partida");
    cargarPartidaBtn = crearBotonMenu(37,250,":/images/cargar","  Cargar Partida");
    partidaMultijugador = crearBotonMenu(37,350,":/images/grupo","    Multijugador");
    scene->addWidget(iniciarNuevaPartida);
    scene->addWidget(salvarPartida);
    scene->addWidget(cargarPartidaBtn);
    scene->addWidget(partidaMultijugador);

    //Conectar botones
    connect(iniciarNuevaPartida,SIGNAL(clicked()),this,SLOT(nuevaPartida()));
    connect(salvarPartida,SIGNAL(clicked()),this,SLOT(guardarPartida()));
    connect(cargarPartidaBtn,SIGNAL(clicked()),this,SLOT(cargarPartida()));
    connect(partidaMultijugador,SIGNAL(clicked()),this,SLOT(multijugador()));

    //------------- Agregar Sonido de fondo --------------
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/bgsound"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
    //---------------------- Mostrat ---------------------
    show();
}

Menu::~Menu()
{
    delete scene;
    delete playlist;
    delete music;
    delete iniciarNuevaPartida;
    delete salvarPartida;
    delete cargarPartidaBtn;
    delete partidaMultijugador;
}

void Menu::detenerMusica()
{
    music->stop();
}

void Menu::nuevaPartida()
{
    //TODO
}

void Menu::guardarPartida()
{
    //TODO
}

void Menu::cargarPartida()
{
    //TODO
}

void Menu::multijugador()
{
    //TODO
}

QPushButton *Menu::crearBotonMenu(int x, int y, const QString &icono, const QString &texto)
{
    QFont serifFont("Helvetica", 20, QFont::Bold);
    QPushButton* nuevoBoton = new QPushButton(texto,this);
    nuevoBoton->setGeometry(QRect(x,y,300,50));
    nuevoBoton->setFont(serifFont);
    nuevoBoton->setIcon(QIcon(icono));
    nuevoBoton->setIconSize(QSize(48,48));
    nuevoBoton->setFlat(true);
    return nuevoBoton;
}
