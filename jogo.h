void initJogador(void){

    Jogador.Posicao = (Vector2){TELA_LARGURA/2, TELA_ALTURA*7/8};
    Jogador.Tamanho = (Vector2){TELA_LARGURA/10, 20};
    Jogador.Vidas = MAX_VIDAS;

}

void initBola(void){

    Bola.Posicao = (Vector2){TELA_LARGURA/2, TELA_ALTURA*2/3};
    Bola.Velocidade = (Vector2){0, 0};
    Bola.Raio = 7;
    Bola.Ativa = false;
}

void mexeRaquete(void){

    if (IsKeyDown(KEY_LEFT)){
        Jogador.Posicao.x -= 5; // diminui pos_x em 5 VAI PRA ESQUERDA
    }
    if ((Jogador.Posicao.x - Jogador.Tamanho.x/2) <= 0){ //se chegou na borda da esquerda,
        Jogador.Posicao.x = Jogador.Tamanho.x/2; // não deixa ir mais pra esquerda
    }
    if (IsKeyDown(KEY_RIGHT)){
        Jogador.Posicao.x += 5; // aumenta pos_x em 5 VAI PRA DIREITA
    }
    if ((Jogador.Posicao.x + Jogador.Tamanho.x/2) >= TELA_LARGURA){ //se chegou na borda da direita
        Jogador.Posicao.x = TELA_LARGURA - Jogador.Tamanho.x/2; // nao deixa ir pra direita
    }
}

void initJogo(void){

    initJogador();
    initBola();
}

void UpdateJogo(){

    mexeRaquete();

}

void UpdateFrameJogo(){

    UpdateJogo();
    desenhaJogador();
}
