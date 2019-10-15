#ifndef REGISTO_H
#define REGISTO_H

#include <QWidget>
#include <QMessageBox>
#include <ArchivoUsuarios.h>

namespace Ui {
class Registo;
}

class Registo : public QWidget
{
    Q_OBJECT

public:
    explicit Registo(QWidget *parent = nullptr);
    ~Registo();

private slots:
    void on_Login_clicked();

    void on_Register_clicked();

private slots:
    void campoVacio();

    void llaveErrada();

    void registroCompleto();

    void usuarioExistente();
private:
    Ui::Registo *ui;
    ArchivoUsuarios archivo;
};

#endif // REGISTO_H
