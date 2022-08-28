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

typedef struct Player{

    Vector2 Posicao;
    Vector2 Tamanho;
    char *Nome;
    int Pontos;
    int Vidas;

}Player;

Player Jogador;

typedef struct Ball{

    Vector2 Posicao;
    Vector2 Velocidade;
    int Raio;
    bool Ativa;

}Ball;

Ball Bola;

//SHAPES

//MENU
Rectangle rec1 = { 240, 150, 325, 50 };
Rectangle rec2 = { 240, 225, 325, 50 };
Rectangle rec3 = { 240, 300, 325, 50 };

//PONTUACAO
Rectangle pos1 = {100, 130, 45, 45};
Rectangle pos2 = {100, 190, 45, 45};
Rectangle pos3 = {100, 250, 45, 45};
Rectangle pos4 = {100, 310, 45, 45};
Rectangle pos5 = {100, 370, 45, 45};

Rectangle volta1 = {15, 15, 45, 45};

