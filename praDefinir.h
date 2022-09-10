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
#define MAX_VIDAS 1

// Definição de variáveis pros blocos:
#define BLOCOS_LINHA 5
#define BLOCOS_COLUNA 10
#define BLOCOS_INICIAL 50


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


// Definições de structs para a proJogo.h

    typedef struct Jogador{
        Vector2 posicao;
        Vector2 tamanho;
        int vidas;
        int pontos;
    } Jogador;

    Jogador jogador;

    typedef struct Bola {
        Vector2 posicao;
        Vector2 velocidade;
        int raio;
        bool ativa;
        Color cor;
    } Bola;

    Bola bola;

    typedef struct Bloco {
        Vector2 posicao;
        bool ativo;
    } Bloco;

    Bloco bloco [BLOCOS_LINHA][BLOCOS_COLUNA] = {0};

    Vector2 tamBloco = {0}; // tentei usar isso dentro da struct mas não tava funcionando

// Definição de variáveis para a proPause.h

    bool pause = false;
    bool gameOver= false;

#endif
