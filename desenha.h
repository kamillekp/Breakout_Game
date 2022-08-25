#define DESENHA_H

//BIBLIOTECAS:

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

void limpaTela(){
    DrawRectangle(100, 50, 1000, 2000, BLACK);
}

void desenhaMenu(){

    ClearBackground(BLACK);
    DrawText("BreakoutINF", 240, 60, 50, WHITE); // TITULO DO JOGO

    DrawRectangleGradientV(240, 150, 325, 50, ORANGE, GOLD); // BOTAO JOGAR
        DrawText("JOGAR", 335, 156, 40, BLACK);
        DrawRectangleLinesEx(botao1, 3, ORANGE);

    DrawRectangleGradientV(240, 225, 325, 50, ORANGE, GOLD); // BOTAO PONTUA��O
        DrawText("PONTUACAO", 275, 231, 40, BLACK);
        DrawRectangleLinesEx(botao2, 3, ORANGE);

    DrawRectangleGradientV(240, 300, 325, 50, ORANGE, GOLD); // BOTAO SAIR
        DrawText("SAIR", 355, 306, 40, BLACK);
        DrawRectangleLinesEx(botao3, 3, ORANGE);


    DrawText("Beatriz e Kamille, 2022/01", 240, 380, 26, WHITE); //CREDITOS
}

void desenhaMenuOp (opcao){ // RECEBE OPCAO POR PONTEIRO??

    if (opcao == 0){
        DrawRectangleGradientV(240, 150, 325, 50, PURPLE, DARKPURPLE); // BOTAO JOGAR
            DrawText("JOGAR", 335, 156, 40, WHITE);
            DrawRectangleLinesEx(botao1, 3, DARKPURPLE);
    }
    if (opcao == 1){
        DrawRectangleGradientV(240, 225, 325, 50, PURPLE, DARKPURPLE); // BOTAO PONTUA��O
            DrawText("PONTUACAO", 275, 231, 40, WHITE);
            DrawRectangleLinesEx(botao2, 3, DARKPURPLE);
    }
    if (opcao == 2){
        DrawRectangleGradientV(240, 300, 325, 50, PURPLE, DARKPURPLE); // BOTAO SAIR
            DrawText("SAIR", 355, 306, 40, WHITE);
            DrawRectangleLinesEx(botao3, 3, DARKPURPLE);
    }
}

void desenhaPtos(){ // aqui tem que usar o coisa de high score que o sor deu, modificar os valores de acordo com aquilo

    limpaTela();
    DrawText("TOP SCORES", 240, 60, 50, WHITE); // TITULO DO JOGO

    //VOLTA
        DrawRectangleGradientV(15, 15, 45, 45, ORANGE, GOLD); //QUADRADO
            DrawRectangleLinesEx(volta1, 3, ORANGE);
        DrawText("V", 23, 21, 40, BLACK);
        DrawText("Voltar", 70, 21, 40, WHITE);

    //POS 1
        DrawRectangleGradientV(100, 130, 45, 45, ORANGE, GOLD); //QUADRADO
            DrawRectangleLinesEx(pos1, 3, ORANGE);
        DrawText("1", 118, 135, 40, BLACK); //POS
        DrawText("JOGADOR1", 200, 135, 40, WHITE); //NOME
        DrawText("9999", 600, 135, 40, WHITE); //PONTOS

    //POS 2
        DrawRectangleGradientV(100, 190, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos2, 3, ORANGE);
        DrawText("2", 113, 195, 40, BLACK);
        DrawText("O MAX EH ISSO 16", 200, 195, 40, WHITE); //NOME
        DrawText("9999", 600, 195, 40, WHITE); //PONTOS

    //POS 3
        DrawRectangleGradientV(100, 250, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos3, 3, ORANGE);
        DrawText("3", 113, 255, 40, BLACK);
        DrawText("JOGADOR3", 200, 255, 40, WHITE); //NOME
        DrawText("0000", 600, 255, 40, WHITE); //PONTOS

    //POS 4
        DrawRectangleGradientV(100, 310, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos4, 3, ORANGE);
        DrawText("4", 113, 315, 40, BLACK);
        DrawText("JOGADOR4", 200, 315, 40, WHITE); //NOME
        DrawText("9999", 600, 315, 40, WHITE); //PONTOS

    //POS 5
        DrawRectangleGradientV(100, 370, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos5, 3, ORANGE);
        DrawText("5", 113, 375, 40, BLACK);
        DrawText("JOGADOR5", 200, 375, 40, WHITE); //NOME
        DrawText("9999", 600, 375, 40, WHITE); //PONTOS

}


