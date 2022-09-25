
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
    int pontos;
} BESTPLAYERS;


void criaJogadores(){
    BESTPLAYERS bp[5];
    FILE *ptArq;
    int i;

    // Jogador 1
    strcpy(bp[0].nome, "Rodrigo");
    bp[0].pontos = 300;

    // Jogador 2
    strcpy(bp[1].nome, "Micheli");
    bp[1].pontos = 268;

    // Jogador 3
    strcpy(bp[2].nome, "Augusto");
    bp[2].pontos = 232;

    // Jogador 4
    strcpy(bp[3].nome, "Joana");
    bp[3].pontos = 143;

    // Jogador 5
    strcpy(bp[4].nome, "Alan");
    bp[4].pontos = 97;


    ptArq = fopen("highscore.bin", "wb");

    if(!ptArq){
        printf("\nErro ao abrir arquivo.");
    }
    else{
        for(i=0; i<5; i++){
            if(fwrite (&bp[i], sizeof(BESTPLAYERS), 1, ptArq) != 1){
                printf("\nErro na escrita.");
            }
        }

        fclose(ptArq);
    }
}


// PEGA ARQUIVO E PASSA PONTOS PARA INTEIRO
int pegaArquivo(void){

    BESTPLAYERS bp[5];
    int pontuacaoInt[5];
    FILE *ptArq;
    int i;

    //abrindo o arquivo somente para leitura
    ptArq = fopen("highscore.bin", "rb");

    if(!ptArq){
        printf("\nErro ao abrir o arquivo.");
    }
    else{
        while(!feof(ptArq)){
            if(fread (&bp, sizeof(bp), 5, ptArq) == 5);
        }

        fclose(ptArq);
    }

    for(i=0; i<5; i++){
        pontuacaoInt[i] = bp[i].pontos;
    }

    return defineMaior(pontuacaoInt);
}

// PRECISA ACHAR UM JEITO DE PEGAR PONTOS DO JOGADOR
int defineMaior (int vet[]) {
    int posPontos = -1;
    int pontos = 35;


    if(/*jogador.*/pontos > vet[0]){
        posPontos = 0;
    }

    if(/*jogador.*/pontos > vet[1]){
        posPontos = 1;
    }

    if(/*jogador.*/pontos > vet[2]){
        posPontos = 2;
    }

    if(/*jogador.*/pontos > vet[3]){
        posPontos = 3;
    }

    if(/*jogador.*/pontos > vet[4]){
        posPontos = 4;
    }

    return posPontos;
}

void gravaArquivo(int lugar/*, JOGADOR *j*/){
    char nome[30];
    int pontos = 250;

    strcpy(nome, "Fábio");

    BESTPLAYERS bp[5];
    int pontuacaoInt[5];
    char strAuxiliar[10][15];
    FILE *ptArq;
    int i;

    //abrindo o arquivo somente para leitura
    ptArq = fopen("highscore.bin", "rb");

    if(!ptArq){
        printf("\nErro ao abrir o arquivo.");
    }
    else{
        while(!feof(ptArq)){
            if(fread (&bp, sizeof(bp), 5, ptArq) == 5);
        }

        fclose(ptArq);
    }

    // ALTERANDO ORDEM
    switch(lugar){
        case 0: for(i=4; i<0; i--){
                    strcpy(bp[i].nome, bp[i-1].nome);
                    bp[i].pontos = bp[i-1].pontos;
                }

                strcpy(bp[0].nome, nome);
                bp[0].pontos = pontos;

            break;
        case 1: for(i=4; i<1; i--){
                    strcpy(bp[i].nome, bp[i-1].nome);
                    bp[i].pontos = bp[i-1].pontos;
                }

                strcpy(bp[1].nome, nome);
                bp[1].pontos = pontos;
            break;
        case 2: for(i=4; i<2; i--){
                    strcpy(bp[i].nome, bp[i-1].nome);
                    bp[i].pontos = bp[i-1].pontos;
                }

                strcpy(bp[2].nome, nome);
                bp[2].pontos = pontos;
            break;
        case 3: for(i=4; i<3; i--){
                    strcpy(bp[i].nome, bp[i-1].nome);
                    bp[i].pontos = bp[i-1].pontos;
                }

                strcpy(bp[3].nome, nome);
                bp[3].pontos = pontos;
            break;
        case 4: strcpy(bp[4].nome, nome);
                bp[4].pontos = pontos;
            break;
    }

    ptArq = fopen("highscore.bin", "wb");

    if(!ptArq){
        printf("\nErro ao abrir o arquivo.");
    }
    else{
        if(fwrite(&bp, sizeof(bp), 5, ptArq) != 5){
            printf("\nErro ao gravar arquivo.");
        }
    }


}

#endif
