#include "MapaMar.h"

MapaMar::MapaMar(Partida partida, QWidget *parent): QGraphicsView(parent)
{
    dificultdad = partida._dificultad;
    vida = new Vida();
    puntos = new Puntaje();
    puntos->setPos(puntos->x(),puntos->y()+25);
    vida->setVida(partida._vida);
    puntos->setPuntos(partida._puntos);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,533);
    setBackgroundBrush(QBrush(QImage(":/images/fondo_ondas")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,533);
    //------------ Agregar elementos a escena ------------
    scene->addItem(vida);
    scene->addItem(puntos);

    //Crear Item para escena
    jugador = new BarcoJugador();
    jugador->setPos(10,250);
    jugador->setFlag(QGraphicsItem::ItemIsFocusable);
    jugador->setFocus();

    //Agregar a escena
    scene->addItem(jugador);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawnByDif()));
    timer->start(2000);
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

MapaMar::~MapaMar()
{
    delete music;
    delete playlist;
}

Partida MapaMar::obtenerPartida()
{
    int vidap = vida->getVida();
    int puntosp = puntos->getPuntos();
    Partida partida(vidap,puntosp,dificultdad,"");
    return partida;
}

void MapaMar::recibirDamage()
{
    vida->decrementarVida();
}

void MapaMar::ganarPuntos()
{
    puntos->ganarPuntos();
}

void MapaMar::spawnByDif()
{
    jugador->spawn(dificultdad);
}
