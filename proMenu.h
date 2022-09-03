// Defini��o:

#define proMenu_h

/* Essa biblioteca vai ser usada para definir todas as fun��es necess�rias para a cria��o da l�gica do menu, utilizando
as fun��es predefinidas da biblioteca Raylib */

// Bibliotecas utilizadas:
#include "raylib.h"
#include <stdio.h>

// Vari�veis utilizadas:
int op = 0;
int *ptr_op = &op;
int tela = 0;

// Fun��es para o Menu principal:

void upDownMenu (int op){

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

int decideTela(void){

    if (IsKeyUp(KEY_ENTER)){
        upDownMenu(op);
    }

    if (IsKeyPressed(KEY_ENTER)){
        switch (op){
            case 0: tela = 2; // Jogo
                    break;
            case 1: tela = 1; // Pontua��o
                    break;
            case 2: CloseWindow(); // Sair
                    break;
        }
    }

    return tela;
}


