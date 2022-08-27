#ifndef PLAY_H
#define PLAY_H

//BIBLIOTECAS:

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

void pegaMatriz(int nivel){
    char *ptArq;
    char str[5][10];
    int i, j;

    if(nivel == 1){
        // TENTATIVA DE PEGAR DADOS DE NIVEL1.TXT COMO MATRIZ (SPOILER: ERRO!)
        /*ptArq = fopen("nivel1.txt", "r");

        for(i=0; i<5; i++){
            for(j=0; j<10; j++){
                fscanf(ptArq, "%s", str[i][j]);
                printf("%s", str[i][j]);
            }
        }*/
    }
    if(nivel == 2){

    }
}






#endif
