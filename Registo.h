#ifndef REGISTO_H
#define REGISTO_H

#include <QWidget>
#include <QMessageBox>
#include <ArchivoUsuarios.h>
#include <Menu.h>

namespace Ui {
class Registo;
}

class Registo : public QWidget
{
    Q_OBJECT

public:
    explicit Registo(QWidget *parent = nullptr);
    ~Registo();

public slots:
    void on_Login_clicked();

    void on_Register_clicked();

private slots:
    void abrirMenu(const string &usuario);

    void mensajeCampoVacio();

    void mensajeLlaveErrada();

    void mensajeRegistroCompleto();

    void mensajeUsuarioExistente();
private:
    Ui::Registo *ui;
    ArchivoUsuarios* archivo;
    Menu* menu;
};

#endif // REGISTO_H
