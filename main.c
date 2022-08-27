//BIBLIOTECAS:
#include "raylib.h"
#include "tudo.h"
#include "menu.h"
#include "desenha.h"
#include "highscore.h"
#include "play.h"

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
        ClearBackground(BLACK);
        //pegaArquivo(); TESTE PARA HIGHSCORE.H

        //pegaMatriz(1); TESTE PARA PLAY.H

        /*desenhaMenu();
        menu = decideMenu();*/

        if (menu == 0){
            limpaTela();
            DrawText("JOGAR", 335, 156, 40, WHITE);
        }
        else if (menu == 1){
            desenhaPtos();
            voltaMenu();
        }
        EndDrawing();
    }

    return 0;

}
