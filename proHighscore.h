
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

// PEGA ARQUIVO E PASSA PONTOS PARA INTEIRO
int pegaArquivo(){
    FILE *ptArq;
    int pontuacaoInt [5];
    char str[150];
    int num;
    int i = 0;

    //abrindo o arquivo somente para leitura
    ptArq = fopen("highscore.bin", "r");

        while(fgets(str, 150, ptArq)){              // pegando casa linha do arquivo
            if(i%2 != 0){
                num = atoi(str);                     // transformando em int
                pontuacaoInt[i] = num;
            }
            i++;
        }

        fclose(ptArq);

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

    FILE *ptArq;
    char str[10][100];
    char strAuxiliar[10][100];
    char juncaoStr [300];
    int i = 0;

    // LENDO
    ptArq = fopen("highscore.bin", "r");

    while(fgets(str, 100, ptArq)){
        strcpy(strAuxiliar[i], str);
        i++;
    }

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
    strcpy(juncaoStr, strcat(strAuxiliar[0], strcat(strAuxiliar[1], strcat(strAuxiliar[2], strcat(strAuxiliar[3], strcat(strAuxiliar[4], strcat(strAuxiliar[5], strcat(strAuxiliar[6], strcat(strAuxiliar[7], strcat(strAuxiliar[8], "35"/*strAuxiliar[9]*/))))))))));

    ptArq = fopen("highscore.bin", "w");
    fputs(juncaoStr, ptArq);
    fclose(ptArq);
}

#endif
