void initJogo(void){ // INIICALIZA JOGADOR E BOLA

    //INICIALIZA JOGADOR
    Jogador.posX = TELA_LARGURA/2;
    Jogador.posY = TELA_ALTURA*7/8;
    Jogador.tamX = TELA_LARGURA/10;
    Jogador.tamY = 20;
    Jogador.Vidas = MAX_VIDAS;

    //INICIALIZA BOLA
    Bola.Posicao = (Vector2){TELA_LARGURA/2, TELA_ALTURA*2/3};
    Bola.Velocidade = (Vector2){0, 0};
    Bola.Raio = 7;
    Bola.Ativa = false;

}

void mexeRaquete(void){ // LÓGICA PRA MEXER A RAQUETE

    if (IsKeyDown(KEY_LEFT)){
        Jogador.posX -= 5; // diminui pos_x em 5 VAI PRA ESQUERDA
    }
    if ((Jogador.posX - Jogador.tamX/2) <= 0){ //se chegou na borda da esquerda,
        Jogador.posX = Jogador.tamX/2; // não deixa ir mais pra esquerda
    }
    if (IsKeyDown(KEY_RIGHT)){
        Jogador.posX += 5; // aumenta pos_x em 5 VAI PRA DIREITA
    }
    if ((Jogador.posX + Jogador.tamX/2) >= TELA_LARGURA){ //se chegou na borda da direita
        Jogador.posX = TELA_LARGURA - Jogador.tamX/2; // nao deixa ir pra direita
    }
}

void updateJogo(){ // ATUALIZA A LÓGICA DO JOGO

    mexeRaquete();

}

void updateJogoDesenho(){ // ATUALIZA A LÓGICA E DESENHA COM A LOGICA ATUALIZADA

    updateJogo();
    desenhaJogo();
}
