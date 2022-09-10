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

    //JOGADOR player;
    bool returnJogo = false; // retorna se o jogo terminou ou não
    int telaAtual = 0;
    int posPontos;
    int op;

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
             desenhaPtos();

             if(IsKeyPressed(KEY_V)){   // Volta pro Menu
                telaAtual = 0;
             }
        }

        if (telaAtual == 2){            // Jogo

            atualizaJogoDesenho();

            if(gameOver == 1){
                limpaTela();
                desenhaEndGame();

                posPontos = pegaArquivo();   // pega arquivo de 5 melhores e vê se jogador.pontos é maior que um deles

                // pega o posPontos, pra ver se pegaArquivo retornou algum resultado
                if(posPontos == 0 || posPontos == 1 || posPontos == 2 || posPontos == 3 || posPontos == 4){
                    gravaArquivo(posPontos);
                }



                if(IsKeyPressed(KEY_V)){
                    telaAtual = 0;
                    gameOver = 0; // pra voltar pro menu e poder jogar de novo
                    //TEM QUE VOLTAR A VIDA PRO MAX E ZERAR A PONTUAÇÃO DO JOGADOR


                }

            }


            //KAMILLE:
            //desenhaJogo();

            // FUNCAOJOGO(&returnJogo, &player.pontos);
                    // recebe returnJogo como ponteiro para poder retornar true quando o jogo acabar
                    // recebe player.pontos como ponteiro para poder setar a pontuação dele no final do jogo

            /*if(returnJogo == true){
                pegaArquivo(&player);
            }*/
        }

        EndDrawing();

    }

    return 0;
}
