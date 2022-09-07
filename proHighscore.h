
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

int pontos = 35;
int posPontos = -1;

// PEGA ARQUIVO E PASSA PONTOS PARA INTEIRO
int pegaArquivo(){
    FILE *ptArq;
    int pontuacaoInt [5];
    char str[10][100];

    //abrindo o arquivo somente para leitura
    ptArq = fopen("highscore.bin", "r");

        // IGNORAR
        fgets(str[0], 100, ptArq);

        fgets(str[1], 100, ptArq);
        pontuacaoInt[0] = atoi(str[1]);


        // IGNORAR
        fgets(str[2], 100, ptArq);

        fgets(str[3], 100, ptArq);
        pontuacaoInt[1] = atoi(str[3]);


        // IGNORAR
        fgets(str[4], 100, ptArq);

        fgets(str[5], 100, ptArq);
        pontuacaoInt[2] = atoi(str[5]);


        // IGNORAR
        fgets(str[6], 100, ptArq);

        fgets(str[7], 100, ptArq);
        pontuacaoInt[3] = atoi(str[7]);


        // IGNORAR
        fgets(str[8], 100, ptArq);

        fgets(str[9], 100, ptArq);
        pontuacaoInt[4] = atoi(str[9]);

    fclose(ptArq);

    return defineMaior(pontuacaoInt);
}


// PRECISA ACHAR UM JEITO DE PEGAR PONTOS DO JOGADOR
int defineMaior (int vet[]) {

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

    FILE *ptArq;
    char str[10][100];
    char strAuxiliar[10][100];
    char juncaoStr [300];

    // LENDO
    ptArq = fopen("highscore.bin", "r");

        fgets(str[0], 100, ptArq); // NOME 1
            strcpy(strAuxiliar[0], str[0]);
        fgets(str[1], 100, ptArq); // PONTOS
            strcpy(strAuxiliar[1], str[1]);

        fgets(str[2], 100, ptArq); // NOME 2
            strcpy(strAuxiliar[2], str[2]);
        fgets(str[3], 100, ptArq); // PONTOS
            strcpy(strAuxiliar[3], str[3]);

        fgets(str[4], 100, ptArq); // NOME 3
            strcpy(strAuxiliar[4], str[4]);
        fgets(str[5], 100, ptArq); // PONTOS
            strcpy(strAuxiliar[5], str[5]);

        fgets(str[6], 100, ptArq); // NOME 4
            strcpy(strAuxiliar[6], str[6]);
        fgets(str[7], 100, ptArq); // PONTOS
            strcpy(strAuxiliar[7], str[7]);

        fgets(str[8], 100, ptArq); // NOME 5
            strcpy(strAuxiliar[8], str[8]);
        fgets(str[9], 100, ptArq); // PONTOS
            strcpy(strAuxiliar[9], str[9]);

    fclose(ptArq);


    // ALTERANDO ORDEM
   /* switch(lugar){
        case 0: strcpy(strAuxiliar[0], *j.nome);
                strcpy(strAuxiliar[1], *j.pontos);
            break;
        case 1: strcpy(strAuxiliar[2], *j.nome);
                strcpy(strAuxiliar[3], *j.pontos);
            break;
        case 2: strcpy(strAuxiliar[4], *j.nome);
                strcpy(strAuxiliar[5], *j.pontos);
            break;
        case 3: strcpy(strAuxiliar[6], *j.nome);
                strcpy(strAuxiliar[7], *j.pontos);
            break;
        case 4: strcpy(strAuxiliar[8], *j.nome);
                strcpy(strAuxiliar[9], *j.pontos);
            break;
        default: printf("NÃO ENTROU!");
    }*/


    // GRAVANDO
    ptArq = fopen("highscore.bin", "w");
    strcpy(juncaoStr, strcat(strAuxiliar[0], strcat(strAuxiliar[1], strcat(strAuxiliar[2], strcat(strAuxiliar[3], strcat(strAuxiliar[4], strcat(strAuxiliar[5], strcat(strAuxiliar[6], strcat(strAuxiliar[7], strcat(strAuxiliar[8], "teste"/*strAuxiliar[9]*/))))))))));
    fputs(juncaoStr, ptArq);
    fclose(ptArq);
}

#endif
