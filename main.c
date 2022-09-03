#include "proDesenho.h"
#include "proJogo.h"
#include "proMenu.h"
#include "praDefinir.h"
#include "proHighscore.h"

int main(){

    //JOGADOR player;
    bool returnJogo = false; // retorna se o jogo terminou ou n�o
    int telaAtual = 0;
    int op;

    //player.pontos = 0;

    InitWindow(TELA_LARGURA, TELA_ALTURA, TELA_NOME);
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground(BLACK);

        printf("%d", telaAtual);

        if (telaAtual==0){ // Menu principal
            desenhaMenu();
            decideTela(&telaAtual);
        }

        if (telaAtual == 1){ // Pontua��o
             desenhaPtos();

             if(IsKeyPressed(KEY_V)){
                telaAtual = 0;
             }
            //Volta menu aqui
        }

        if (telaAtual == 2){ // Jogo
            desenhaJogo();

            // FUNCAOJOGO(&returnJogo, &player.pontos);
                    // recebe returnJogo como ponteiro para poder retornar true quando o jogo acabar
                    // recebe player.pontos como ponteiro para poder setar a pontua��o dele no final do jogo

            /*if(returnJogo == true){
                pegaArquivo(&player);
            }*/
        }

        EndDrawing();

    }

    return 0;
}
