#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED


#include "Auxiliar.h"
#include "Pelota.h"
#include "Juego.h"
#include "Tiempo.h"
#include <conio.h>    //AQUI SE ENCUENTRA kbhit()



//MACROS QUE DEFINEN QUE NUMERO LE CORRESPONDE A CADA TECLA

#define ARRIBA 72
#define ABAJO 80

class Jugador{

    int x,y;
    int puntaje;

  public:

    Jugador(int _x,int _y);
    int X(){ return x;}
    int Y(){ return y;}
    void incrementoY(int _y){y+=_y;}   //VER PARA QUE SIRVE.
    int getPuntaje(){return puntaje;}


    void pintar() const;    //LA PONGO const PORQUE NO VOY A MODIFICAR NINGUN DATO MIEMBRO,SOLO LOS VA A USAR.
    void borrar() const;    //ELIMINA EL RASTRO DEL JUGADOR(LA POSICION ANTERIOR DEL JUGADOR) EN CADA ITERACION.
    //void mover();
    void pintarPuntaje(int,int,int);

    void moverJugadorCpu(int _x,int _y,int _dx,int opc,Tiempo&);  // _dx ES EL INCREMENTO EN x QUE TIENE LA PELOTA, YA QUE YO VOY A QUERER QUE EL RECTANGULO QUE MUEVE LA cpu SOLO CUANDO EL INCREMENTO EN x DE LA PELOTA
                                                  // (_dx) SEA POSITIVO, ES DECIR LA PELOTA ESTA YENDO HACIA LA DERECHA (INCREMENTO POSITIVO).


    void actualizarPuntaje(int,Pelota& ,int,int);


};

Jugador::Jugador(int _x,int _y): x(_x),y(_y){}


void Jugador::pintar() const {

    Auxiliar::gotoxy(x,y-1); printf("%c",219);
    Auxiliar::gotoxy(x,y); printf("%c",219);
    Auxiliar::gotoxy(x,y+1); printf("%c",219);

}


void Jugador::borrar() const {

    Auxiliar::gotoxy(x-1,y-1); printf("   ");
    Auxiliar::gotoxy(x-1,y); printf("   ");
    Auxiliar::gotoxy(x-1,y+1); printf("   ");

}

/*
void Jugador::mover(){

      if(kbhit()){   //DETECTA SI SE PRESIONO ALGUNA TECLA CUALQUIERA DEL TECLADO.


            char tecla = getch();   //ME DICE Y GUARDA QUE TECLA SE PRESIONO.
            borrar();
            if(tecla == ARRIBA && y > 5) y = y-2;
            if(tecla == ABAJO && y + 2 < 45) y = y+2;   //SE OPTO POR METER TANTO EL MOVIMIENTO DEL JUGADOR 1 Y DEL 2 EN EL MISMO METODO, YA QUE SI HACIA LOS DOS METODOS POR SEPARADO
                                                        //(moverJugador1 y moverJugador2 SEPARADOS NO SE MOVIAN LOS RECTANGULOS.

            if(tecla == 'r' && y > 5) y = y-2;
            if(tecla == 'f' && y + 2 < 45) y = y+2;

            pintar();


      }
}
*/

void Jugador::moverJugadorCpu(int _x,int _y,int _dx,int opc,Tiempo& tiempo){ //EN LOS PARAMETROS DE ESTA FUNCION VIENEN LAS COORDENADAS Y EL INCREMENTO DE LA PELOTA.


      if(opc == 3){              //VER SI AGREGO UN bool PARA QUE SIGA INCREMENTAN

         //tiempo.pintar();
         tiempo.incrementar();
      }

      if(_x > SCREEN_WIDTH/2 && _dx > 0){   //SI ESTAMOS MAS CERCA DEL JUGADOR CPU(A LA DERECHA) QUE DEL JUGADOR 1 (A LA IZQUIERDA), QUE SE MUEVA EL RECTANGULO DE LA DERECHA.

          borrar();

          if(_y > y) y++;   //SI LA COORDENADA _y DE LA PELOTA ES MAYOR QUE LA COORDENADA y DEL JUGADOR cpu, SIGNIFICA QUE LA PELOTA ESTA POR DEBAJO DEL RECTANGULO, ENTONCES INCREMENTAMOS LA COORDENADA
                            // y DEL JUGADOR cpu PARA QUE VAYA SIGUIENDO LA PELOTA.


          if(_y < y) y--;

          pintar();

      }
}


void Jugador::pintarPuntaje(int p,int x,int y){     //NECESITA RECIBIR COMO PARAMETRO EL PUNTAJE

      Auxiliar::gotoxy(x,y); printf("Puntaje %d",p);

}


void Jugador::actualizarPuntaje(int p,Pelota& pelota,int x,int y){


      puntaje = p;
      pintarPuntaje(p,x,y);
      Sleep(2000);
      pelota.borrar();
      pelota.setX(SCREEN_WIDTH/2);
      pelota.setY(SCREEN_HEIGHT/2);
      pelota.pintar();

}


#endif // JUGADOR_H_INCLUDED
