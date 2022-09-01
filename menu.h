int opcao=0;
int menu=5;
int *ponteiro = &opcao;

void updownMenu(int opcao){ // MUDA AS OPÇÕES DOS BOTÕES

    if(IsKeyPressed(KEY_DOWN)){
        switch (opcao){
            case 0: *ponteiro = 1;
                    break;
            case 1: *ponteiro = 2;
                    break;
            case 2: *ponteiro = 0;
                    break;
        }
    }
    else if(IsKeyPressed(KEY_UP)){
        switch (opcao){
            case 0: *ponteiro = 2;
                    break;
            case 1: *ponteiro = 0;
                    break;
            case 2: *ponteiro = 1;
                    break;
        }
    }
    desenhaMenuOp(opcao);
}

int decideMenu(void){ // MUDA O MENU

    if (IsKeyUp(KEY_ENTER)){
        updownMenu(opcao);
    }

    if (IsKeyPressed(KEY_ENTER)){
        switch (opcao){
            case 0: menu = 0; // JOGO
                    break;
            case 1: menu = 1; // PONTUAÇÃO
                    break;
            case 2: CloseWindow(); // SAIR
                    break;
        }
    }

    return menu;
}

void voltaMenu(){ // VOLTA PRO MENU
    if (IsKeyPressed(KEY_V)){
        menu = 100;
    }
}

void completoMenu(){ // MENU COMPLETO

        desenhaMenu();
        menu = decideMenu();

        if (menu == 0){ // COMEÇA O JOGO
            /*initJogo(); // TEM QUE TER UMA FUNÇÃO PROPRIA PRA COLOCAR AQUI QUE SEJA O JOGO TODO
            limpaTela();
            updateJogoDesenho();*/
            int game = 0;

            Vector2 ballPosition = {TELA_LARGURA/2, TELA_ALTURA/2 };

            do{

            limpaTela();

            if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 5.0f;
            if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 5.0f;
            if (IsKeyDown(KEY_UP)) ballPosition.y -= 5.0f;
            if (IsKeyDown(KEY_DOWN)) ballPosition.y += 5.0f;

            DrawCircleV(ballPosition, 50, MAROON);

            }while(game=0);

            }

        else if (menu == 1){ // DESENHA O MENU PONTUAÇÃO
            desenhaPtos();
            voltaMenu();
        }

}

