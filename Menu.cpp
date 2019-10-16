#include "Menu.h"

Menu::Menu(QWidget *parent): QGraphicsView(parent)
{
    menuDificultad = new MenuDificultad();
    connect(menuDificultad,SIGNAL(dificultadElegida(int)),this,SLOT(setDificultad(int)));

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,375,500);
    setBackgroundBrush(QBrush(QImage(":/images/fondo_sumergido")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(375,500);
    //------------ Crear Botones del menu ------------
    iniciarNuevaPartida = crearBotonMenu(37,50,":/images/agregar","   Nueva Partida");
    salvarPartida = crearBotonMenu(37,150,":/images/salvar","Guardar Partida");
    cargarPartidaBtn = crearBotonMenu(37,250,":/images/cargar","  Cargar Partida");
    partidaMultijugador = crearBotonMenu(37,350,":/images/grupo","    Multijugador");
    //--------------- Conectar botones ---------------------
    connect(iniciarNuevaPartida,SIGNAL(clicked()),this,SLOT(seleccionarDificultad()));
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
    delete menuDificultad;
}

void Menu::detenerMusica()
{
    music->stop();
}

void Menu::seleccionarDificultad()
{
    menuDificultad->setMenuDificultad();
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

void Menu::iniciarJuego()
{
    detenerMusica();
    game = new MapaMar();
}

QPushButton *Menu::crearBotonMenu(int x, int y, const QString &icono, const QString &texto)
{
    QFont serifFont("DejaVu Serif Condensed", 20, QFont::Bold);
    QPushButton* nuevoBoton = new QPushButton(texto,this);
    nuevoBoton->setGeometry(QRect(x,y,300,50));
    nuevoBoton->setFont(serifFont);
    nuevoBoton->setIcon(QIcon(icono));
    nuevoBoton->setIconSize(QSize(48,48));
    nuevoBoton->setFlat(true);
    return nuevoBoton;
}

void Menu::setDificultad(int value)
{
    dificultad = value;
    iniciarJuego();
}

