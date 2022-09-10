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
    int x = 25, y = 20;                                             // posição x inicia em 25 e y em 20
    char blocos[B_LINHA][B_COLUNA];
    int cont = 0;

    pegaMatrizBlocos(blocos);                                       // pega a matriz do arquivo

    for(i=0; i<B_LINHA; i++){
        for(j=0; j<B_COLUNA; j++){
            switch(blocos[i][j]){                                   // faz um switch pra casa letra da matriz e entra no caractere que corresponde

                case 'R':   DrawRectangle(x, y, 60, 10, RED);
                    break;
                case 'G':   DrawRectangle(x, y, 60, 10, DARKGREEN);
                    break;
                case 'B':   DrawRectangle(x, y, 60, 10, DARKBLUE);
                    break;
                case 'Y':   DrawRectangle(x, y, 60, 10, YELLOW);
                    break;
                case 'X':   DrawRectangle(x, y, 60, 10, DARKPURPLE);
                    break;
                case '-':   DrawRectangle(x, y, 60, 10, BLACK);
                    break;
            }
            x = x + 75;                                             // sempre atualiza o x e cada bloco fica a uma distância de 50px um do outro
        }
            x = 25;                                                 // a posição dos blocos no eixo x sempre começa em 25
            y = y + 20;                                             /*  sempre que termina de desenhar uma linha, acrescenta 20px, ou seja,
                                                                        i = 0 --> y = 20   i = 1 --> y = 40       e assim segue*/
    }
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

void desenhaTeste(){

    int i, j;
    for (i=0; i<B_LINHA; i++){
        for (j=0; j<B_COLUNA; j++){ // Anda na matriz

            if (bloco[i][j].ativo == true){ // Se o bloco está ativo

                if ((i + j) % 2 == 0){
                    DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, BLUE);
                }
                else DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, RED);
            }
        }
    }

}

void desenhaBlocos2(void){

    char bloco_cores[B_LINHA][B_COLUNA];

    pegaMatrizBlocos(bloco_cores);

    int i, j;
    for (i=0; i<B_LINHA; i++){
        for (j=0; j<B_COLUNA; j++){ // Anda na matriz

            if (bloco_cores[i][j] == '-'){
                bloco[i][j].ativo = false;
            }

            if (bloco[i][j].ativo == true){ // Se o bloco está ativo

                switch (bloco_cores[i][j]){

                    case 'R':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, RED);
                                break;
                    case 'G':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, DARKGREEN);
                                break;
                    case 'B':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, DARKBLUE);
                                break;
                    case 'Y':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, YELLOW);
                                break;
                    case 'X':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, DARKPURPLE);
                                break;
                }
            }
        }
    }
}

void desenhaJogo(){                     // Desenha o Jogo inteiro (junção de todas as funções de desenho do Jogo)
    //desenhaBlocos();        // Blocos
    desenhaJogador();       // Raquete
    desenhaBola();          // Bola
    desenhaVidas();         // Vidas
    desenhaPontosJogo();    // Pontuação
    //desenhaTeste();
    desenhaBlocos2();
}


void desenhaEndGame(){
    setlocale(LC_ALL, " ");

    DrawText("Fim de jogo!", TELA_LARGURA/3, TELA_ALTURA/3, 45, WHITE);

    DrawText("Sua pontuacaoo eh", TELA_LARGURA/6, TELA_ALTURA/2, 45, WHITE);
    DrawText(TextFormat("%i", jogador.pontos), TELA_LARGURA/1.3, TELA_ALTURA/2, 45, WHITE);

    DrawRectangleGradientV(15, 15, 45, 45, ORANGE, GOLD); // quadrado
            DrawRectangleLinesEx(volta1, 3, ORANGE);
        DrawText("V", 23, 21, 40, BLACK);
        DrawText("Voltar", 70, 21, 40, WHITE);
}


// Funções para o pause:

void desenhaPause(){ ClearBackground(BLACK); }


#endif
