//BIBLIOTECAS:
#include "raylib.h"
#include "tudo.h"
#include "menu.h"
#include "desenha.h"
#include "highscore.h"
#include "play.h"
#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int main(){

    InitWindow(TELA_LARGURA, TELA_ALTURA, TELA_NOME);
    SetTargetFPS(60);

    //Font fonte = LoadFont("others/alagard.ttf");

    while(!WindowShouldClose()){

        BeginDrawing();
        //pegaArquivo(); TESTE PARA HIGHSCORE.H

        //pegaMatriz(1); TESTE PARA PLAY.H

        completoMenu();

        EndDrawing();
    }

    return 0;

}
