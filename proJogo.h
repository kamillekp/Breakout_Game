// Definição:

#ifndef proJogo_h
#define proJogo_h

/* Essa biblioteca vai ser usada para definir todas as funções necessárias para a criação da lógica do jogo, utilizando
as funções predefinidas da biblioteca Raylib */

// Bibliotecas utilizadas:

#include "raylib.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "proDesenho.h"
#include "proMenu.h"
#include "praDefinir.h"
#include "proHighscore.h"
#include "proPause.h"

void initJogo(void){

    // Inicializa raquete
    jogador.posicao = (Vector2){TELA_LARGURA/2, TELA_ALTURA*7/8};
    jogador.tamanho = (Vector2){TELA_LARGURA/10, 20};
    jogador.vidas = MAX_VIDAS;
    jogador.pontos = 0;

    // Inicializa bola
    bola.posicao = (Vector2) {TELA_LARGURA/2, TELA_ALTURA*2/3};
    bola.velocidade = (Vector2){0, 0};
    bola.raio = 7;
    bola.ativa = false;
    bola.cor = ORANGE;

    // Inicializa blocos
    tamBloco = (Vector2){GetScreenWidth()/BLOCOS_LINHA, 40};

    for (int i = 0; i < BLOCOS_LINHA; i++){
        for (int j = 0; j < BLOCOS_COLUNA; j++){
            bloco[i][j].posicao = (Vector2){j*tamBloco.x + tamBloco.x/2, i*tamBloco.y + BLOCOS_INICIAL};
            bloco[i][j].ativo = true;
        }
    }
}

void pegaMatrizBlocos (char blocos[5][10]){
    FILE *ptrBlocos;
    int i = 0, j = 0;
    char t;

    ptrBlocos = fopen("nivel1.txt", "r");                   // abre o arquivo para leitura
    for(i=0; i<5; i++){
        for(j=0; j<10; j++){
            blocos[i][j] = fgetc(ptrBlocos);                // pega cada caractere do arquivo
        }
    }

    fclose(ptrBlocos);
}

void mexeRaquete(void){                                     // Função da lógica do movimento da raquete

    if (IsKeyDown(KEY_LEFT)){
        jogador.posicao.x -= 5;                             // diminui pos_x em 5 VAI PRA ESQUERDA
    }
    if ((jogador.posicao.x - jogador.tamanho.x/2) <= 0){    //se chegou na borda da esquerda,
        jogador.posicao.x = jogador.tamanho.x/2;            // não deixa ir mais pra esquerda
    }
    if (IsKeyDown(KEY_RIGHT)){
        jogador.posicao.x += 5;                             // aumenta pos_x em 5 VAI PRA DIREITA
    }
    if ((jogador.posicao.x + jogador.tamanho.x/2) >= TELA_LARGURA){     //se chegou na borda da direita
        jogador.posicao.x = TELA_LARGURA - jogador.tamanho.x/2;         // nao deixa ir pra direita
    }
}

void lancaBola(void){                                       // Função para a lógica do lançamento da bola
    int random = (- 2 + (rand() % (2 + 2 + 1)));

    if (!bola.ativa){                                       // Se a bola não está ativa (começo do jogo)

        if (IsKeyPressed(KEY_SPACE)){                       // Se apertar no espaço, a bola fica ativa

            bola.ativa = true;
            bola.velocidade = (Vector2){random, -7};
        }
     }
}

void mexeBola(void){                                        // Função para a lógica do movimento da bola

    if (bola.ativa){                        // Se a bola está ativa, se mexe pras direções de acordo com a velocidade da bola

        bola.posicao.x += bola.velocidade.x;
        bola.posicao.y += bola.velocidade.y;
    }

    else{
        bola.posicao = (Vector2){jogador.posicao.x, TELA_ALTURA*7/8 - 30 }; // Se não está ativa, fica parada no lugar original
    }
}

void bateParede(void){                                      // Função para a lógica da bola rebater nas paredes

    if (((bola.posicao.x + bola.raio) >= TELA_LARGURA) || ((bola.posicao.x - bola.raio) <= 0)){
        bola.velocidade.x *= -1;
    }

    if ((bola.posicao.y - bola.raio) <= 0){
        bola.velocidade.y *= -1;
    }

    if ((bola.posicao.y + bola.raio) >= TELA_ALTURA){       // Se passar da parte de baixo da tela, desativa a bola

        bola.velocidade = (Vector2){0, 0};
        bola.ativa = false;

        jogador.vidas--;

        if(jogador.vidas == 0 /*|| blocos == 0*/) {
            gameOver = true;
        }
    }
}

void bateJogador(){                                         // Função para a lógica da bola rebater na raquete

    // CheckCollisionCircleRec --> função que checa se teve colisão entre um circulo e um retangulo
    if (CheckCollisionCircleRec (bola.posicao, bola.raio, (Rectangle){jogador.posicao.x - jogador.tamanho.x/2,
                                                           jogador.posicao.y - jogador.tamanho.y/2, jogador.tamanho.x,
                                                           jogador.tamanho.y})){

        if (bola.velocidade.y > 0){
            bola.velocidade.y *= -1;
            bola.velocidade.x = (bola.posicao.x - jogador.posicao.x)/(jogador.tamanho.x/2)*5;
        }
    }
}

void bateBlocos(){  // tentar mudar isso pra checkcollision depois pq TALVEZ fique mais facil

    for (int i = 0; i < BLOCOS_LINHA; i++){
                for (int j = 0; j < BLOCOS_COLUNA; j++){
                    if (bloco[i][j].ativo){ // se o bloco estiver ativo
                        // bateu embaixo
                        if (((bola.posicao.y - bola.raio) <= (bloco[i][j].posicao.y + tamBloco.y/2)) && // se a borda da bola "tocar" na borda do bloco
                            ((bola.posicao.y - bola.raio) > (bloco[i][j].posicao.y + tamBloco.y/2 + bola.velocidade.y)) &&
                            ((fabs(bola.posicao.x - bloco[i][j].posicao.x)) < (tamBloco.x/2 + bola.raio*2/3)) && (bola.velocidade.y < 0))
                        {
                            bloco[i][j].ativo = false; // desativa o bloco
                            bola.velocidade.y *= -1; // inverte a velocidade pra ir de volta
                        }
                        // bateu encima
                        else if (((bola.posicao.y + bola.raio) >= (bloco[i][j].posicao.y - tamBloco.y/2)) &&
                                ((bola.posicao.y + bola.raio) < (bloco[i][j].posicao.y - tamBloco.y/2 + bola.velocidade.y)) &&
                                ((fabs(bola.posicao.x - bloco[i][j].posicao.x)) < (tamBloco.x/2 + bola.raio*2/3)) && (bola.velocidade.y > 0))
                        {
                            bloco[i][j].ativo = false;
                            bola.velocidade.y *= -1;
                        }
                        // bateu na esquerda
                        else if (((bola.posicao.x + bola.raio) >= (bloco[i][j].posicao.x - tamBloco.x/2)) &&
                                ((bola.posicao.x + bola.raio) < (bloco[i][j].posicao.x - tamBloco.x/2 + bola.velocidade.x)) &&
                                ((fabs(bola.posicao.y - bloco[i][j].posicao.y)) < (tamBloco.y/2 + bola.raio*2/3)) && (bola.velocidade.x > 0))
                        {
                            bloco[i][j].ativo = false;
                            bola.velocidade.x *= -1;
                        }
                        // bateu na direita
                        else if (((bola.posicao.x - bola.raio) <= (bloco[i][j].posicao.x + tamBloco.x/2)) &&
                                ((bola.posicao.x - bola.raio) > (bloco[i][j].posicao.x + tamBloco.x/2 + bola.velocidade.x)) &&
                                ((fabs(bola.posicao.y - bloco[i][j].posicao.y)) < (tamBloco.y/2 + bola.raio*2/3)) && (bola.velocidade.x < 0))
                        {
                            bloco[i][j].ativo = false;
                            bola.velocidade.x *= -1;
                        }
                    }
                }
            }

}

void atualizaJogo(void){                                    // Atualiza a lógica do jogo

    if (IsKeyPressed('P')){
        pause = !pause;
    }

    if (!pause){

        mexeRaquete();
        lancaBola();
        mexeBola();
        bateParede();
        bateJogador();
        bateBlocos();
    }

}

void atualizaJogoDesenho(void){                             // Desenha o jogo com a lógica atualizada

    limpaTela();
    atualizaJogo();
    desenhaJogo();

}

#endif
