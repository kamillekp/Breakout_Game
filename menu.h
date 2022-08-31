int opcao=0;
int menu=5;
int *ponteiro = &opcao;

// MUDA AS OPÇÕES DOS BOTÕES
void updownMenu(int opcao){

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

// MUDA O MENU
int decideMenu(void){

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

void voltaMenu(){
    if (IsKeyPressed(KEY_V)){
        menu = 100;
    }
}

void completoMenu(){

        desenhaMenu();
        menu = decideMenu();

        if (menu == 0){ // COMEÇA O JOGO
            initJogo(); // TEM QUE TER UMA FUNÇÃO PROPRIA PRA COLOCAR AQUI QUE SEJA O JOGO TODO
            limpaTela();
            updateJogoDesenho();
            }

        else if (menu == 1){ // DESENHA O MENU PONTUAÇÃO
            desenhaPtos();
            voltaMenu();
        }

}

