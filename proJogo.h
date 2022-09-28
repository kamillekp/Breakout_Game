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
    initBola();

    initBloco(0);
}

void initBloco(int nivel){

    char bloco_cores[B_LINHA][B_COLUNA];

    pegaMatrizBlocos(bloco_cores, nivel);

    int i, j, espaco, altura=0;

    for (i=0; i<B_LINHA; i++){
        espaco=0;

        for (j=0; j<B_COLUNA; j++){
            bloco[i][j].tamanho = (Vector2){65, 20};
            bloco[i][j].posicao = (Vector2){j*bloco[i][j].tamanho.x + 39 + espaco, i*bloco[i][j].tamanho.y + 35 + altura};
            switch (bloco_cores[i][j]){
                case 'B': bloco[i][j].cor = BLUE;
                          bloco[i][j].ativo = true;
                          break;
                case 'G': bloco[i][j].cor = LIME;
                          bloco[i][j].ativo = true;
                          break;
                case 'R': bloco[i][j].cor = RED;
                          bloco[i][j].ativo = true;
                          break;
                case 'P': bloco[i][j].cor = MAGENTA;
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
                case '-': bloco[i][j].ativo = false;
                          break;
            }

            espaco = espaco + 8; // espaço entre os blocos
        }
        altura = altura + 8; // altura entre os blocos
    }
}

void initBola(void){

    bola.posicao = (Vector2) {TELA_LARGURA/2, TELA_ALTURA*2/3};
    bola.velocidade = (Vector2){0, 0};
    bola.raio = 7;
    bola.ativa = false;
    bola.cor = ORANGE;

}
void pegaMatrizBlocos (char blocos[5][10], int nivel){
    FILE *ptrBlocos;
    int i = 0, j = 0;

    char nomeArq[30];

    switch(nivel){
        case 0: strcpy(nomeArq,"nivel1.txt");
                break;
        case 1: strcpy(nomeArq,"nivel2.txt");
                break;
        case 2: strcpy(nomeArq,"nivel3.txt");
                break;
    }

    ptrBlocos = fopen(nomeArq, "r");                   // abre o arquivo para leitura
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
    //int random = (- 2 + (rand() % (2 + 2 + 1)));

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

        if(jogador.vidas == 0 /*|| blocos == 0*/) {
            gameOver = true;
        }
    }
}

void bateJogador(void){                                         // Função para a lógica da bola rebater na raquete

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

void bateBloco3(void){

    int i, j;
    for (i=0; i<B_LINHA; i++){
        for (j=0; j<B_COLUNA; j++){
            if (bloco[i][j].ativo == true){ // Se o bloco estiver ativo

                /* Se a bolinha bater por baixo, esse if é basicamente: se a borda da bola tocar na borda de baixo do
                bloco e se a bola não estiver parada */
                if(((bola.posicao.y - bola.raio) <= (bloco[i][j].posicao.y + bloco[i][j].tamanho.y/2)) &&
                  ((bola.posicao.y - bola.raio) > (bloco[i][j].posicao.y + bloco[i][j].tamanho.y/2 + bola.velocidade.y)) &&
                  ((fabs(bola.posicao.x - bloco[i][j].posicao.x)) < (bloco[i][j].tamanho.x/2 + bola.raio*2/3))
                  && (bola.velocidade.y < 0)){

                    bloco[i][j].ativo = false;
                    bola.velocidade.y *= -1;
                    //switch da cor pra ver se dá powerup ou não

                    jogador.pontos = jogador.pontos + 20;
                }

                /* Mesma coisa do anterior, só muda que é a borda de cima do bloco */
                else if (((bola.posicao.y - bola.raio) >= (bloco[i][j].posicao.y + bloco[i][j].tamanho.y/2)) &&
                  ((bola.posicao.y - bola.raio) < (bloco[i][j].posicao.y + bloco[i][j].tamanho.y/2 + bola.velocidade.y)) &&
                  ((fabs(bola.posicao.x - bloco[i][j].posicao.x)) < (bloco[i][j].tamanho.x/2 + bola.raio*2/3))
                  && (bola.velocidade.y < 0)){

                    bloco[i][j].ativo = false;
                    bola.velocidade.y *= -1;
                    //switch da cor pra ver se dá powerup ou não

                    jogador.pontos = jogador.pontos + 20;
                }

                /* Quase a mesma coisa dos anteriores, mas inverte os y por x das duas primeiras linhas, pra fazer:
                "Se a borda da bola tocar na borda do lado esquerdo do bloco"*/
                else if (((bola.posicao.x - bola.raio) >= (bloco[i][j].posicao.x + bloco[i][j].tamanho.x/2)) &&
                  ((bola.posicao.x - bola.raio) < (bloco[i][j].posicao.x + bloco[i][j].tamanho.x/2 + bola.velocidade.x)) &&
                  ((fabs(bola.posicao.y - bloco[i][j].posicao.y)) < (bloco[i][j].tamanho.y/2 + bola.raio*2/3))
                  && (bola.velocidade.x < 0)){

                    bloco[i][j].ativo = false;
                    bola.velocidade.y *= -1;
                    //switch da cor pra ver se dá powerup ou não

                    jogador.pontos = jogador.pontos + 20;
                }

                /* Mesma coisa do anterior, só muda que é a borda do lado direito do bloco */
                else if (((bola.posicao.x - bola.raio) <= (bloco[i][j].posicao.x + bloco[i][j].tamanho.x/2)) &&
                  ((bola.posicao.x - bola.raio) > (bloco[i][j].posicao.x + bloco[i][j].tamanho.x/2 + bola.velocidade.x)) &&
                  ((fabs(bola.posicao.y - bloco[i][j].posicao.y)) < (bloco[i][j].tamanho.y/2 + bola.raio*2/3))
                  && (bola.velocidade.x < 0)){

                    bloco[i][j].ativo = false;
                    bola.velocidade.y *= -1;
                    //switch da cor pra ver se dá powerup ou não

                    jogador.pontos = jogador.pontos + 20;
                }
            }
        }
    }
}

void bateBlocoCol(void){ // Rebate bolinha mas usando o CheckCollisionCircleRec, não ta funcionando muito bem

    int i, j;
    for (i=0; i<B_LINHA; i++){
        for (j=0; j<B_COLUNA; j++){
            if (bloco[i][j].ativo == true){ // Se o bloco estiver ativo
                if ((CheckCollisionCircleRec (bola.posicao, bola.raio,
                                            (Rectangle){bloco[i][j].posicao.x - bloco[i][j].tamanho.x/2,
                                            bloco[i][j].posicao.y - bloco[i][j].tamanho.y/2, bloco[i][j].tamanho.x,
                                            bloco[i][j].tamanho.y})) && (bola.velocidade.x < 0)){

                bloco[i][j].ativo = false;
                bola.velocidade.y *= -1;
                }
            }
        }
    }
}

void bateBloco2(void){

    for (int i=0; i<B_LINHA; i++){
        for (int j=0; j<B_COLUNA; j++){
            if (bloco[i][j].ativo == true){
                if (bola.posicao.x >= bloco[i][j].posicao.x && bola.posicao.x <= bloco[i][j].posicao.x + bloco[i][j].tamanho.x){
                    if (bola.posicao.y - bola.raio <= bloco[i][j].posicao.y + bloco[i][j].tamanho.y && bola.posicao.y + bola.raio >= bloco[i][j].tamanho.y /*&& bola.velocidade.x < 0*/){

                        bloco[i][j].ativo = false;
                        bola.velocidade.y *= -1;
                        jogador.pontos = jogador.pontos + 20;
                    }

                }
                if (bola.posicao.y >= bloco[i][j].posicao.y && bola.posicao.y <= bloco[i][j].posicao.y + bloco[i][j].tamanho.y){
                    if (bola.posicao.x - bola.raio <= bloco[i][j].posicao.x + bloco[i][j].tamanho.x && bola.posicao.x + bola.raio >= bloco[i][j].tamanho.x /*&& bola.velocidade.y < 0*/){

                        bloco[i][j].ativo = false;
                        bola.velocidade.y *= -1;
                        jogador.pontos = jogador.pontos + 20;
                    }
                }
            }
        }
    }
}

void bateBloco(/*Bloco bloco[][B_COLUNA]*/){

    for (int i=0; i<B_LINHA; i++){
        for (int j=0; j<B_COLUNA; j++){
            if (bloco[i][j].ativo == true){ // Se o bloco estiver ativo
                if ((CheckCollisionCircleRec (bola.posicao, bola.raio,
                                            (Rectangle){bloco[i][j].posicao.x, bloco[i][j].posicao.y, bloco[i][j].tamanho.x,
                                            bloco[i][j].tamanho.y})) /*&& (bola.velocidade.x < 0)*/){

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


void atualizaJogo(){                                    // Atualiza a lógica do jogo

    if (IsKeyPressed('P')){
        pause = !pause;
    }

    if (!pause){

        mexeRaquete();
        lancaBola();
        mexeBola();
        bateParede();
        bateJogador();
        //bateBlocoCol();
        //bateBloco3();
        //bateBloco2();
        bateBloco(/*bloco*/);
    }

}

void atualizaJogoDesenho(){                             // Desenha o jogo com a lógica atualizada

    limpaTela();
    atualizaJogo();
    desenhaJogo();

}

#endif
