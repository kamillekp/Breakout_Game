
#ifndef proHighscore_h
#define proHighscore_h

//BIBLIOTECAS:

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#include "proDesenho.h"
#include "proJogo.h"
#include "proMenu.h"
#include "praDefinir.h"
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

#endif
