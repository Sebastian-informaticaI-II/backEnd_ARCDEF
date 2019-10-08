#ifndef FILADECANONES_H
#define FILADECANONES_H

#include <iostream>
#include <Canon.h>
#include <QObject>
#include <QTimer>

using namespace std;

class FilaDeCanones : public Canon
{
    Q_OBJECT
public:
    FilaDeCanones(Canon* parent = nullptr);
public slots:
    void setCanones(const Canon &modelo, int cantidad);

    void disparar();
    void recargar();

    int reloadTime() const;
    void setReloadTime(int reloadTime);

    int accurasi() const;
    void setAccurasi(int accurasi);

private slots:
    void recargado();
private:
    int _cantidad;
    int _reloadTime;
    int _accurasi;
};

#endif // FILADECANONES_H
