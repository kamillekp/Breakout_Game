/* BreakoutINF - Beatriz Aline Arend e Kamille Konarzewski Pimentel, 2022/01
tudo.h é uma biblioteca criada para armazenar todas as structs, funções e variáveis necessárias do programa.
*/

#define TUDO_H

#include <raylib.h>

// TELA INICIAL:
#define TELA_NOME "BreakoutINF - Beatriz e Kamille"

#define TELA_ALTURA 450
#define TELA_LARGURA 800

// JOGO?
#define MAX_VIDAS 3

//MATRIZ : arquivo txts --- pegar o .txt aqui, e referenciar depois lá no jogo, e não deixar pra pegar ele lá (pelo menos 2)

// TELAS?
typedef enum{

    INIT_Tela, // 0
    MENU_Tela, // 2
    JOGO_Tela, // 3
    PTOS_Tela, // 4
    SAIR_Tela, // 5

} Telas;

typedef struct{

    char Nome[255];
    int Altura;
    int Largura;

}InitTelaInfo;

typedef struct Jogador{

    char *Nome;
    int Pontos;
    int Vidas;
    bool Estado; // se tá vivo ou morto

}Jogador;

typedef struct Bola{

    int PosX;
    int PosY;
    int Raio;

}Bola;

typedef struct Raquete{

    int Altura;
    int Largura;
    int PosX;
    int PosY;

}Raquete;

//SHAPES

//MENU
Rectangle botao1 = {240, 150, 325, 50};
Rectangle botao2 = {240, 225, 325, 50};
Rectangle botao3 = {240, 300, 325, 50};

//PONTUACAO
Rectangle pos1 = {100, 130, 45, 45};
Rectangle pos2 = {100, 190, 45, 45};
Rectangle pos3 = {100, 250, 45, 45};
Rectangle pos4 = {100, 310, 45, 45};
Rectangle pos5 = {100, 370, 45, 45};

Rectangle volta1 = {15, 15, 45, 45};


