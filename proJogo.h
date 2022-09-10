// Defini��o:

#ifndef proJogo_h
#define proJogo_h

/* Essa biblioteca vai ser usada para definir todas as fun��es necess�rias para a cria��o da l�gica do jogo, utilizando
as fun��es predefinidas da biblioteca Raylib */

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
    int i, j, espaco, altura=0;


    for (i=0; i<B_LINHA; i++){
        espaco=0;

        for (j=0; j<B_COLUNA; j++){
            bloco[i][j].tamanho = (Vector2){65, 20};
            bloco[i][j].posicao = (Vector2){j*bloco[i][j].tamanho.x + 39 + espaco, i*bloco[i][j].tamanho.y + 35 + altura};
            bloco[i][j].ativo = true;

            espaco = espaco + 8; // espa�o entre os blocos
        }
        altura = altura + 8; // altura entre os blocos
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

void mexeRaquete(void){                                     // Fun��o da l�gica do movimento da raquete

    if (IsKeyDown(KEY_LEFT)){
        jogador.posicao.x -= 5;                             // diminui pos_x em 5 VAI PRA ESQUERDA
    }
    if ((jogador.posicao.x - jogador.tamanho.x/2) <= 0){    //se chegou na borda da esquerda,
        jogador.posicao.x = jogador.tamanho.x/2;            // n�o deixa ir mais pra esquerda
    }
    if (IsKeyDown(KEY_RIGHT)){
        jogador.posicao.x += 5;                             // aumenta pos_x em 5 VAI PRA DIREITA
    }
    if ((jogador.posicao.x + jogador.tamanho.x/2) >= TELA_LARGURA){     //se chegou na borda da direita
        jogador.posicao.x = TELA_LARGURA - jogador.tamanho.x/2;         // nao deixa ir pra direita
    }
}

void lancaBola(void){                                       // Fun��o para a l�gica do lan�amento da bola
    int random = (- 2 + (rand() % (2 + 2 + 1)));

    if (!bola.ativa){                                       // Se a bola n�o est� ativa (come�o do jogo)

        if (IsKeyPressed(KEY_SPACE)){                       // Se apertar no espa�o, a bola fica ativa

            bola.ativa = true;
            bola.velocidade = (Vector2){random, -7};
        }
     }
}

void mexeBola(void){                                        // Fun��o para a l�gica do movimento da bola

    if (bola.ativa){                        // Se a bola est� ativa, se mexe pras dire��es de acordo com a velocidade da bola

        bola.posicao.x += bola.velocidade.x;
        bola.posicao.y += bola.velocidade.y;
    }

    else{
        bola.posicao = (Vector2){jogador.posicao.x, TELA_ALTURA*7/8 - 30 }; // Se n�o est� ativa, fica parada no lugar original
    }
}

void bateParede(void){                                      // Fun��o para a l�gica da bola rebater nas paredes

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

void bateJogador(void){                                         // Fun��o para a l�gica da bola rebater na raquete

    // CheckCollisionCircleRec --> fun��o que checa se teve colis�o entre um circulo e um retangulo
    if (CheckCollisionCircleRec (bola.posicao, bola.raio, (Rectangle){jogador.posicao.x - jogador.tamanho.x/2,
                                                           jogador.posicao.y - jogador.tamanho.y/2, jogador.tamanho.x,
                                                           jogador.tamanho.y})){

        if (bola.velocidade.y > 0){
            bola.velocidade.y *= -1;
            bola.velocidade.x = (bola.posicao.x - jogador.posicao.x)/(jogador.tamanho.x/2)*5;
        }
    }
}

void bateBloco(void){

    int i, j;
    for (i=0; i<B_LINHA; i++){
        for (j=0; j<B_COLUNA; j++){
            if (bloco[i][j].ativo == true){ // Se o bloco estiver ativo

                /* Se a bolinha bater por baixo, esse if � basicamente: se a borda da bola tocar na borda de baixo do
                bloco e se a bola n�o estiver parada */
                if(((bola.posicao.y - bola.raio) <= (bloco[i][j].posicao.y + bloco[i][j].tamanho.y/2)) &&
                  ((bola.posicao.y - bola.raio) > (bloco[i][j].posicao.y + bloco[i][j].tamanho.y/2 + bola.velocidade.y)) &&
                  ((fabs(bola.posicao.x - bloco[i][j].posicao.x)) < (bloco[i][j].tamanho.x/2 + bola.raio*2/3))
                  && (bola.velocidade.y < 0)){

                    bloco[i][j].ativo = false;
                    bola.velocidade.y *= -1;
                    //switch da cor pra ver se d� powerup ou n�o

                    jogador.pontos = jogador.pontos + 20;
                }

                /* Mesma coisa do anterior, s� muda que � a borda de cima do bloco */
                else if (((bola.posicao.y - bola.raio) >= (bloco[i][j].posicao.y + bloco[i][j].tamanho.y/2)) &&
                  ((bola.posicao.y - bola.raio) < (bloco[i][j].posicao.y + bloco[i][j].tamanho.y/2 + bola.velocidade.y)) &&
                  ((fabs(bola.posicao.x - bloco[i][j].posicao.x)) < (bloco[i][j].tamanho.x/2 + bola.raio*2/3))
                  && (bola.velocidade.y < 0)){

                    bloco[i][j].ativo = false;
                    bola.velocidade.y *= -1;
                    //switch da cor pra ver se d� powerup ou n�o

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
                    //switch da cor pra ver se d� powerup ou n�o

                    jogador.pontos = jogador.pontos + 20;
                }

                /* Mesma coisa do anterior, s� muda que � a borda do lado direito do bloco */
                else if (((bola.posicao.x - bola.raio) <= (bloco[i][j].posicao.x + bloco[i][j].tamanho.x/2)) &&
                  ((bola.posicao.x - bola.raio) > (bloco[i][j].posicao.x + bloco[i][j].tamanho.x/2 + bola.velocidade.x)) &&
                  ((fabs(bola.posicao.y - bloco[i][j].posicao.y)) < (bloco[i][j].tamanho.y/2 + bola.raio*2/3))
                  && (bola.velocidade.x < 0)){

                    bloco[i][j].ativo = false;
                    bola.velocidade.y *= -1;
                    //switch da cor pra ver se d� powerup ou n�o

                    jogador.pontos = jogador.pontos + 20;
                }
            }
        }
    }
}

void bateBlocoCol(void){ // Rebate bolinha mas usando o CheckCollisionCircleRec, n�o ta funcionando muito bem

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
                //switch da cor pra ver se d� powerup ou n�o
                }
            }
        }
    }
}

void atualizaJogo(void){                                    // Atualiza a l�gica do jogo

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
        bateBloco();
    }

}

void atualizaJogoDesenho(void){                             // Desenha o jogo com a l�gica atualizada

    limpaTela();
    atualizaJogo();
    desenhaJogo();

}

#endif
