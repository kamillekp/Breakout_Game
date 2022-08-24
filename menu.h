#ifndef MENU_H
#define MENU_H

//BIBLIOTECAS:

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>


//VER COMO VAI FUNCIONAR OPCAO COMO PONTEIRO
int opcao=0;

void CimaOuBaixo(opcao){
//Essa função muda as opcoes do menu

    if(IsKeyDown(KEY_DOWN)){
        switch (opcao){
        case 0: opcao = 1;
                break;
        case 1: opcao = 2;
                break;
        case 2: opcao = 0;
                break;
        }
    }
    else if(IsKeyPressed(KEY_UP)){
        switch (opcao){
        case 0: opcao = 2;
                break;
        case 1: opcao = 0;
                break;
        case 2: opcao = 1;
                break;
        }
    }
    desenhaMenuOp(opcao);
}

void decideMenu(void){

    if (IsKeyUp(KEY_ENTER)){
    CimaOuBaixo(opcao);
    }

    else if (IsKeyPressed(KEY_ENTER)){
        switch (opcao){
        case 0: DrawText("JOGO", TELA_LARGURA/2, TELA_ALTURA/5, 100, BLACK); // mudar pra que chama o jogo dps
                break;
        case 1: DrawText("PTOS", TELA_LARGURA/2, TELA_ALTURA/5, 100, BLACK); // mudar pra que chama o highscores dps
                break;
        case 2: WindowShouldClose; // NÃO SE ISSO FUNCIONA mas é pra sair
                break;
        }
    }
}

#endif


