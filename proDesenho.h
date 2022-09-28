// Definição:

#ifndef proDesenho_h
#define proDesenho_h

/* Essa biblioteca vai ser usada para definir todas as funções necessárias para desenhar o programa, utilizando as funções
predefinidas da biblioteca Raylib */

// Bibliotecas utilizadas:
#include "raylib.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "proJogo.h"
#include "proMenu.h"
#include "praDefinir.h"
#include "proHighscore.h"
#include "proPause.h"

// Funções para o Menu:

void limpaTela(){ // Deixa a tela no estado original em preto.
    DrawRectangle(0, 0, 1000, 2000, BLACK);
}

void desenhaMenu(){ // Desenha o Menu com o título, três botões, e créditos.

    DrawText("BreakoutINF", 240, 60, 50, WHITE); // Título do jogo.

    DrawRectangleGradientV(240, 150, 325, 50, ORANGE, GOLD); // Botão 'JOGAR'
    DrawRectangleLinesEx(botao1, 3, ORANGE);
        DrawText("JOGAR", 335, 156, 40, BLACK);

    DrawRectangleGradientV(240, 225, 325, 50, ORANGE, GOLD); // Botão 'PONTUAÇÃO'
    DrawRectangleLinesEx(botao2, 3, ORANGE);
        DrawText("PONTUACAO", 275, 231, 40, BLACK);

    DrawRectangleGradientV(240, 300, 325, 50, ORANGE, GOLD); // Botão 'SAIR'
    DrawRectangleLinesEx(botao3, 3, ORANGE);
        DrawText("SAIR", 355, 306, 40, BLACK);

    DrawText("Beatriz e Kamille, 2022/01", 240, 380, 26, WHITE); // Créditos
}

void desenhaMenuOp (int opcao){ // Desenha o botão em outra cor quando ele é selecionado.

    if (opcao == 0){
        DrawRectangleGradientV(240, 150, 325, 50, DARKPURPLE, PURPLE); // Botão 'JOGAR
        DrawRectangleLinesEx(botao1, 3, DARKPURPLE);
            DrawText("JOGAR", 335, 156, 40, WHITE);
    }
    if (opcao == 1){
        DrawRectangleGradientV(240, 225, 325, 50, DARKPURPLE, PURPLE); // Botão 'PONTUAÇÃO'
        DrawRectangleLinesEx(botao2, 3, DARKPURPLE);
            DrawText("PONTUACAO", 275, 231, 40, WHITE);
    }
    if (opcao == 2){
        DrawRectangleGradientV(240, 300, 325, 50, DARKPURPLE, PURPLE); // Botão 'SAIR'
        DrawRectangleLinesEx(botao3, 3, DARKPURPLE);
            DrawText("SAIR", 355, 306, 40, WHITE);
    }
}


// Funções para a Pontuação:


int desenhaPtos(){ // Desenha o menu Pontuação

    FILE *ptArq;
    BESTPLAYERS bp[5];

    //abrindo o arquivo_frase somente para leitura
    ptArq = fopen("highscore.bin", "rb");

    if(!ptArq){
        printf("\nErro ao abrir o arquivo.");
    }
    else{
        if(fread(&bp, sizeof(BESTPLAYERS), 5, ptArq) != 5){
            printf("\nErro ao ler arquivo.");
        }
        fclose(ptArq);
    }

    limpaTela();
    DrawText("TOP SCORES", 240, 60, 50, WHITE); // TITULO DO JOGO

    //VOLTA
        DrawRectangleGradientV(15, 15, 45, 45, ORANGE, GOLD); //QUADRADO
            DrawRectangleLinesEx(volta1, 3, ORANGE);
        DrawText("V", 23, 21, 40, BLACK);
        DrawText("Voltar", 70, 21, 40, WHITE);

    //POS 1
        DrawRectangleGradientV(100, 130, 45, 45, ORANGE, GOLD); //QUADRADO
            DrawRectangleLinesEx(pos1, 3, ORANGE);
            DrawText("1", 118, 135, 40, BLACK); //POS

        DrawText(bp[0].nome, 200, 135, 40, WHITE); // NOME
        DrawText(bp[0].pontos, 600, 135, 40, WHITE); // PONTOS

    //POS 2
        DrawRectangleGradientV(100, 190, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos2, 3, ORANGE);
            DrawText("2", 113, 195, 40, BLACK);

        DrawText(bp[1].nome, 200, 195, 40, WHITE); // NOME
        DrawText(bp[1].pontos, 600, 195, 40, WHITE); // PONTOS

    //POS 3
        DrawRectangleGradientV(100, 250, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos3, 3, ORANGE);
            DrawText("3", 113, 255, 40, BLACK);

        DrawText(bp[2].nome, 200, 255, 40, WHITE); // NOME
        DrawText(bp[2].pontos, 600, 255, 40, WHITE); // PONTOS

    //POS 4
        DrawRectangleGradientV(100, 310, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos4, 3, ORANGE);
            DrawText("4", 113, 315, 40, BLACK);

        DrawText(bp[3].nome, 200, 315, 40, WHITE); // NOME
        DrawText(bp[3].pontos, 600, 315, 40, WHITE); // PONTOS


    //POS 5
        DrawRectangleGradientV(100, 370, 45, 45, ORANGE, GOLD);
            DrawRectangleLinesEx(pos5, 3, ORANGE);
        DrawText("5", 113, 375, 40, BLACK);

        DrawText(bp[4].nome, 200, 375, 40, WHITE); // NOME
        DrawText(bp[4].pontos, 600, 375, 40, WHITE); // PONTOS

        fclose(ptArq);
}



/*
NÃO SEI QUE MERDA EU FIZ AQUI --> BEATRIZ era pra ta funcionando vo me matar
void desenhaPtos(){

    FILE *arq;
    MELHOR jogadores[5];

    arq = fopen("highscore.bin", "rb");

    if(!arq){
        printf("\nErro ao abrir o arquivo.");
    }
    else{
        if(fread(&jogadores, sizeof(MELHOR), 5, arq) != 5){
            printf("\nErro ao ler arquivo.");
        }
        fclose(arq);
    }

    limpaTela();
    DrawText("TOP SCORES", 240, 60, 50, WHITE); // TITULO DO JOGO

    //VOLTA
    DrawRectangleGradientV(15, 15, 45, 45, ORANGE, GOLD); //QUADRADO
        DrawRectangleLinesEx(volta1, 3, ORANGE);
    DrawText("V", 23, 21, 40, BLACK);
    DrawText("Voltar", 70, 21, 40, WHITE);

    //POS 1
    DrawRectangleGradientV(100, 130, 45, 45, ORANGE, GOLD); //QUADRADO
        DrawRectangleLinesEx(pos1, 3, ORANGE);
        DrawText("1", 118, 135, 40, BLACK); //POS

    DrawText(jogadores[0].nome, 200, 135, 40, WHITE); // NOME
    DrawText((TextFormat("%i", jogadores[0].pontos)), 600, 135, 40, WHITE); // PONTOS

    //POS 2
    DrawRectangleGradientV(100, 190, 45, 45, ORANGE, GOLD);
        DrawRectangleLinesEx(pos2, 3, ORANGE);
        DrawText("2", 113, 195, 40, BLACK);

    DrawText(jogadores[1].nome, 200, 195, 40, WHITE); // NOME
    DrawText((TextFormat("%i", jogadores[1].pontos)), 600, 195, 40, WHITE); // PONTOS

    //POS 3
    DrawRectangleGradientV(100, 250, 45, 45, ORANGE, GOLD);
        DrawRectangleLinesEx(pos3, 3, ORANGE);
        DrawText("3", 113, 255, 40, BLACK);

    DrawText(jogadores[2].nome, 200, 255, 40, WHITE); // NOME
    DrawText((TextFormat("%i", jogadores[2].pontos)), 600, 255, 40, WHITE); // PONTOS

    //POS 4
    DrawRectangleGradientV(100, 310, 45, 45, ORANGE, GOLD);
        DrawRectangleLinesEx(pos4, 3, ORANGE);
    DrawText("4", 113, 315, 40, BLACK);

    DrawText(jogadores[3].nome, 200, 315, 40, WHITE); // NOME
    DrawText((TextFormat("%i", jogadores[3].pontos)), 600, 315, 40, WHITE); // PONTOS


    //POS 5
    DrawRectangleGradientV(100, 370, 45, 45, ORANGE, GOLD);
        DrawRectangleLinesEx(pos5, 3, ORANGE);
        DrawText("5", 113, 375, 40, BLACK);

    DrawText(jogadores[4].nome, 200, 375, 40, WHITE); // NOME
    DrawText((TextFormat("%i", jogadores[4].pontos)), 600, 375, 40, WHITE); // PONTOS

    fclose(arq);
}

*/

// Funções para o jogo:

/*
void desenhaBlocos(){
    int i, j;
    int x = 25, y = 20;                                             // posição x inicia em 25 e y em 20
    char blocos[B_LINHA][B_COLUNA];

    pegaMatrizBlocos(blocos);                                       // pega a matriz do arquivo

    for(i=0; i<B_LINHA; i++){
        for(j=0; j<B_COLUNA; j++){
            switch(blocos[i][j]){                                   // faz um switch pra cada letra da matriz e entra no caractere que corresponde

                case 'R':   DrawRectangle(x, y, 60, 10, RED);
                    break;
                case 'G':   DrawRectangle(x, y, 60, 10, DARKGREEN);
                    break;
                case 'B':   DrawRectangle(x, y, 60, 10, DARKBLUE);
                    break;
                case 'Y':   DrawRectangle(x, y, 60, 10, YELLOW);
                    break;
                case 'X':   DrawRectangle(x, y, 60, 10, DARKPURPLE);
                    break;
                case '-':   DrawRectangle(x, y, 60, 10, BLACK);
                    break;
            }
            x = x + 75;                                             // sempre atualiza o x e cada bloco fica a uma distância de 50px um do outro
        }
            x = 25;                                                 // a posição dos blocos no eixo x sempre começa em 25
            y = y + 20;                                             // sempre que termina de desenhar uma linha, acrescenta 20px, ou seja,
                                                                    // i = 0 --> y = 20   i = 1 --> y = 40       e assim segue
    }
}

*/

void desenhaJogador(){                  // Desenha a raquete do Jogador

    DrawRectangle(jogador.posicao.x - jogador.tamanho.x/2, jogador.posicao.y - jogador.tamanho.y/2, jogador.tamanho.x, jogador.tamanho.y, WHITE);
}

void desenhaBola(){                     // Desenha a bola

    DrawCircleV(bola.posicao, bola.raio, bola.cor);
}

void desenhaPontosJogo(){               // Desenha a quantidade de pontos do Jogador

    DrawText(TextFormat("%i", jogador.pontos), 690, 390, 45, WHITE);

}

void desenhaVidas(){                    // Desenha a quantidade de vidas do Jogador

    for (int i = 0; i < jogador.vidas; i++) DrawRectangle(20 + 40*i, TELA_ALTURA - 30, 35, 10, WHITE);
}

int desenhaNome(char nome[30]){

    int tela;
    int tecla;
    int letras=0;
    tecla=GetCharPressed();


    while(!IsKeyPressed(KEY_ENTER)){

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Qual o seu nome?", 190, 60, 50, WHITE);
        DrawRectangleLinesEx(nom1, 6, ORANGE);

        tecla=GetCharPressed();

        while(tecla>0 && letras<10){

            nome[letras] = tecla;
            nome[letras+1] = '\0';
            tecla = 0;
            letras++;
        }

        tecla=GetCharPressed();

        DrawText(nome, 220, 210, 70, WHITE);
        EndDrawing();

    }

    tela = 0;

    return tela;

}

/*
void desenhaTeste(){

    int i, j;
    for (i=0; i<B_LINHA; i++){
        for (j=0; j<B_COLUNA; j++){ // Anda na matriz

            if (bloco[i][j].ativo == true){ // Se o bloco está ativo

                if ((i + j) % 2 == 0){
                    DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, BLUE);
                }
                else DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, RED);
            }
        }
    }

}
*/

/*
void desenhaBlocos2(void){

    char bloco_cores[B_LINHA][B_COLUNA];

    pegaMatrizBlocos(bloco_cores);

    int i, j;
    for (i=0; i<B_LINHA; i++){
        for (j=0; j<B_COLUNA; j++){ // Anda na matriz

            if (bloco_cores[i][j] == '-'){
                bloco[i][j].ativo = false;
            }

            if (bloco[i][j].ativo == true){ // Se o bloco está ativo

                switch (bloco_cores[i][j]){

                    case 'R':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, RED);
                                break;
                    case 'G':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, DARKGREEN);
                                break;
                    case 'B':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, DARKBLUE);
                                break;
                    case 'Y':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, YELLOW);
                                break;
                    case 'X':   DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, DARKPURPLE);
                                break;
                }
            }
        }
    }
}
*/

void desenhaBlocos3(void){

    for (int i=0; i<B_LINHA; i++){
        for (int j=0; j<B_COLUNA; j++){ // Anda na matriz
            if (bloco[i][j].ativo == true){
                DrawRectangleV(bloco[i][j].posicao, bloco[i][j].tamanho, bloco[i][j].cor);
                /*if (bloco[i][j].especial != 0){
                    DrawRectangleLinesEx((Rectangle){bloco[i][j].posicao.x, bloco[i][j].posicao.y, bloco[i][j].tamanho.x,
                                        bloco[i][j].tamanho.y}, 3, GOLD);
                }*/
                switch (bloco[i][j].especial){
                    case 1: DrawRectangleLinesEx((Rectangle){bloco[i][j].posicao.x, bloco[i][j].posicao.y, bloco[i][j].tamanho.x,
                                bloco[i][j].tamanho.y}, 3, DARKGREEN);
                            break;
                    case 2: DrawRectangleLinesEx((Rectangle){bloco[i][j].posicao.x, bloco[i][j].posicao.y, bloco[i][j].tamanho.x,
                                bloco[i][j].tamanho.y}, 3, DARKBLUE);
                            break;
                    case 3: DrawRectangleLinesEx((Rectangle){bloco[i][j].posicao.x, bloco[i][j].posicao.y, bloco[i][j].tamanho.x,
                                bloco[i][j].tamanho.y}, 3, GOLD);
                            break;
                }
            }
        }
    }
}



void desenhaJogo(){                     // Desenha o Jogo inteiro (junção de todas as funções de desenho do Jogo)

    desenhaJogador();       // Raquete
    desenhaBola();          // Bola
    desenhaVidas();         // Vidas
    desenhaPontosJogo();    // Pontuação
    desenhaBlocos3();

    if (pause){
        desenhaPause();
        //desenhaProx();
    }

}


void desenhaEndGame(){
    setlocale(LC_ALL, " ");

    DrawText("Fim de jogo!", TELA_LARGURA/3, TELA_ALTURA/3, 45, WHITE);

    DrawText("Sua pontuacaoo eh", TELA_LARGURA/6, TELA_ALTURA/2, 45, WHITE);
    DrawText(TextFormat("%i", jogador.pontos), TELA_LARGURA/1.3, TELA_ALTURA/2, 45, WHITE);

    DrawRectangleGradientV(15, 15, 45, 45, ORANGE, GOLD); // quadrado
        DrawRectangleLinesEx(volta1, 3, ORANGE);
    DrawText("V", 23, 21, 40, BLACK);
    DrawText("Voltar", 70, 21, 40, WHITE);

    DrawRectangleGradientV(530, 390, 45, 45, ORANGE, GOLD); // quadrado
        DrawRectangleLinesEx(prox, 3, ORANGE);
    //DrawText(">", 545, 385, 60, BLACK);
    DrawText("C", 539, 392, 45, BLACK);
    DrawText("Continuar", 590, 400, 40, WHITE);
}


// Funções para o pause:

void desenhaPause(){

    DrawRectangle(240, 100, 300, 240, BLACK);
    DrawRectangleLinesEx(rec1, 3, ORANGE);

    DrawText("PAUSADO", 270, 130, 50, WHITE);

    DrawRectangleGradientV(270, 195, 45, 45, ORANGE, GOLD); //QUADRADO
    DrawRectangleLinesEx(con2, 3, ORANGE);
    DrawText("P", 279, 199, 40, BLACK);
    DrawText("CONTINUAR", 330, 205, 30, WHITE);

    /*DrawRectangleGradientV(270, 260, 45, 45, ORANGE, GOLD); //QUADRADO
    DrawRectangleLinesEx(con3, 3, ORANGE);
    DrawText("S", 281, 264, 40, BLACK);
    DrawText("SAIR", 330, 270, 30, WHITE);*/

}

void desenhaProx(){

    limpaTela();

    DrawText("Voce passou de nivel!", 130, 170, 50, WHITE);

    DrawRectangleGradientV(530, 390, 45, 45, ORANGE, GOLD); // quadrado
        DrawRectangleLinesEx(prox, 3, ORANGE);
    DrawText("C", 539, 392, 45, BLACK);
    DrawText("Continuar", 590, 400, 40, WHITE);

}

void desenhaFim(){

    limpaTela();

    DrawText("Voce zerou o jogo!", 130, 170, 50, WHITE);

    DrawRectangleGradientV(530, 390, 45, 45, ORANGE, GOLD); // quadrado
        DrawRectangleLinesEx(prox, 3, ORANGE);
    DrawText("C", 539, 392, 45, BLACK);
    DrawText("Continuar", 590, 400, 40, WHITE);

}


#endif
