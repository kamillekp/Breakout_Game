#include "proDesenho.h"
#include "proJogo.h"
#include "proMenu.h"
#include "praDefinir.h"
#include "proHighscore.h"

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main(){

    int telaAtual = 0;
    int nivel=0;
    int flagC=0;

    MELHOR ultimo;
    FILE *arq;
    MELHOR melhores[5];

    char nome[30];
    bzero(nome, 30);

    // QUANDO PRECISAR VOLTAR A LISTA PRO INICIO DESCOMENTA AS FUNÇÕES
    // Coloca a lista ficticia no vetor
    ficticiaLista(melhores);
    // Coloca no arquivo e ordena ela
    fazLista(melhores, arq);

    initJogo();

    InitWindow(TELA_LARGURA, TELA_ALTURA, TELA_NOME);
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground(BLACK);

        if (telaAtual==0){              // Menu principal
            desenhaMenu();
            decideTela(&telaAtual);
        }

        if (telaAtual == 1){            // Pontuação
             desenhaPtos(arq);

             if(IsKeyPressed(KEY_V)){   // Volta pro Menu
                telaAtual = 0;
             }
        }

        if (telaAtual == 2){            // Jogo
            atualizaJogoDesenho();
            proxNivel = acabouBloco();
        }

        if (proxNivel == true){

            if (nivel == 3){

                while(IsKeyUp(KEY_C) && flagC==0){

                    BeginDrawing();

                    desenhaFim();

                    EndDrawing();

                    if (IsKeyPressed(KEY_C)){
                        flagC = 1;
                    }
                }
                proxNivel = false;
                gameOver = 1;
            }
            else{
                nivel++;
                initBloco(nivel);
                initBola();
                jogador.posicao = (Vector2){TELA_LARGURA/2, TELA_ALTURA*7/8};
                jogador.vidas = MAX_VIDAS;

                while(IsKeyUp(KEY_C) && nivel<3){
                    BeginDrawing();

                    desenhaProx();

                    EndDrawing();
                }
                telaAtual = 2;
                proxNivel = false;
            }
        }

        if(gameOver == 1){
            limpaTela();
            desenhaEndGame();

            ultimo = ultimoLista();

            if (jogador.pontos>ultimo.pontos){
                telaAtual = desenhaNome(nome);
                insereLista(jogador.pontos, nome);
                initJogo();
                gameOver = 0;
                bzero(nome, 30);

            }

            if(IsKeyPressed(KEY_V)){
                initJogo();
                telaAtual = 0;
                gameOver = 0; // pra voltar pro menu e poder jogar de novo
            }
        }

        EndDrawing();
    }

    return 0;
}
