// Definição:

#ifndef proHighscore_h
#define proHighscore_h

/* Essa biblioteca vai ser usada para definir todas as funções necessárias para a criação da lógica do highscore, utilizando
as funções predefinidas da biblioteca Raylib */

// Bibliotecas utilizadas:
#include "raylib.h"
#include <stdio.h>

    typedef struct Melhor{
        char nome[30];
        int pontos;
    }MELHOR;

    MELHOR melhores[5];

void ficticiaLista (MELHOR melhores[]){ // Cria uma lista fictícia de jogadores

    char nome1[30]="Beatriz";
    char nome2[30]="Igor";
    char nome3[30]="Kamille";
    char nome4[30]="Joao";
    char nome5[30]="Marcelo";

    strcpy(melhores[0].nome,nome1);
    strcpy(melhores[1].nome,nome2);
    strcpy(melhores[2].nome,nome3);
    strcpy(melhores[3].nome,nome4);
    strcpy(melhores[4].nome,nome5);

    for (int i=0; i<5; i++){
        melhores[i].pontos = i*150;
    }
}

void fazLista (MELHOR melhores[], FILE *arq){

    ordenaLista(melhores);

    arq = fopen("top.bin", "wb");

    if (fwrite(melhores, sizeof(MELHOR), 5, arq) != 5)
        printf("Erro na escrita!\n");

    fclose(arq);

    for(int i=0; i<5; i++){
        printf("%s     %d\n", melhores[i].nome, melhores[i].pontos);
    }
}

void ordenaLista(MELHOR melhores[]){

	MELHOR temp;

    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (melhores[j].pontos < melhores[i].pontos){
                temp = melhores[i];
                melhores[i] = melhores[j];
                melhores[j] = temp;
            }
        }
    }
}

MELHOR ultimoLista(){

    FILE *arq;
    MELHOR ultimo;
    MELHOR melhores[5];

    arq = fopen("top.bin", "rb");

    for (int i=0; i<5; i++){
        if (fread(&melhores[i], sizeof(MELHOR), 1, arq) != 1){
            printf("Erro na leitura!\n");
        }
    }

    fclose(arq);

    ultimo = melhores[4];

    return ultimo;
}

void insereLista(int pts, char nome[]){

    FILE *arq;
    MELHOR jogador;
    MELHOR melhores[5];

    strcpy(jogador.nome, nome);
    jogador.pontos = pts;

    arq = fopen("top.bin", "rb");

    for (int i=0; i<5; i++){
        if (fread(&melhores[i], sizeof(MELHOR), 1, arq) != 1){
            printf("Erro na leitura!\n");
        }
    }

    fclose(arq);

    melhores[4] = jogador;

    fazLista(melhores, arq);

}

#endif
