// Defini��o:

#ifndef proDesenho_h
#define proDesenho_h

/* Essa biblioteca vai ser usada para definir todas as fun��es necess�rias para desenhar o programa, utilizando as fun��es
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

void limpaTela(void);
void desenhaMenu(void);
void desenhaMenuOp (int opcao);
void desenhaPtos(FILE *arq);
void desenhaJogador(void);
void desenhaBola(void);
void desenhaPontosJogo(void);
void desenhaVidas(void);
int desenhaNome(char nome[30]);
void desenhaBlocos(void);
void desenhaJogo(void);
void desenhaEndGame(void);
void desenhaPause(void);
void desenhaProx(void);
void desenhaFim(void);

// Fun��es para o Menu:
void limpaTela(void){               // Deixa a tela no estado original em preto.
    DrawRectangle(0, 0, 1000, 2000, BLACK);
}

void desenhaMenu(void){             // Desenha o Menu com o t�tulo, tr�s bot�es, e cr�ditos.

    DrawText("BreakoutINF", 240, 60, 50, WHITE);             // T�tulo do jogo.

    DrawRectangleGradientV(240, 150, 325, 50, ORANGE, GOLD); // Bot�o 'JOGAR'
    DrawRectangleLinesEx(botao1, 3, ORANGE);
        DrawText("JOGAR", 335, 156, 40, BLACK);

    DrawRectangleGradientV(240, 225, 325, 50, ORANGE, GOLD); // Bot�o 'PONTUA��O'
    DrawRectangleLinesEx(botao2, 3, ORANGE);
        DrawText("PONTUACAO", 275, 231, 40, BLACK);

    DrawRectangleGradientV(240, 300, 325, 50, ORANGE, GOLD); // Bot�o 'SAIR'
    DrawRectangleLinesEx(botao3, 3, ORANGE);
        DrawText("SAIR", 355, 306, 40, BLACK);

    DrawText("Beatriz e Kamille, 2022/01", 240, 380, 26, WHITE); // Cr�ditos
}

void desenhaMenuOp (int opcao){ // Desenha o bot�o em outra cor quando ele � selecionado.

    if (opcao == 0){
        DrawRectangleGradientV(240, 150, 325, 50, DARKPURPLE, PURPLE); // Bot�o 'JOGAR
        DrawRectangleLinesEx(botao1, 3, DARKPURPLE);
            DrawText("JOGAR", 335, 156, 40, WHITE);
    }
    if (opcao == 1){
        DrawRectangleGradientV(240, 225, 325, 50, DARKPURPLE, PURPLE); // Bot�o 'PONTUA��O'
        DrawRectangleLinesEx(botao2, 3, DARKPURPLE);
            DrawText("PONTUACAO", 275, 231, 40, WHITE);
    }
    if (opcao == 2){
        DrawRectangleGradientV(240, 300, 325, 50, DARKPURPLE, PURPLE); // Bot�o 'SAIR'
        DrawRectangleLinesEx(botao3, 3, DARKPURPLE);
            DrawText("SAIR", 355, 306, 40, WHITE);
    }
}


// Fun��es para a Pontua��o:
void desenhaPtos(FILE *arq){

    MELHOR jogadores[5];

    arq = fopen("top.bin", "rb");

    for (int i=0; i<5; i++){
        if (fread(&jogadores[i], sizeof(MELHOR), 1, arq) != 1){
            printf("Erro na leitura!\n");
        }
    }

    fclose(arq);

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

        DrawText(jogadores[0].nome, 200, 135, 40, WHITE); // NOME
        DrawText((TextFormat("%i", jogadores[0].pontos)), 600, 135, 40, WHITE); // PONTOS

    //POS 2
        DrawRectangleGradientV(100, 190, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos2, 3, ORANGE);
            DrawText("2", 113, 195, 40, BLACK);

        DrawText(jogadores[1].nome, 200, 195, 40, WHITE); // NOME
        DrawText((TextFormat("%i", jogadores[2].pontos)), 600, 195, 40, WHITE); // PONTOS

    //POS 3
        DrawRectangleGradientV(100, 250, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos3, 3, ORANGE);
            DrawText("3", 113, 255, 40, BLACK);

        DrawText(jogadores[2].nome, 200, 255, 40, WHITE); // NOME
        DrawText((TextFormat("%i", jogadores[2].pontos)), 600, 255, 40, WHITE); // PONTOS

    //POS 4
        DrawRectangleGradientV(100, 310, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos4, 3, ORANGE);
            DrawText("4", 113, 315, 40, BLACK);

        DrawText(jogadores[3].nome, 200, 315, 40, WHITE); // NOME
        DrawText((TextFormat("%i", jogadores[3].pontos)), 600, 315, 40, WHITE); // PONTOS


    //POS 5
        DrawRectangleGradientV(100, 370, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos5, 3, ORANGE);
        DrawText("5", 113, 375, 40, BLACK);

        DrawText(jogadores[4].nome, 200, 375, 40, WHITE); // NOME
        DrawText((TextFormat("%i", jogadores[4].pontos)), 600, 375, 40, WHITE); // PONTOS

}

// Fun��es para o jogo:
void desenhaJogador(void){                  // Desenha a raquete do Jogador

    DrawRectangle(jogador.posicao.x - jogador.tamanho.x/2, jogador.posicao.y - jogador.tamanho.y/2, jogador.tamanho.x, jogador.tamanho.y, WHITE);
}

void desenhaBola(void){

    DrawCircleV(bola.posicao, bola.raio, bola.cor);
}

void desenhaPontosJogo(void){               // Desenha a quantidade de pontos do Jogador

    DrawText(TextFormat("%i", jogador.pontos), 690, 390, 45, WHITE);

}

void desenhaVidas(void){                    // Desenha a quantidade de vidas do Jogador

    for (int i = 0; i < jogador.vidas; i++) DrawRectangle(20 + 40*i, TELA_ALTURA - 30, 35, 10, WHITE);
}

int desenhaNome(char nome[30]){

    int tela;
    int tecla;
    int letras=0;
    tecla=GetCharPressed();

    while(!IsKeyPressed(KEY_ENTER)){

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Qual o seu nome?", 190, 60, 50, WHITE);
        DrawRectangleLinesEx(nom1, 6, ORANGE);

        tecla=GetCharPressed();

        while(tecla>0 && letras<10){

            nome[letras] = tecla;
            nome[letras+1] = '\0';
            tecla = 0;
            letras++;
        }

        if (IsKeyPressed(KEY_BACKSPACE)){
            letras--;
            if (letras < 0){
                letras = 0;
            }
            nome[letras] = '\0';
        }

        DrawText(nome, 220, 210, 70, WHITE);
        EndDrawing();
    }

    tela = 0;

    return tela;
}

void desenhaBlocos(void){

    // Anda na matriz
    for (int i=0; i<B_LINHA; i++){
        for (int j=0; j<B_COLUNA; j++){

            if (bloco[i][j].ativo == true){
                DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, bloco[i][j].cor);

                switch (bloco[i][j].especial){
                    case 1: DrawRectangleLinesEx((Rectangle){bloco[i][j].posicao.x, bloco[i][j].posicao.y, bloco[i][j].tamanho.x,
                            bloco[i][j].tamanho.y}, 3, DARKGREEN);
                        break;
                    case 2: DrawRectangleLinesEx((Rectangle){bloco[i][j].posicao.x, bloco[i][j].posicao.y, bloco[i][j].tamanho.x,
                            bloco[i][j].tamanho.y}, 3, DARKBLUE);
                        break;
                    case 3: DrawRectangleLinesEx((Rectangle){bloco[i][j].posicao.x, bloco[i][j].posicao.y, bloco[i][j].tamanho.x,
                            bloco[i][j].tamanho.y}, 3, GOLD);
                        break;
                }
            }
        }
    }
}

void desenhaJogo(void){                     // Desenha o Jogo inteiro (jun��o de todas as fun��es de desenho do Jogo)

    desenhaJogador();       // Raquete
    desenhaBola();          // Bola
    desenhaVidas();         // Vidas
    desenhaPontosJogo();    // Pontua��o
    desenhaBlocos();

    if (pause){
        desenhaPause();
    }

}


// Fun��es para outros menus:

void desenhaEndGame(void){
    setlocale(LC_ALL, " ");

    DrawText("Fim de jogo!", TELA_LARGURA/3, TELA_ALTURA/3, 45, WHITE);

    DrawText("Sua pontuacaoo eh", TELA_LARGURA/6, TELA_ALTURA/2, 45, WHITE);
    DrawText(TextFormat("%i", jogador.pontos), TELA_LARGURA/1.3, TELA_ALTURA/2, 45, WHITE);

    DrawRectangleGradientV(15, 15, 45, 45, ORANGE, GOLD); // quadrado
        DrawRectangleLinesEx(volta1, 3, ORANGE);
    DrawText("V", 23, 21, 40, BLACK);
    DrawText("Voltar", 70, 21, 40, WHITE);

    DrawRectangleGradientV(530, 390, 45, 45, ORANGE, GOLD); // quadrado
        DrawRectangleLinesEx(prox, 3, ORANGE);
    //DrawText(">", 545, 385, 60, BLACK);
    DrawText("C", 539, 392, 45, BLACK);
    DrawText("Continuar", 590, 400, 40, WHITE);
}

void desenhaPause(void){

    DrawRectangle(240, 100, 300, 240, BLACK);
    DrawRectangleLinesEx(rec1, 3, ORANGE);

    DrawText("PAUSADO", 270, 130, 50, WHITE);

    DrawRectangleGradientV(270, 195, 45, 45, ORANGE, GOLD); //QUADRADO
    DrawRectangleLinesEx(con2, 3, ORANGE);
    DrawText("P", 279, 199, 40, BLACK);
    DrawText("CONTINUAR", 330, 205, 30, WHITE);
}

void desenhaProx(void){

    limpaTela();

    DrawText("Voce passou de nivel!", 130, 170, 50, WHITE);

    DrawRectangleGradientV(530, 390, 45, 45, ORANGE, GOLD); // quadrado
        DrawRectangleLinesEx(prox, 3, ORANGE);
    DrawText("C", 539, 392, 45, BLACK);
    DrawText("Continuar", 590, 400, 40, WHITE);

}

void desenhaFim(void){

    limpaTela();

    DrawText("Voce zerou o jogo!", 130, 170, 50, WHITE);

    DrawRectangleGradientV(530, 390, 45, 45, ORANGE, GOLD); // quadrado
        DrawRectangleLinesEx(prox, 3, ORANGE);
    DrawText("C", 539, 392, 45, BLACK);
    DrawText("Continuar", 590, 400, 40, WHITE);

}


#endif
