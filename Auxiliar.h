#ifndef AUXILIAR_H_INCLUDED
#define AUXILIAR_H_INCLUDED

#include <windows.h>
#include <cstdio>

#define SCREEN_WIDTH 91
#define SCREEN_HEIGHT 36
#define WIN_WIDTH 70

class Auxiliar{


 public:

      static void gotoxy(int x,int y);
      static void ocultarCursor();
      static void pintarLimites();

};


void Auxiliar::gotoxy(int x,int y){

      HANDLE hCon;    //MANIPULAMOS LA CONSOLA.
      hCon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;    //DECLARAMOS UN OBJETO DE TIPO COORDENADAS.
      dwPos.X = x;    //SETEAMOS LAS COORDENADAS.
      dwPos.Y = y;

      SetConsoleCursorPosition(hCon, dwPos);   //UBICAMOS EN LA CONSOLA LAS COORDENADAS.
}

void Auxiliar::ocultarCursor(){

      HANDLE hCon;    //MANIPULAMOS LA CONSOLA.
      hCon = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_CURSOR_INFO  cci;   //ESTRUCTURA QUE MANEJA LA APARIENCIA DEL CURSOR.
      cci.dwSize = 2;             //TAMAÑO DEL CURSOR.
      cci.bVisible = FALSE;       //PARA QUE NO SE MUESTRE EN PANTALLA.

      SetConsoleCursorInfo(hCon,&cci);    //PASAMOS cci POR REFERENCIA PORQUE VAMOS A MODIFICAR LOS DATOS.
}

//FUNCION QUE DIBUJA LOS LIMITES EN PANTALLA.
/*
void Auxiliar::pintarLimites(){

      for(int x = 2;x<176;x++){
        gotoxy(x,3);printf("%c",205);   //DEJO FIJO y Y AUMENTO DE A UNO EN x EN LA PARTE SUPERIOR.
        gotoxy(x,45);printf("%c",205);   //DEJO FIJO y Y AUMENTO DE A UNO EN x EN LA PARTE INFERIOR.
      }


       for(int y = 4;y<45;y++){
        gotoxy(1,y);printf("%c",186);   //DEJO FIJO x Y AUMENTO DE A UNO EN y A LA IZQUIERDA.
        gotoxy(176,y);printf("%c",186);   //DEJO FIJO x Y AUMENTO DE A UNO EN y A LA DERECHA.
      }

    //AHORA PINTAMOS LAS ESQUINAS


    gotoxy(1,3); printf("%c",201);   //ESQUINA SUPERIOR IZQUIERDA.
    gotoxy(1,45); printf("%c",200);   //ESQUINA INFERIOR IZQUIERDA.
    gotoxy(176,3); printf("%c",187);   //ESQUINA SUPERIOR DERECHA.
    gotoxy(176,45); printf("%c",188);   //ESQUINA INFERIOR DERECHA.


}
*/


void Auxiliar::pintarLimites(){

     for(int x = 8 ; x < SCREEN_WIDTH;x++){
        gotoxy(x,3);printf("%c",205);   //DEJO FIJO y Y AUMENTO DE A UNO EN x EN LA PARTE SUPERIOR.
        gotoxy(x, SCREEN_HEIGHT - 4);printf("%c",205);   //DEJO FIJO y Y AUMENTO DE A UNO EN x EN LA PARTE INFERIOR.

      }

      for(int y = 4;y < SCREEN_HEIGHT - 4;y++){
        gotoxy(8,y);printf("%c",186);   //DEJO FIJO x Y AUMENTO DE A UNO EN y A LA IZQUIERDA.
        gotoxy(SCREEN_WIDTH,y);printf("%c",186);   //DEJO FIJO x Y AUMENTO DE A UNO EN y A LA DERECHA.
      }

       //AHORA PINTAMOS LAS ESQUINAS

      gotoxy(8,3); printf("%c",201);   //ESQUINA SUPERIOR IZQUIERDA.
      gotoxy(8,SCREEN_HEIGHT - 4); printf("%c",200);   //ESQUINA INFERIOR IZQUIERDA.
      gotoxy(SCREEN_WIDTH,3); printf("%c",187);   //ESQUINA SUPERIOR DERECHA.
      gotoxy(SCREEN_WIDTH,SCREEN_HEIGHT - 4); printf("%c",188);   //ESQUINA INFERIOR DERECHA.

}



#endif // AUXILIAR_H_INCLUDED
