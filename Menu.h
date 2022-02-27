#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


#include <cstdlib>
#include "Juego.h"
#include "ArchivoSurvivor.h"



class Menu{

  public:

    //LA CLASE MENU NO NECESITA CONSERVAR NINGUN ESTADO INTERNO, DE MANERA QUE NO NECESITO INSTANCIAR OBJETOS DE DICHA CLASE, POR ESO USO static EN SUS METODOS.
    static void mostrar();

};


void Menu::mostrar(){

    bool salir=0;
    int opc;

    ArchivoSurvivor archivosurvivor(0,"");

    while(salir==0){

      cout << " ---------------------------- " << endl;
      cout << " PONG " << endl << endl;
      cout << endl << endl << endl << endl << endl;
      cout << " 1 - UN JUGADOR " << endl;
      cout << " 2 - DOS JUGADORES " << endl;
      cout << " 3 - SURVIVOR " << endl;
      cout << " 4 - VER MAXIMA PUNTUACION " << endl;
      cout  << endl << endl;
      cout << " 0 - SALIR DEL PROGRAMA " << endl << endl << endl;
      cout << " ---------------------------- " << endl;
      cout << " INGRESE OPCION: ";
      cin >> opc;

      system("cls");

      switch(opc){

      case 1:
      case 2:
      case 3:

        Juego::jugar(opc);        //VER SI FUNCIONA BIEN.

      break;

      case 4:

        archivosurvivor.mostrarMaximaPuntuacion();

      break;

      case 0:

        salir=1;

      break;

      }
    }
}



#endif // MENU_H_INCLUDED
