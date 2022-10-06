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

void initJogo(void);
char pegaMatrizBlocos (FILE *ARQUIVO);
void initBloco(int nivel);
void initBola(void);
void mexeRaquete(void);
void lancaBola(void);
void mexeBola(void);
void bateParede(void);
void bateJogador(void);
void bateBloco(void);
bool acabouBloco (void);
void atualizaJogo(void);
void atualizaJogoDesenho(void);

void desenhaJogo(void);
void limpaTela(void);

void initJogo(void){

    // Inicializa raquete
    jogador.posicao = (Vector2){TELA_LARGURA/2, TELA_ALTURA*7/8};
    jogador.tamanho = (Vector2){TELA_LARGURA/10, 20};
    jogador.vidas = MAX_VIDAS;
    jogador.pontos = 0;

    // Inicializa bola
    initBola();

    initBloco(0); // inicia com nivel 1
}

char pegaMatrizBlocos (FILE *ARQUIVO){

    char cor;

    do{
        cor = fgetc(ARQUIVO);

    }while(cor == ' ' || cor == '\n'); // Se for espaço ou \n vai dnv

    return cor;
}

void initBloco(int nivel){

    FILE *arq;

    switch(nivel){
        case 0: arq = fopen("nivel1.txt", "r");
                break;
        case 1: arq = fopen("nivel2.txt", "r");
                break;
        case 2: arq = fopen("nivel3.txt", "r");
                break;
    }

    int i, j, espaco, altura=0;
    char cor;

    for (i=0; i<B_LINHA; i++){
        espaco=0;

        for (j=0; j<B_COLUNA; j++){

            cor = pegaMatrizBlocos(arq);

            bloco[i][j].tamanho = (Vector2){65, 20};
            bloco[i][j].posicao = (Vector2){j*bloco[i][j].tamanho.x + 39 + espaco, i*bloco[i][j].tamanho.y + 35 + altura};

            switch (cor){
                case 'B': bloco[i][j].cor = BLUE;
                          bloco[i][j].ativo = true;
                          break;
                case 'G': bloco[i][j].cor = LIME;
                          bloco[i][j].ativo = true;
                          break;
                case 'R': bloco[i][j].cor = RED;
                          bloco[i][j].ativo = true;
                          break;
                case 'X': bloco[i][j].cor = MAGENTA;
                          bloco[i][j].ativo = true;
                          break;
                case 'Y': bloco[i][j].cor = YELLOW;
                          bloco[i][j].ativo = true;
                          break;
                case 'V': bloco[i][j].cor = GREEN;
                          bloco[i][j].especial = 1;
                          bloco[i][j].ativo = true;
                          break;
                case 'A': bloco[i][j].cor = SKYBLUE;
                          bloco[i][j].especial = 2;
                          bloco[i][j].ativo = true;
                          break;
                case 'M': bloco[i][j].cor = WHITE;
                          bloco[i][j].especial = 3;
                          bloco[i][j].ativo = true;
                          break;
                case '-': bloco[i][j].cor = BLANK;
                          bloco[i][j].ativo = false;
                          break;
            }

            espaco = espaco + 8; // espaço entre os blocos
        }
        altura = altura + 8; // altura entre os blocos
    }

    fclose(arq);

}

void initBola(void){

    bola.posicao = (Vector2) {TELA_LARGURA/2, TELA_ALTURA*2/3};
    bola.velocidade = (Vector2){0, 0};
    bola.raio = 7;
    bola.ativa = false;
    bola.cor = ORANGE;

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

    if (!bola.ativa){                                       // Se a bola não está ativa (começo do jogo)

        if (IsKeyPressed(KEY_SPACE)){                       // Se apertar no espaço, a bola fica ativa

            bola.ativa = true;
            bola.velocidade = (Vector2){0, -7};
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
        bola.raio = 7;

        jogador.vidas--;

        if(jogador.vidas == 0) {
            gameOver = true;
        }
    }
}

void bateJogador(void){                                         // Função para a lógica da bola rebater na raquete

    // NÃO DA PRA COLOCAR SÓ POS.X, POS.Y NO RECTANGLE PQ SE NÃO PEGA NO FIM DO RETANGULO
    // CheckCollisionCircleRec --> função que checa se teve colisão entre um circulo e um retangulo
    if (CheckCollisionCircleRec (bola.posicao, bola.raio, (Rectangle){jogador.posicao.x - 40,
                                                                      jogador.posicao.y - 10,
                                                                      jogador.tamanho.x, jogador.tamanho.y})){


        if (bola.velocidade.y > 0){
            bola.velocidade.y *= -1;
            bola.velocidade.x = (bola.posicao.x - jogador.posicao.x)/4;

        }
    }
}

void bateBloco(void){

    for (int i=0; i<B_LINHA; i++){
        for (int j=0; j<B_COLUNA; j++){
            if (bloco[i][j].ativo == true){         // Se o bloco estiver ativo
                if ((CheckCollisionCircleRec (bola.posicao, bola.raio,
                                            (Rectangle){bloco[i][j].posicao.x, bloco[i][j].posicao.y, bloco[i][j].tamanho.x,
                                            bloco[i][j].tamanho.y}))){

                    bloco[i][j].ativo = false;

                    switch (bloco[i][j].especial){
                        case 0: bola.velocidade.y *= -1;
                                jogador.pontos = jogador.pontos + 20;
                            break;
                        case 1: bola.velocidade.y *= -1.5;
                                jogador.pontos = jogador.pontos + 20;
                            break;
                        case 2: bola.velocidade.y *= -1;
                                jogador.pontos = jogador.pontos + 20;
                                bola.raio *= 2;
                            break;
                        case 3: bola.velocidade.y *= -1;
                                jogador.pontos = jogador.pontos + 40;
                            break;
                    }
                }
            }
        }
    }
}

bool acabouBloco (void){

    bool proxNivel;

    for (int i=0; i<B_LINHA; i++){
        for (int j=0; j<B_COLUNA; j++){
            if (bloco[i][j].ativo == true){

                proxNivel = false;
                return proxNivel;
            }
        }
   }

    proxNivel = true;
    return proxNivel;
}

void atualizaJogo(void){                             // Atualiza a lógica do jogo

    if (IsKeyPressed('P')){
        pause = !pause;
    }

    if (!pause){

        mexeRaquete();
        lancaBola();
        mexeBola();
        bateParede();
        bateJogador();
        bateBloco(/*bloco*/);
    }

}

void atualizaJogoDesenho(void){                     // Desenha o jogo com a lógica atualizada

    limpaTela();
    atualizaJogo();
    desenhaJogo();

}

#endif
