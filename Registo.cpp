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
//    archivo = new ArchivoUsuarios();
//    QString nombre = ui->UserName->text();
//    QString llave = ui->Password->text();
//    if(llave.isEmpty() || nombre.isEmpty()){
//        mensajeCampoVacio();
//        return;
//    }
//    bool todoBine = archivo->confirmarLogin(nombre,llave);
//    if(!todoBine){
//        mensajeLlaveErrada();
//        return;
//    }
//    delete archivo;
    QString nombre = "Sebastian";
    abrirMenu(nombre.toStdString());
}

void Registo::on_Register_clicked()
{
    archivo = new ArchivoUsuarios();
    QString nombre = ui->UserName->text();
    QString llave = ui->Password->text();
    if(llave.isEmpty() || nombre.isEmpty()){
        mensajeCampoVacio();
        return;
    }
    bool ok = archivo->existeUsuario(nombre);
    if(ok){
        mensajeUsuarioExistente();
        return;
    }
    archivo->registrarUsuario(nombre,llave);
    mensajeRegistroCompleto();
    delete archivo;
}

void Registo::abrirMenu(const string &usuario)
{

    menu = new Menu(usuario,this);
}

void Registo::mensajeCampoVacio()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Error: El Usuario o la contraseña estan vacios.\nIngrese dato faltante.");
    msgBox.exec();
}

void Registo::mensajeLlaveErrada()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("Error: Contraseña erronea.");
    msgBox.exec();
    ui->Password->clear();
}

void Registo::mensajeRegistroCompleto()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Registro Exitoso. \n ahora puede ingresar con su nuevo usuario y contraseña");
    msgBox.exec();
}

void Registo::mensajeUsuarioExistente()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("Error: El usuario ya existe.");
    msgBox.exec();
}
