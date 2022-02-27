#ifndef PELOTA_H_INCLUDED
#define PELOTA_H_INCLUDED


#include "Jugador.h"
#include "Juego.h"
#include "Auxiliar.h"


class Pelota{

      int x,y;
      int dx,dy;  //ESTAS VARIABLES CONTROLARAN EL INCREMENTO DE LA PELOTA (SU AVANCE A CADA ITERACION).

   public:

       Pelota(int _x,int _y,int _dx,int _dy);
       int X(){ return x;}
       int Y(){ return y;}
       void setX(int _x) { x = _x;}
       void setY(int _y) { y = _y;}

       int DX(){ return dx;}

       void pintar()const;    //LA PONGO const PORQUE NO VOY A MODIFICAR NINGUN DATO MIEMBRO,SOLO LOS VA A USAR.
       void borrar()const;    //ELIMINA EL RASTRO DEL JUGADOR(LA POSICION ANTERIOR DEL JUGADOR) EN CADA ITERACION.

       void mover(int,int,int,int);

};


Pelota :: Pelota(int _x,int _y,int _dx,int _dy): x(_x),y(_y),dx(_dx),dy(_dy){}

void Pelota::pintar() const{

     Auxiliar::gotoxy(x,y); printf("%c",184);

}

void Pelota::borrar() const{

     Auxiliar::gotoxy(x,y); printf(" ");
}


void Pelota::mover(int coordx1,int coordy1,int coordx2,int coordy2){

     borrar();
     x+=dx; y+=dy;   //AL VALOR ACTUAL DE LAS COORDENADAS x E y LE SUMO EL INCREMENTO DADO EN EL CONSTRUCTOR.
     pintar();

     //PROGRAMO LAS COLISIONES DE LA PELOTA CONTRA LA PARED.
     //SI LA COORDENADA MAS SU INCREMENTO ES IGUAL AL VALOR DE ALGUN LIMITE DEL ESCENARIO, DEBO CAMBIAR EL SENTIDO DE LA PELOTA, CAMBIANDOLE EL SIGNO AL INCREMENTO CORRESPONDIENTE.

     if(x+dx == 8 || x+dx == SCREEN_WIDTH){

        borrar();

        dx = -dx;
     }

     if(y+dy == 4 || y+dy == SCREEN_HEIGHT - 5){

        //borrar();
        dy = -dy;
     }


     //DEBO CONTROLAR LA VELOCIDAD DE LA PELOTA.

     //CONTROL DE COLISION CON EL RECTANGULO Y LA PELOTA PARA AMBOS JUGADORES.


     if(x + dx == coordx1 && y >= coordy1 - 2 && y <= coordy1 + 2){dx = -dx;}
     if(x + dx == coordx2 && y >= coordy2 -2 && y <= coordy2 + 2){dx = -dx;}


     //ES INTERESANTE QUE SE PUEDEN CONTROLAR A AMBOS RECTANGULOS(DE A UNO POR VEZ) DEPENDIENDO DONDE ESTE LA PELOTA.

}


#endif // PELOTA_H_INCLUDED
