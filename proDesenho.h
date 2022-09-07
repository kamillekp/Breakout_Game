// Definição:

#ifndef proDesenho_h
#define proDesenho_h

/* Essa biblioteca vai ser usada para definir todas as funções necessárias para desenhar o programa, utilizando as funções
predefinidas da biblioteca Raylib */

// Bibliotecas utilizadas:
#include "raylib.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "proJogo.h"
#include "proMenu.h"
#include "praDefinir.h"
#include "proHighscore.h"
#include "proPause.h"

// Funções para o Menu:

void limpaTela(){ // Deixa a tela no estado original em preto.
    DrawRectangle(0, 0, 1000, 2000, BLACK);

}

void desenhaMenu(){ // Desenha o Menu com o título, três botões, e créditos.

    DrawText("BreakoutINF", 240, 60, 50, WHITE); // Título do jogo.

    DrawRectangleGradientV(240, 150, 325, 50, ORANGE, GOLD); // Botão 'JOGAR'
    DrawRectangleLinesEx(botao1, 3, ORANGE);
        DrawText("JOGAR", 335, 156, 40, BLACK);

    DrawRectangleGradientV(240, 225, 325, 50, ORANGE, GOLD); // Botão 'PONTUAÇÃO'
    DrawRectangleLinesEx(botao2, 3, ORANGE);
        DrawText("PONTUACAO", 275, 231, 40, BLACK);

    DrawRectangleGradientV(240, 300, 325, 50, ORANGE, GOLD); // Botão 'SAIR'
    DrawRectangleLinesEx(botao3, 3, ORANGE);
        DrawText("SAIR", 355, 306, 40, BLACK);

    DrawText("Beatriz e Kamille, 2022/01", 240, 380, 26, WHITE); // Créditos
}

void desenhaMenuOp (int opcao){ // Desenha o botão em outra cor quando ele é selecionado.

    if (opcao == 0){
        DrawRectangleGradientV(240, 150, 325, 50, DARKPURPLE, PURPLE); // Botão 'JOGAR
        DrawRectangleLinesEx(botao1, 3, DARKPURPLE);
            DrawText("JOGAR", 335, 156, 40, WHITE);
    }
    if (opcao == 1){
        DrawRectangleGradientV(240, 225, 325, 50, DARKPURPLE, PURPLE); // Botão 'PONTUAÇÃO'
        DrawRectangleLinesEx(botao2, 3, DARKPURPLE);
            DrawText("PONTUACAO", 275, 231, 40, WHITE);
    }
    if (opcao == 2){
        DrawRectangleGradientV(240, 300, 325, 50, DARKPURPLE, PURPLE); // Botão 'SAIR'
        DrawRectangleLinesEx(botao3, 3, DARKPURPLE);
            DrawText("SAIR", 355, 306, 40, WHITE);
    }
}


// Funções para a Pontuação:

int desenhaPtos(){ // Desenha o menu Pontuação

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


// Funções para o jogo:

void desenhaBlocos(){
    int i, j;
    char blocos;



    /*blocos =*/ pegaMatrizBlocos();            // tentativa de pegar matriz para desenhar blocos, spoiler: error

    /*for(i=0; i<5; i++){
        for(j=0; j<10; j++){
            switch(blocos[i][j]){

                case 'R':   printf(" Red");
                            //DrawRectangle(x, y, 60, 10, RED);
                    break;
                case 'G':   printf(" Green");
                            //DrawRectangle(x, y, 60, 10, DARKGREEN);
                    break;
                case 'B':   printf(" Blue");
                            //DrawRectangle(x, y, 60, 10, DARKBLUE);
                    break;
                case 'Y':   printf(" Yellow");
                            //DrawRectangle(x, y, 60, 10, YELLOW);
                    break;
                case 'X':   printf(" Purple");
                            //DrawRectangle(x, y, 60, 10, DARKPURPLE);
                    break;
                case '-':   printf(" Blank");
                            //DrawRectangle(x, y, 60, 10, BLACK);
                    break;
            }
        }
    }*/
}

void desenhaJogador(){                  // Desenha a raquete do Jogador

    DrawRectangle(jogador.posicao.x - jogador.tamanho.x/2, jogador.posicao.y - jogador.tamanho.y/2, jogador.tamanho.x, jogador.tamanho.y, WHITE);
}

void desenhaBola(){                     // Desenha a bola

    DrawCircleV(bola.posicao, bola.raio, bola.cor);
}

void desenhaPontosJogo(){               // Desenha a quantidade de pontos do Jogador

    DrawText(TextFormat("%i", jogador.pontos), 690, 390, 45, WHITE);

}

void desenhaVidas(){                    // Desenha a quantidade de vidas do Jogador

    for (int i = 0; i < jogador.vidas; i++) DrawRectangle(20 + 40*i, TELA_ALTURA - 30, 35, 10, WHITE);
}

void desenhaJogo(){                     // Desenha o Jogo inteiro (junção de todas as funções de desenho do Jogo)
    desenhaBlocos();        // Blocos
    desenhaJogador();       // Raquete
    desenhaBola();          // Bola
    desenhaVidas();         // Vidas
    desenhaPontosJogo();    // Pontuação
}

void desenhaEndGame(){
    setlocale(LC_ALL, " ");

    DrawText("Fim de jogo!", TELA_LARGURA/3, TELA_ALTURA/3, 45, WHITE);

    DrawText("Sua pontuação é ", TELA_LARGURA/4, TELA_ALTURA/2, 45, WHITE);
    DrawText(jogador.pontos, TELA_LARGURA/4, TELA_ALTURA/2, 45, WHITE);         // não aparece

    DrawRectangleGradientV(15, 15, 45, 45, ORANGE, GOLD); // quadrado
            DrawRectangleLinesEx(volta1, 3, ORANGE);
        DrawText("V", 23, 21, 40, BLACK);
        DrawText("Voltar", 70, 21, 40, WHITE);
}


// Funções para o pause:

void desenhaPause(){ ClearBackground(BLACK); }


#endif
