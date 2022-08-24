#define DESENHA_H

//BIBLIOTECAS:

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

void desenhaMenu(){

    ClearBackground(BLACK);
    DrawText("BreakoutINF", 240, 60, 50, WHITE); // TITULO DO JOGO

    DrawRectangleGradientV(240, 150, 325, 50, ORANGE, GOLD); // BOTAO JOGAR
        DrawText("JOGAR", 335, 156, 40, BLACK);
    DrawRectangleGradientV(240, 225, 325, 50, ORANGE, GOLD); // BOTAO PONTUA플O
        DrawText("PONTUACAO", 275, 231, 40, BLACK);
    DrawRectangleGradientV(240, 300, 325, 50, ORANGE, GOLD); // BOTAO SAIR
        DrawText("SAIR", 355, 306, 40, BLACK);

    DrawText("Beatriz e Kamille, 2022/01", 240, 380, 26, WHITE);
}

void desenhaMenuOp (opcao){ // RECEBE OPCAO POR PONTEIRO??

    if (opcao == 0){
        DrawRectangleGradientV(240, 150, 325, 50, PURPLE, DARKPURPLE);
            DrawText("JOGAR", 335, 156, 40, WHITE);
        //DrawRectangleLines(240, 150, 325, 50, WHITE); // LINHA PRO BOTAO JOGAR
    }
    if (opcao == 1){
        DrawRectangleGradientV(240, 225, 325, 50, PURPLE, DARKPURPLE); // BOTAO PONTUA플O
            DrawText("PONTUACAO", 275, 231, 40, WHITE);
        //DrawRectangleLines(240, 225, 325, 50, WHITE); // LINHA PRO BOTAO PONTUA플O
    }
    if (opcao == 2){
        DrawRectangleGradientV(240, 300, 325, 50, PURPLE, DARKPURPLE); // BOTAO SAIR
            DrawText("SAIR", 355, 306, 40, WHITE);
        //DrawRectangleLines(240, 300, 325, 50, WHITE); // LINHA PRO BOTAO SAIR
    }
}

void desenhaPtos(){ // aqui tem que usar o coisa de high score que o sor deu, modificar os valores de acordo com aquilo

    ClearBackground(BLACK);
    DrawText("TOP SCORES", 240, 60, 50, WHITE); // TITULO DO JOGO

    //POS 1
        DrawRectangleGradientV(100, 130, 45, 45, ORANGE, GOLD); //QUADRADO
        DrawText("1", 118, 135, 40, BLACK); //POS
        DrawText("JOGADOR1", 200, 135, 40, WHITE); //NOME
        DrawText("9999", 600, 135, 40, WHITE); //PONTOS

    //POS 2
        DrawRectangleGradientV(100, 190, 45, 45, ORANGE, GOLD);
        DrawText("2", 113, 195, 40, BLACK);
        DrawText("O MAX EH ISSO 16", 200, 195, 40, WHITE); //NOME
        DrawText("9999", 600, 195, 40, WHITE); //PONTOS

    //POS 3
        DrawRectangleGradientV(100, 250, 45, 45, ORANGE, GOLD);
        DrawText("3", 113, 255, 40, BLACK);
        DrawText("JOGADOR3", 200, 255, 40, WHITE); //NOME
        DrawText("0000", 600, 255, 40, WHITE); //PONTOS

    //POS 4
        DrawRectangleGradientV(100, 310, 45, 45, ORANGE, GOLD);
        DrawText("4", 113, 315, 40, BLACK);
        DrawText("JOGADOR4", 200, 315, 40, WHITE); //NOME
        DrawText("9999", 600, 315, 40, WHITE); //PONTOS

    //POS 5
        DrawRectangleGradientV(100, 370, 45, 45, ORANGE, GOLD);
        DrawText("5", 113, 375, 40, BLACK);
        DrawText("JOGADOR5", 200, 375, 40, WHITE); //NOME
        DrawText("9999", 600, 375, 40, WHITE); //PONTOS

    /*DrawRectangle(int posX, int posY, int width, int height, Color color); // QUADRADO
    DrawText(const char *text, int posX, int posY, int fontSize, Color color); //  POSI플O
    DrawText(const char *text, int posX, int posY, int fontSize, Color color); // NOME DO JOGADOR
    DrawText(const char *text, int posX, int posY, int fontSize, Color color); // PONTOS
    */
}


