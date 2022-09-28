// Definição:

#ifndef proHighscore_h
#define proHighscore_h

/* Essa biblioteca vai ser usada para definir todas as funções necessárias para a criação da lógica do highscore, utilizando
as funções predefinidas da biblioteca Raylib */

// Bibliotecas utilizadas:
#include "raylib.h"
#include <stdio.h>

#include "proDesenho.h"
#include "proJogo.h"
#include "praDefinir.h"
#include "proMenu.h"
#include "proPause.h"
#include "proPause.h"

typedef struct {
    char nome[30];
    char pontos[5];
} BESTPLAYERS;


void criaJogadores(){
    BESTPLAYERS bp[5];
    FILE *ptArq;

    // Jogador 1
    strcpy(bp[0].nome, "Rodrigo");
    strcpy(bp[0].pontos, "300");

    // Jogador 2
    strcpy(bp[1].nome, "Micheli");
    strcpy(bp[1].pontos, "268");

    // Jogador 3
    strcpy(bp[2].nome, "Augusto");
    strcpy(bp[2].pontos, "232");

    // Jogador 4
    strcpy(bp[3].nome, "Joana");
    strcpy(bp[3].pontos, "143");

    // Jogador 5
    strcpy(bp[4].nome, "Alan");
    strcpy(bp[4].pontos, "127");

    ptArq = fopen("highscore.bin", "wb");

    if(!ptArq){
        printf("\nErro ao abrir arquivo.");
    }
    else{
        for (int i=0; i<5; i++){
            if(fwrite (&bp[i], sizeof(BESTPLAYERS), 1 , ptArq) != 1){
                printf("\nErro ao gravar arquivo.");
            }
        }
        fclose(ptArq);
    }
}


// PEGA ARQUIVO E PASSA PONTOS PARA INTEIRO
int pegaArquivo(void){

    FILE *ptArq;
    BESTPLAYERS bp[5];
    int pontuacaoInt[5];
    int i;

    //abrindo o arquivo_frase somente para leitura
    ptArq = fopen("highscore.bin", "rb");

    if(!ptArq){
        printf("\nErro ao abrir o arquivo.");
    }
    else{
        if(fread(&bp, sizeof(BESTPLAYERS), 5, ptArq) != 5){
            printf("\nErro ao ler arquivo. PA");
        }
        fclose(ptArq);
    }

    for(i=0; i<5; i++){
        pontuacaoInt[i] = atoi(bp[i].pontos);
    }

    return defineMaior(pontuacaoInt);
}

// PRECISA ACHAR UM JEITO DE PEGAR PONTOS DO JOGADOR
int defineMaior (int vet[]) {
    int posPontos = -1;
    int pontos = 215;

    if(/*jogador.*/pontos > vet[0]){
        posPontos = 0;
    }

    else if(/*jogador.*/pontos > vet[1]){
        posPontos = 1;
    }

    else if(/*jogador.*/pontos > vet[2]){
        posPontos = 2;
    }

    else if(/*jogador.*/pontos > vet[3]){
        posPontos = 3;
    }

    else if(/*jogador.*/pontos > vet[4]){
        posPontos = 4;
    }

    return posPontos;
}

void gravaArquivo(int lugar/*, JOGADOR *j*/){
    char nome[30];
    int pontos[5];

    strcpy(nome, "Fábio");
    strcpy(pontos, "215");

    BESTPLAYERS bp[5];
    FILE *ptArq;
    int i;

    //abrindo o arquivo somente para leitura
    ptArq = fopen("highscore.bin", "rb");

    if(!ptArq){
        printf("\nErro ao abrir o arquivo.");
    }
    else{
        while(!feof(ptArq)){
            if(fread (&bp, sizeof(BESTPLAYERS), 5, ptArq) != 5){
                 printf("\nErro ao ler arquivo. GA");
            }
        }
        fclose(ptArq);
    }

    // ALTERANDO ORDEM
    switch(lugar){
        case 0: for(i=4; i<0; i--){
                    strcpy(bp[i].nome, bp[i-1].nome);
                    strcpy(bp[i].pontos, bp[i-1].pontos);
                }

                printf("\nEntrou 0 switch");

                strcpy(bp[0].nome, nome);
                strcpy(bp[0].pontos, pontos);
            break;
        case 1: for(i=4; i<1; i--){
                    strcpy(bp[i].nome, bp[i-1].nome);
                    strcpy(bp[i].pontos, bp[i-1].pontos);
                }

                printf("\nEntrou 1 switch");

                strcpy(bp[1].nome, nome);
                strcpy(bp[1].pontos, pontos);
            break;
        case 2: for(i=4; i<2; i--){
                    strcpy(bp[i].nome, bp[i-1].nome);
                    strcpy(bp[i].pontos, bp[i-1].pontos);
                }

                printf("\nEntrou 2 switch");

                strcpy(bp[2].nome, nome);
                strcpy(bp[2].pontos, pontos);
            break;
        case 3: for(i=4; i<3; i--){
                    strcpy(bp[i].nome, bp[i-1].nome);
                    strcpy(bp[i].pontos, bp[i-1].pontos);
                }

                printf("\nEntrou 3 switch");

                strcpy(bp[3].nome, nome);
                strcpy(bp[3].pontos, pontos);
            break;
        case 4: strcpy(bp[4].nome, nome);
                strcpy(bp[4].pontos, pontos);

                printf("\nEntrou 4 switch");
            break;
    }

    ptArq = fopen("highscore.bin", "wb");

    if(!ptArq){
        printf("\nErro ao abrir o arquivo.");
    }
    else{
        if(fwrite(&bp, sizeof(BESTPLAYERS), 5, ptArq) != 5){
            printf("\nErro ao gravar arquivo.");
        }
    }

    fclose(ptArq);
}

/*

typedef struct {
    char nome[30];
    char pontos[5];
} BESTPLAYERS;

// BEATRIZ

    typedef struct Melhor{
        char nome[30];
        int pontos;
    }MELHOR;

    MELHOR melhores[5];

void ficticiaLista (MELHOR melhores[]){ // Cria uma lista fictícia de jogadores

    char nome1[30]="Beatriz";
    char nome2[30]="Igor";
    char nome3[30]="Kamille";
    char nome4[30]="Alguém";
    char nome5[30]="Ninguém";

    strcpy(melhores[0].nome,nome1);
    strcpy(melhores[0].nome,nome2);
    strcpy(melhores[0].nome,nome3);
    strcpy(melhores[0].nome,nome4);
    strcpy(melhores[0].nome,nome5);

    for (int i=0; i<5; i++){
        melhores[i].pontos = i*150;
    }
}

void ordenaLista(MELHOR melhores[]){

    int ranking = 5;

    for(int i=0; i<(ranking-1); i++){
        for(int j=0; j<(ranking-1-i); j++){
            if (melhores[j+1].pontos > melhores[j].pontos){
                trocaLista(&melhores[j+1], &melhores[j]);
            }
        }
    }
}

void trocaLista (MELHOR jog1, MELHOR jog2){ // Coloca o Jogador1 no lugar do Jogador2 e vice versa.

    MELHOR temp = jog2;
    jog2=jog1;
    jog1=temp;

}

void insereLista (MELHOR jog, int pts, char nome[30]){ // Insere um jogador na lista :: recebe um MELHOR, jogador.pontos e jogador.nome

    FILE *arq;
    MELHOR inserido;
    MELHOR jogadores[5];

    strcpy(inserido.nome, nome);
    inserido.pontos = pts;

    arq = fopen("highscore.bin", "rb");
    fread(&jogadores, sizeof(MELHOR), 5, arq); // Lê os jogadores do top 5
    fclose(arq);

    jogadores[4] = inserido; // Troca o último jogador da lista pelo jogador a ser inserido
    fazLista(jogadores, arq);

}

void fazLista(MELHOR jogadores[5], FILE *arq){

    ordenaLista(jogadores);
    arq = fopen("highscore.bin", "wb");
    fwrite(jogadores, sizeof(MELHOR), 5, arq);
    fclose(arq);

}
*/

#endif
