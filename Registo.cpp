#include "Registo.h"
#include "ui_Registo.h"

Registo::Registo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registo)
{
    ui->setupUi(this);
    setting = new QSettings(":/archivos/registrados.ini",QSettings::IniFormat);
}

Registo::~Registo()
{
    delete ui;
    delete setting;
}

void Registo::on_Login_clicked()
{
    QString nombre = ui->UserName->text();
    QString llave = ui->Password->text();
    if(llave.isEmpty() || nombre.isEmpty()){
        campoVacio();
        return;
    }
    bool todoBine = confirmarUsuarioLLave(nombre,llave);
    if(!todoBine){
        llaveErrada();
        return;
    }
    QMessageBox msgBox;
    msgBox.setText("Entraste");
    msgBox.exec();
}

void Registo::on_Register_clicked()
{
    QString nombre = ui->UserName->text();
    QString llave = ui->Password->text();
    if(llave.isEmpty() || nombre.isEmpty()){
        campoVacio();
        return;
    }
    registrarUsuario(nombre,llave);
    registroCompleto();
}

bool Registo::confirmarUsuarioLLave(const QString &nombre, const QString &llave)
{
    bool ok = setting->contains(nombre);
    if(!ok){
        return false;
    }
    QString llaveReal = setting->value(llave,"").toString();
    if(llaveReal != llave){
        return false;
    }
    return true;
}

void Registo::registrarUsuario(const QString &nombre, const QString &llave)
{
    setting->setValue(nombre,llave);
}

void Registo::campoVacio()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Error: El Usuario o la contraseña estan vacios.\nIngrese dato faltante.");
    msgBox.exec();
}

void Registo::llaveErrada()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("Error: Contraseña erronea.");
    msgBox.exec();
    ui->Password->clear();
}

void Registo::registroCompleto()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Registro Exitoso. \n ahora puede ingresar con su nuevo usuario y contraseña");
    msgBox.exec();
}
