#include "MainWindow.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(argc == 1){
        MainWindow w;
        w.show();
        return a.exec();
    }
    std::string argumento(argv[1]);
    if(argumento == "-V"){
        std::cout << "La version del backEnd es: " << APP_VERSION << std::endl;
    }else{
        std::cout << "ERROR argumento desconocido. " << std::endl;
    }
    return 1;
}
