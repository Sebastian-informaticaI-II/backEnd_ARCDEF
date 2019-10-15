#include "Registo.h"
#include "ui_Registo.h"

Registo::Registo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registo)
{
    ui->setupUi(this);
}

Registo::~Registo()
{
    delete ui;
}

void Registo::on_Login_clicked()
{
    QString nombre = ui->UserName->text();
    QString llave = ui->Password->text();
    if(llave.isEmpty() || nombre.isEmpty()){
        campoVacio();
        return;
    }
    bool todoBine = archivo.confirmarLogin(nombre,llave);
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
    bool ok = archivo.existeUsuario(nombre);
    if(ok){
        usuarioExistente();
        return;
    }
    archivo.registrarUsuario(nombre,llave);
    registroCompleto();
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

void Registo::usuarioExistente()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("Error: El usuario ya existe.");
    msgBox.exec();
}
