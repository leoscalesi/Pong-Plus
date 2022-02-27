#ifndef ARCHIVOSURVIVOR_H_INCLUDED
#define ARCHIVOSURVIVOR_H_INCLUDED

#include <string.h>
#include <fstream>

class ArchivoSurvivor{

      int tiempomaximoarchivo;
      string iniciales;

  public:

      ArchivoSurvivor(int _tiempomaximoarchivo,string _iniciales):tiempomaximoarchivo(_tiempomaximoarchivo),iniciales(_iniciales){}

      //void verMaximoTiempo();
      int leerTiempoArchivoSurvivor();
      void guardarTiempoArchivo(int,string);
      void mostrarMaximaPuntuacion();

      string ingresaIniciales();



};

int ArchivoSurvivor::leerTiempoArchivoSurvivor(){

     ifstream archivo;
     archivo.open("PuntajeMaximoArchivoSurvivor.txt");
     if(!archivo.is_open()){

        cout << "Error al leer el archivo";
        Sleep(2000);
        system("cls");
        return -1;
     }
     //CON EL OPERADOR DE EXTRACCION >> LEO EL CONTENIDO  Y LO GUARDO EN LA VARIABLE.
     archivo >> tiempomaximoarchivo;

     return tiempomaximoarchivo;
     archivo.close();
}


 void ArchivoSurvivor::guardarTiempoArchivo(int p,string i){


     ofstream archivo;
     archivo.open("PuntajeMaximoArchivoSurvivor.txt");
     if(!archivo.is_open()){

        cout << "Error al leer el archivo";
        Sleep(2000);
        system("cls");
        return;
     }

     archivo << p << i;
     //EL flush SE HACE SOLAMENTE CON LOS ARCHIVOS DE SALIDA (ESCRITURA DE ARCHIVOS).
     archivo.flush();
     archivo.close();
}



/*
void ArchivoSurvivor::verMaximoTiempo(){

     tiempomaximoarchivo = leerTiempoArchivoSurvivor();

     cout << "EL TIEMPO MAXIMO DE SUPERVIVENCIA FUE: " << tiempomaximoarchivo;

     Sleep(3000);
     system("cls");

}
*/

void ArchivoSurvivor::mostrarMaximaPuntuacion(){

     ifstream archivo;
     archivo.open("PuntajeMaximoArchivoSurvivor.txt");
     if(!archivo.is_open()){

        cout << "Error al leer el archivo";
        Sleep(2000);
        system("cls");
        return;
     }
     //CON EL OPERADOR DE EXTRACCION >> LEO EL CONTENIDO  Y LO GUARDO EN LA VARIABLE.
     archivo >> tiempomaximoarchivo >> iniciales;

     cout << tiempomaximoarchivo << endl;
     cout << iniciales;

     Sleep(3000);
     system("cls");

     archivo.close();

}


string ArchivoSurvivor::ingresaIniciales(){

     Sleep(2000);
     system("cls");

     Auxiliar::gotoxy(50,10),cout << " FELICIDADES!!! BATISTE UN NUEVO RECORD!!!! " << endl << endl;
     Auxiliar::gotoxy(56,14),cout << " INGRESA TUS INICIALES:  ";
     cin >> iniciales;

     return iniciales;
}


#endif // ARCHIVOSURVIVOR_H_INCLUDED
