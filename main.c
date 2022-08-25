//BIBLIOTECAS:
#include "raylib.h"
#include "tudo.h"
#include "menu.h"
#include "desenha.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>


int main(){

    InitWindow(TELA_LARGURA, TELA_ALTURA, TELA_NOME);
    SetTargetFPS(60);

    //Font fonte = LoadFont("others/alagard.ttf");

    while(!WindowShouldClose()){

        BeginDrawing();

        desenhaMenu();
        menu = decideMenu(); // essa merda n funciona direito;

        if (menu == 0){
            DrawText("JOGAR", 335, 156, 40, BLACK);
        }
        else if (menu == 1){
            desenhaPtos();
        }
        EndDrawing();
    }

    return 0;

}
