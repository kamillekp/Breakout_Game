// Definição:

#ifndef praDefinir_h
#define praDefinir_h

/* Essa biblioteca vai ser usada para definir todas as variáveis necessárias para o programa */

// Bibliotecas utilizadas:
#include "raylib.h"
#include <stdio.h>

#include "proDesenho.h"
#include "proJogo.h"
#include "proMenu.h"
#include "proHighscore.h"
#include "proPause.h"

// Definição de variáveis da tela inicial:

#define TELA_NOME "BreakoutINF - Beatriz e Kamille"
#define TELA_ALTURA 450
#define TELA_LARGURA 800
#define MAX_VIDAS 10

// Definição de variáveis pros blocos:
#define B_LINHA 5
#define B_COLUNA 10
#define B_ESPACO 5

// Definição de variáveis para main

    bool pause = false;
    bool gameOver = false;
    bool proxNivel = false;


// Definição de variáveis para a proMenu.h
    int op = 0;
    int *ptr_op = &op;

// Definição de shapes para a proDesenho.h

    // Botões para o Menu:
    Rectangle botao1 = {240, 150, 325, 50};
    Rectangle botao2 = {240, 225, 325, 50};
    Rectangle botao3 = {240, 300, 325, 50};

    // Quadrados para o menu Pontuação:
    Rectangle pos1 = {100, 130, 45, 45};
    Rectangle pos2 = {100, 190, 45, 45};
    Rectangle pos3 = {100, 250, 45, 45};
    Rectangle pos4 = {100, 310, 45, 45};
    Rectangle pos5 = {100, 370, 45, 45};

    Rectangle volta1 = {15, 15, 45, 45};

    // Retangulos do menu Pause:
    Rectangle rec1 = {240, 100, 300, 240};

    Rectangle con1 = {270, 130, 45, 45};
    Rectangle con2 = {270, 195, 45, 45};
    Rectangle con3 = {270, 260, 45, 45};

    // Retangulos para o menu Nome:
    Rectangle nom1 = {190, 190, 440, 100};

    // Retangulos para Continuar:
    Rectangle prox = {530, 390, 45, 45};

// Definições de structs para a proJogo.h

    typedef struct Jogador{
        Vector2 posicao;
        Vector2 tamanho;
        int vidas;
        int pontos;
    } Jogador;

    Jogador jogador;

    typedef struct Bola{
        Vector2 posicao;
        Vector2 velocidade;
        int raio;
        bool ativa;
        Color cor;
    } Bola;

    Bola bola;

    typedef struct Bloco{
        Vector2 posicao;
        Vector2 tamanho;
        bool ativo;
        Color cor;
        int especial;
    } Bloco;

    Bloco bloco[B_LINHA][B_COLUNA];

// Definições de structs para a proHighscore.h

#endif
