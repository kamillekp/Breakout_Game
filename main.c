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
        //desenhaPtos();
        decideMenu(); // fazer essa funcao mexer em um ponteiro quem sabe

        /*if (ponteiro){
            //funcoes do jogo
        }
        else if (ponteiro){
            //funcoes do highscore
            desenhaPtos();
        }
        else //sair
        */
        EndDrawing();
    }

    return 0;

}
