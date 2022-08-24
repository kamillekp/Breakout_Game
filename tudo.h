/* BreakoutINF - Beatriz Aline Arend e Kamille Konarzewski Pimentel, 2022/01
tudo.h � uma biblioteca criada para armazenar todas as structs, fun��es e vari�veis necess�rias do programa.
*/

#define TUDO_H

#include <raylib.h>

// TELA INICIAL:
#define TELA_NOME "BreakoutINF - Beatriz e Kamille"

#define TELA_ALTURA 450
#define TELA_LARGURA 800

// JOGO?
#define MAX_VIDAS 3

//MATRIZ : arquivo txts --- pegar o .txt aqui, e referenciar depois l� no jogo, e n�o deixar pra pegar ele l� (pelo menos 2)

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
    bool Estado; // se t� vivo ou morto

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

