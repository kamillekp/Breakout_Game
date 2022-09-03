#define HIGHSCORE_H

//BIBLIOTECAS:

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int pontos = 35;
char nomeJogador[50] = "Manuel";

// PEGA ARQUIVO E PASSA PONTOS PARA INTEIRO
void pegaArquivo(){
    FILE *ptArq;
    char str[10][100];
    int pontuacaoInt [5];
    int tam = 5;

    //abrindo o arquivo_frase somente para gravação gravação
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

    defineMaior(pontuacaoInt, tam);
}

void gravaArquivo(int lugar){

    FILE *ptArq;
    char str[10][100];
    char strAuxiliar[10][100];
    char juncaoStr [300];
    int i;

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
        case 0: strcpy(strAuxiliar[0], nomeJogador);
                strcpy(strAuxiliar[1], pontos);
            break;
        case 1: strcpy(strAuxiliar[2], nomeJogador);
                strcpy(strAuxiliar[3], pontos);
            break;
        case 2: strcpy(strAuxiliar[4], nomeJogador);
                strcpy(strAuxiliar[5], pontos);
            break;
        case 3: strcpy(strAuxiliar[6], nomeJogador);
                strcpy(strAuxiliar[7], pontos);
            break;
        case 4: strcpy(strAuxiliar[8], nomeJogador);
                strcpy(strAuxiliar[9], pontos);
            break;
        default: printf("NÃO ENTROU!");
    }*/

    // GRAVANDO
    ptArq = fopen("highscore.bin", "w");


    strcpy(juncaoStr, strcat(strAuxiliar[0], strcat(strAuxiliar[1], strcat(strAuxiliar[2], strcat(strAuxiliar[3], strcat(strAuxiliar[4], strcat(strAuxiliar[5], strcat(strAuxiliar[6], strcat(strAuxiliar[7], strcat(strAuxiliar[8], "teste"/*strAuxiliar[9]*/))))))))));

    fputs(juncaoStr, ptArq);
    fclose(ptArq);
}


// PONTOS VÊM DA VARIÁVEL GLOBAL, TEMOS QUE VER COMO TRAZER O NOME E OS PONTOS DO JOGADOR PRA CÁ
void defineMaior (int vet[], int tam) {
    if(pontos > vet[0]){
        gravaArquivo(0);
    }
    else if(pontos > vet[1]){
        gravaArquivo(1);
    }
    else if(pontos > vet[2]){
        gravaArquivo(2);
    }
    else if(pontos > vet[3]){
        gravaArquivo(3);
    }
    else if(pontos > vet[4]){
        gravaArquivo(4);
    }

}


