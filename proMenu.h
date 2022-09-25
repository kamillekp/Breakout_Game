// Defini��o:

#ifndef proMenu_h
#define proMenu_h

/* Essa biblioteca vai ser usada para definir todas as fun��es necess�rias para a cria��o da l�gica do menu, utilizando
as fun��es predefinidas da biblioteca Raylib */

// Bibliotecas utilizadas:
#include "raylib.h"
#include <stdio.h>

#include "proDesenho.h"
#include "proJogo.h"
#include "praDefinir.h"
#include "proHighscore.h"
#include "proPause.h"
#include "proPause.h"

// Fun��es para o Menu principal:

void upDownMenu (int op){ // Muda a op��o de acordo com as teclas pressionadas

    if (IsKeyPressed(KEY_UP)){
        switch (op){
            case 0: *ptr_op = 2;
                break;
            case 1: *ptr_op = 0;
                break;
            case 2: *ptr_op = 1;
                break;
        }
    }

    if (IsKeyPressed(KEY_DOWN)){
        switch (op){
            case 0: *ptr_op = 1;
                break;
            case 1: *ptr_op = 2;
                break;
            case 2: *ptr_op = 0;
                break;

        }
    }

    desenhaMenuOp(op);
}

int decideTela(int *telaAtual){ // Decide a tela que vai ser mostrada

    if (IsKeyUp(KEY_ENTER)){
        upDownMenu(op);
    }

    if (IsKeyPressed(KEY_ENTER)){
        switch (op){
            case 0: *telaAtual = 2; // Jogo
                    break;
            case 1: *telaAtual = 1; // Pontua��o
                    break;
            case 2: CloseWindow(); // Sair
                    break;
        }
    }
}


#endif
