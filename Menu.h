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

class Menu: public QGraphicsView
{
    Q_OBJECT
public:
    Menu(QWidget * parent = nullptr);
    ~Menu();
public slots:
    void detenerMusica();
    void nuevaPartida();
    void guardarPartida();
    void cargarPartida();
    void multijugador();
private slots:
    QPushButton* crearBotonMenu(int x,int y, const QString &icono,const QString &texto);
private:
    QGraphicsScene *scene;
    QMediaPlaylist *playlist;
    QMediaPlayer *music;
    QPushButton* iniciarNuevaPartida;
    QPushButton* salvarPartida;
    QPushButton* cargarPartidaBtn;
    QPushButton* partidaMultijugador;
};

#endif // MENU_H
