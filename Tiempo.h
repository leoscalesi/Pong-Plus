#ifndef TIEMPO_H_INCLUDED
#define TIEMPO_H_INCLUDED


#include "Auxiliar.h"


class Tiempo{           //NO REPRESENTA AL TIEMPO REAL, CAMBIAR LUEGO PARA REPRESENTAR EL TIEMPO REAL.

       int minutos,segundos,milisegundos;

    public:

       Tiempo(int _minutos,int _segundos,int _milisegundos):minutos(_minutos),segundos(_segundos),milisegundos(_milisegundos){}
       int getMinutos(){return minutos;}
       int getSegundos(){return segundos;}
       int getMiliSegundos(){return milisegundos;}

       void pintar();
       void incrementar();
       void borrar();
       int convertirASegundos();

};


void Tiempo::pintar(){

     Auxiliar::gotoxy(70,2),printf("Tiempo");
     Auxiliar::gotoxy(78,2),printf("%d",minutos);
     Auxiliar::gotoxy(82,2),printf("%d",segundos);
     Auxiliar::gotoxy(86,2),printf("%d",milisegundos);

}

void Tiempo::borrar(){

    Auxiliar::gotoxy(78,2),printf("    ");
    Auxiliar::gotoxy(82,2),printf("    ");
    Auxiliar::gotoxy(86,2),printf("    ");

}


void Tiempo::incrementar(){   //SERIA CORRECTO HACER UN SLEEP (1000) PARA ASEGURARNOS DE QUE TRANSCURRA 1 seg., COSA QUE ACA NO SE CUMPLE.

     borrar();

     milisegundos ++;

     if(milisegundos == 60){

        milisegundos = 0;
        segundos ++;

        if(segundos == 60){

            milisegundos = 0;
            segundos = 0;
            minutos ++;
        }
     }

     pintar();
}


int Tiempo::convertirASegundos(){

    return segundos + minutos * 60;
}




#endif // TIEMPO_H_INCLUDED
