#define DESENHA_H

//BIBLIOTECAS:

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

void limpaTela(){ // LIMPA A TELA
    DrawRectangle(100, 50, 1000, 2000, BLACK);
}

void desenhaMenu(){ // DESENHA MENU PRINCIPAL

    ClearBackground(BLACK);
    DrawText("BreakoutINF", 240, 60, 50, WHITE); // TITULO DO JOGO

    DrawRectangleGradientV(240, 150, 325, 50, ORANGE, GOLD); // BOTAO JOGAR
    DrawRectangleLinesEx(rec1, 3, ORANGE);
        DrawText("JOGAR", 335, 156, 40, BLACK);

    DrawRectangleGradientV(240, 225, 325, 50, ORANGE, GOLD); // BOTAO PONTUAÇÃO
    DrawRectangleLinesEx(rec2, 3, ORANGE);
        DrawText("PONTUACAO", 275, 231, 40, BLACK);

    DrawRectangleGradientV(240, 300, 325, 50, ORANGE, GOLD); // BOTAO SAIR
    DrawRectangleLinesEx(rec3, 3, ORANGE);
        DrawText("SAIR", 355, 306, 40, BLACK);


    DrawText("Beatriz e Kamille, 2022/01", 240, 380, 26, WHITE); //CRÉDITOS
}

void desenhaMenuOp (int opcao){ // QUANDO O BOTÃO ESTÁ "ESCOLHIDO"

    if (opcao == 0){
        DrawRectangleGradientV(240, 150, 325, 50, DARKPURPLE, PURPLE); // BOTAO JOGAR
        DrawRectangleLinesEx(rec1, 3, DARKPURPLE);
            DrawText("JOGAR", 335, 156, 40, WHITE);
    }
    if (opcao == 1){
        DrawRectangleGradientV(240, 225, 325, 50, DARKPURPLE, PURPLE); // BOTAO PONTUACAO
        DrawRectangleLinesEx(rec2, 3, DARKPURPLE);
            DrawText("PONTUACAO", 275, 231, 40, WHITE);
    }
    if (opcao == 2){
        DrawRectangleGradientV(240, 300, 325, 50, DARKPURPLE, PURPLE); // BOTAO SAIR
        DrawRectangleLinesEx(rec3, 3, DARKPURPLE);
            DrawText("SAIR", 355, 306, 40, WHITE);
    }
}

void desenhaPtos(){ // DESENHA MENU PONTUAÇÃO

    FILE *ptArq;
    char str[10][100];

    //abrindo o arquivo_frase somente para leitura
    ptArq = fopen("highscore.bin", "r");

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

        fgets(str[0], 100, ptArq);
        DrawText(str[0], 200, 135, 40, WHITE); // NOME

        fgets(str[1], 100, ptArq);
        DrawText(str[1], 600, 135, 40, WHITE); // PONTOS

    //POS 2
        DrawRectangleGradientV(100, 190, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos2, 3, ORANGE);
            DrawText("2", 113, 195, 40, BLACK);

        fgets(str[2], 100, ptArq);
        DrawText(str[2], 200, 195, 40, WHITE); // NOME

        fgets(str[3], 100, ptArq);
        DrawText(str[3], 600, 195, 40, WHITE); // PONTOS

    //POS 3
        DrawRectangleGradientV(100, 250, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos3, 3, ORANGE);
            DrawText("3", 113, 255, 40, BLACK);

        fgets(str[4], 100, ptArq);
        DrawText(str[4], 200, 255, 40, WHITE); // NOME

        fgets(str[5], 100, ptArq);
        DrawText(str[5], 600, 255, 40, WHITE); // PONTOS

    //POS 4
        DrawRectangleGradientV(100, 310, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos4, 3, ORANGE);
            DrawText("4", 113, 315, 40, BLACK);

        fgets(str[6], 100, ptArq);
        DrawText(str[6], 200, 315, 40, WHITE); // NOME

        fgets(str[7], 100, ptArq);
        DrawText(str[7], 600, 315, 40, WHITE); // PONTOS


    //POS 5
        DrawRectangleGradientV(100, 370, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos5, 3, ORANGE);
        DrawText("5", 113, 375, 40, BLACK);

        fgets(str[8], 100, ptArq);
        DrawText(str[8], 200, 375, 40, WHITE); // NOME

        fgets(str[9], 100, ptArq);
        DrawText(str[9], 600, 375, 40, WHITE); // PONTOS

        fclose(ptArq);
}

void desenhaJogador(){ // DESENHA JOGADOR

    //DrawRectangleV(Jogador.Posicao, Jogador.Tamanho, WHITE); // RAQUETE
    DrawRectangle(Jogador.posX, Jogador.posY, Jogador.tamX, Jogador.tamY, WHITE);
}

void desenhaJogo(){ // DESENHA JOGO (junção de todas as funções)

    desenhaJogador(); // RAQUETE

}
