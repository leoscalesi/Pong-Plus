#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "Auxiliar.h"
#include "Jugador.h"
#include "Pelota.h"
#include "ArchivoSurvivor.h"
#include "Tiempo.h"
#include <conio.h>


class Juego{

 public:

    static void jugar(int);

};


void Juego::jugar(int opc){   //LA OPCION SIRVE PARA DETERMINAR SI ES CONTRA LA MAQUINA O DE A DOS.

    Auxiliar::ocultarCursor();
    Auxiliar::pintarLimites();

    int puntaje1 = 0; int puntaje2 = 0;
    const int puntajemaximo = 20;   //ES EL PUNTAJE ESTABLECIDO PARA QUE JUGANDO DE A DOS JUGADORES, EL QUE PRIMERO OBTIENE ESE PUNTAJE GANA LA PARTIDA.

    Jugador jugador1(10,25);
    jugador1.pintar();
    jugador1.pintarPuntaje(puntaje1,10,2);

    Jugador jugador2(SCREEN_WIDTH - 2,25);
    jugador2.pintar();
    jugador2.pintarPuntaje(puntaje2,79,2);

    Pelota pelota(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,1,1);
    pelota.pintar();

    Tiempo tiempo(0,0,0);

    ArchivoSurvivor archivosurvivor(0,"");

    int cont = 0;   //SIRVE PARA CONTROLAR LA VELOCIDAD DE LA PELOTA, YA QUE CON EL METODO mover() LA PELOTA SE MUEVE RAPIDISIMO.

    char tecla;

    bool gameover = false;

    while(!gameover){

         //FORMA CORRECTA DE QUE FUNCIONE PARA UNO Y DOS JUGADORES.
         //------------------------------------------------------------------------
         //DOS JUGADORES.
         if(kbhit()){

            jugador1.borrar(),jugador2.borrar();
            tecla = getch();
            if(tecla == 'q' && jugador1.Y() > 5) jugador1.incrementoY(-1); else if (tecla == 'a' && jugador1.Y() < SCREEN_HEIGHT - 6) jugador1.incrementoY(1);
            if(opc == 2){

                if(tecla == 'o' && jugador2.Y() > 5) jugador2.incrementoY(-1);
                else if (tecla == 'l' && jugador2.Y() < SCREEN_HEIGHT - 6)  jugador2.incrementoY(1);

            }
            jugador1.pintar(),jugador2.pintar();

        }

         //UN JUGADOR(CONTRA LA MAQUINA) O SURVIVOR.
         if(opc == 1  || opc == 3) jugador2.moverJugadorCpu(pelota.X(),pelota.Y(),pelota.DX(),opc,tiempo);
         //------------------------------------------------------------------------------



         //PUNTAJES Y REINICIO DESDE EL MEDIO DE LA PELOTA. TAMBIEN PARA SURVIVOR CONDICION PARA JUEGO TERMINADO.
         //********************************************************************************

         if(pelota.X() == 9) {

              if(opc == 2 || opc == 1){
                puntaje2 += 5;
                jugador2.actualizarPuntaje(puntaje2,pelota,79,2);

                if (jugador2.getPuntaje() == puntajemaximo) break;   // CONDICION PARA QUE SE TERMINE EL JUEGO SI EL JUGADOR 2 LLEGA PRIMERO AL PUNTAJE MAXIMO.
              }
              if(opc == 3){
                //gameover = true;
                break;
              }
         }
         if(pelota.X() == SCREEN_WIDTH) {

                puntaje1 += 5;
                jugador1.actualizarPuntaje(puntaje1,pelota,10,2);

                if (jugador1.getPuntaje() == puntajemaximo) break;   // CONDICION PARA QUE SE TERMINE EL JUEGO SI EL JUGADOR 1 LLEGA PRIMERO AL PUNTAJE MAXIMO.
         }

         //********************************************************************************




         //CONTROL DE LA VELOCIDAD DE LA PELOTA.
         //--------------------------------------------------------------------------------
         if(!cont){

            pelota.mover(jugador1.X(),jugador1.Y(),jugador2.X(),jugador2.Y()); //NO PASARLE EL OBJETO SOLO PORQUE TRAE PROBLEMAS, PROBABLEMENTE PORQUE NO TENGO EN EL .h SOLO LAS DECLARACIONES Y EN UN cpp LAS DEFINICIONES EN CADA CLASE.

         }
         cont ++;
         if(cont > 1){

            cont = 0;
         }

         Sleep(10); //ESTE Sleep ES CLAVE PARA QUE LA PELOTA PUEDA CONTROLAR SU VELOCIDAD.

         //--------------------------------------------------------------------------------



    } //FIN while.



    Sleep(2000);
    system("cls");

    Auxiliar::gotoxy(SCREEN_WIDTH/2,SCREEN_HEIGHT/2); printf("JUEGO TERMINADO");

    Sleep(3000);




    //MANEJO DEL ARCHIVOSURVIVOR (opc == 3).
    //**************************************************************************************************

    if(opc == 3){

       int tiempomaximoarchivo = archivosurvivor.leerTiempoArchivoSurvivor();

          //CONVERTIR A SEGUNDOS EL TIEMPO DEL JUGADOR PARA PODER COMPARAR.

          int tiempojugador1 = tiempo.convertirASegundos();

          if (tiempojugador1 > tiempomaximoarchivo){       //EN DONDE DICE puntos TENGO QUE HACER UNA FUNCION QUE CONVIERTA EL TIEMPO QUE HIZO EL JUGADOR A SEGUNDOS.

          //ACA MOSTRAR PANTALLA PARA QUE INGRESE SUS INICIALES Y LE DIGA QUE SUPERO EL RECORD.

              string iniciales = archivosurvivor.ingresaIniciales();
              archivosurvivor.guardarTiempoArchivo(tiempojugador1,iniciales);
          }
    }

    //**************************************************************************************************

    system("cls");

}

#endif // JUEGO_H_INCLUDED
