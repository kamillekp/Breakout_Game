#include "proDesenho.h"
#include "proJogo.h"
#include "proMenu.h"
#include "praDefinir.h"
#include "proHighscore.h"

int main(){

    int telaAtual = 0;
    int op;

    InitWindow(TELA_LARGURA, TELA_ALTURA, TELA_NOME);
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground(BLACK);

        if (telaAtual==0){ // Menu principal
            desenhaMenu();
            telaAtual = decideTela();
        }

        if (telaAtual == 1){ // Pontuação

            desenhaPtos();
            //Volta menu aqui
        }

        if (telaAtual == 2){ // Jogo
            DrawCircle(50, 50, 10, YELLOW);
        }

        EndDrawing();

    }

    return 0;
}
