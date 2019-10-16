#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QBrush>
#include <QImage>
#include <QObject>
#include <QWidget>
#include <QPushButton>

#include <MenuDificultad.h>

class Menu: public QGraphicsView
{
    Q_OBJECT
public:
    Menu(QWidget * parent = nullptr);
    ~Menu();    
public slots:
    void detenerMusica();
    void seleccionarDificultad();
    void guardarPartida();
    void cargarPartida();
    void multijugador();
private slots:
    void iniciarJuego();
    QPushButton* crearBotonMenu(int x,int y, const QString &icono,const QString &texto);
    void setDificultad(int value);
private:
    int dificultad;
    QGraphicsScene *scene;
    QMediaPlaylist *playlist;
    QMediaPlayer *music;
    QPushButton* iniciarNuevaPartida;
    QPushButton* salvarPartida;
    QPushButton* cargarPartidaBtn;
    QPushButton* partidaMultijugador;

    MenuDificultad* menuDificultad;

};

#endif // MENU_H
