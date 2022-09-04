// Defini��o:

#ifndef proJogo_h
#define proJogo_h

/* Essa biblioteca vai ser usada para definir todas as fun��es necess�rias para a cria��o da l�gica do jogo, utilizando
as fun��es predefinidas da biblioteca Raylib */

// Bibliotecas utilizadas:
#include "raylib.h"
#include <stdio.h>

#include "proDesenho.h"
#include "proMenu.h"
#include "praDefinir.h"
#include "proHighscore.h"
#include "proPause.h"

/*void atualizaBolinha(){
    DrawCircle(390, 350, 25, ORANGE);
}

void atualizaBlocos(){
}

void atualizaRaquete(){
}

void atualizaVidas(){
}*/


void initJogo(void){

    // Inicializa jogador
    jogador.posicao = (Vector2){TELA_LARGURA/2, TELA_ALTURA*7/8};
    jogador.tamanho = (Vector2){TELA_LARGURA/10, 20};
    jogador.vidas = MAX_VIDAS;
    jogador.pontos = 0;

    // Inicializa bola
    bola.posicao = (Vector2) {TELA_LARGURA/2, TELA_ALTURA*7/8 - 30};
    bola.velocidade = (Vector2){0, 0};
    bola.raio = 7;
    bola.ativa = false;

}

void mexeRaquete(void){ // Fun��o da l�gica do movimento da raquete

    if (IsKeyDown(KEY_LEFT)){
        jogador.posicao.x -= 5; // diminui pos_x em 5 VAI PRA ESQUERDA
    }
    if ((jogador.posicao.x - jogador.tamanho.x/2) <= 0){ //se chegou na borda da esquerda,
        jogador.posicao.x = jogador.tamanho.x/2; // n�o deixa ir mais pra esquerda
    }
    if (IsKeyDown(KEY_RIGHT)){
        jogador.posicao.x += 5; // aumenta pos_x em 5 VAI PRA DIREITA
    }
    if ((jogador.posicao.x + jogador.tamanho.x/2) >= TELA_LARGURA){ //se chegou na borda da direita
        jogador.posicao.x = TELA_LARGURA - jogador.tamanho.x/2; // nao deixa ir pra direita
    }
}

void lancaBola(void){ // Fun��o para a l�gica do lan�amento da bola

    if (!bola.ativa){ // Se a bola n�o est� ativa (come�o do jogo)

        if (IsKeyPressed(KEY_SPACE)){ // Se apertar no espa�o, a bola fica ativa

            bola.ativa = true;
            bola.velocidade = (Vector2){0, -5};
        }
     }
}

void mexeBola(void){ // Fun��o para a l�gica do movimento da bola

    if (bola.ativa){ // Se a bola est� ativa, se mexe pras dire��es de acordo com a velocidade da bola

        bola.posicao.x += bola.velocidade.x;
        bola.posicao.y += bola.velocidade.y;
    }

    else{
        bola.posicao = (Vector2){jogador.posicao.x, TELA_ALTURA*7/8 - 30 }; // Se n�o est� ativa, fica parada no lugar original
    }
}

void bateParede(void){ // Fun��o para a l�gica da bola rebater nas paredes

    if (((bola.posicao.x + bola.raio) >= TELA_LARGURA) || ((bola.posicao.x - bola.raio) <= 0)){
        bola.velocidade.x *= -1;
    }

    if ((bola.posicao.y - bola.raio) <= 0){
        bola.velocidade.y *= -1;
    }

    if ((bola.posicao.y + bola.raio) >= TELA_ALTURA){ // Se passar da parte de baixo da tela, desativa a bola

        bola.velocidade = (Vector2){0, 0};
        bola.ativa = false;

        jogador.vidas--;
    }
}

void bateJogador(){ // Fun��o para a l�gica da bola rebater na raquete

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

void atualizaJogo(void){ // Atualiza a l�gica do jogo

    if (IsKeyPressed('P')){
        pause = !pause;
    }

    if (!pause){

        mexeRaquete();
        lancaBola();
        mexeBola();
        bateParede();
        bateJogador();
    }

}

void atualizaJogoDesenho(void){ // Desenha o jogo com a l�gica atualizada

    atualizaJogo();
    desenhaJogo();
}

#endif
