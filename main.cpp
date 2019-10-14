#include <QApplication>
#include <iostream>
#include <MapaMar.h>
#include <Registo.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(argc == 1){
        Registo registro;
        registro.show();
        return a.exec();
//        MapaMar *game;
//        game = new MapaMar();
//        game->show();
//        return a.exec();
    }
    std::string argumento(argv[1]);
    if(argumento == "-V"){
        std::cout << "La version del backEnd es: " << APP_VERSION << std::endl;
    }else{
        std::cout << "ERROR argumento desconocido. " << std::endl;
    }
    return 1;
}
