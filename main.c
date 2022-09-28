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
    int posPontos;
    char nome[30];
    int nivel=0;
    //float timePlayed = 0.0f;

    initJogo();

    InitWindow(TELA_LARGURA, TELA_ALTURA, TELA_NOME);
    SetTargetFPS(60);

    /*InitAudioDevice();
    Music music = LoadMusicStream("C:/Users/Admin/Documents/Breakout_Game/musicaTrab.mp3");
    PlayMusicStream(music);*/

    criaJogadores();

    while(!WindowShouldClose()){

        /*UpdateMusicStream(music);
        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);
        if (timePlayed > 1.0f) timePlayed = 1.0f;*/

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
            proxNivel = acabouBloco();
        }

        if (proxNivel == true){
            nivel++;
            desenhaProx();
            initBloco(nivel);
            if (IsKeyPressed(KEY_RIGHT)){ // NÃO SEI PQ ESSA DESGRAÇA NAO TA FUNCIONANDO MAS ERA PRA TÁ!!!!
                telaAtual = 2;
            }
        }

        if(gameOver == 1){
            limpaTela();
            desenhaEndGame();

            posPontos = pegaArquivo();   // pega arquivo de 5 melhores e vê se jogador.pontos é maior que um deles

            // pega o posPontos, pra ver se pegaArquivo retornou algum resultado
            if(posPontos != -1 && IsKeyPressed(KEY_RIGHT)){

                telaAtual = desenhaNome(nome);
                gravaArquivo(posPontos/*, nomeJogador*/);
                gameOver = 0;

            }

            if(IsKeyPressed(KEY_V)){
                initJogo();
                telaAtual = 0;
                gameOver = 0; // pra voltar pro menu e poder jogar de novo
            }
        }
    //}

        EndDrawing();
    }

    /*UnloadMusicStream(music);
    CloseAudioDevice();*/

    return 0;
}
