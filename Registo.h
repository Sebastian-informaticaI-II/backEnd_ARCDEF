#ifndef REGISTO_H
#define REGISTO_H

#include <QWidget>
#include <QMessageBox>
#include <QSettings>

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

    bool confirmarUsuarioLLave(const QString &nombre,const QString &llave);

    void registrarUsuario(const QString &nombre,const QString &llave);

    void campoVacio();

    void llaveErrada();

    void registroCompleto();
private:
    Ui::Registo *ui;
    QSettings* setting;
};

#endif // REGISTO_H
