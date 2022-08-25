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
int menu=0;
int *ponteiro = &opcao;

void CimaOuBaixo(opcao){
//Essa função muda as opcoes do menu

    if(IsKeyPressed(KEY_DOWN)){
        switch (opcao){
        case 0: *ponteiro = 1; //
                break;
        case 1: *ponteiro = 2;
                break;
        case 2: *ponteiro = 0;
                break;
        }
    }
    else if(IsKeyPressed(KEY_UP)){
        switch (opcao){
        case 0: *ponteiro = 2;
                break;
        case 1: *ponteiro = 0;
                break;
        case 2: *ponteiro = 1;
                break;
        }
    }
    desenhaMenuOp(opcao);
}

int decideMenu(void){

    if (IsKeyUp(KEY_ENTER)){
    CimaOuBaixo(opcao);
    }

    if (IsKeyPressed(KEY_ENTER)){
        switch (opcao){
        case 0: menu = 0; // JOGO
                break;
        case 1: menu = 1; // PONTUAÇÃO
                break;
        case 2: CloseWindow(); // SAIR
                break;
        }
    }
    return menu;
}

#endif


