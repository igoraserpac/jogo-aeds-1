#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cobra.h"
#include "telas.h"
#include <math.h>

int main(){

    // Declaração de algumas variáveis necessárias para a inicialização do jogo.
    int tela = START_MENU;
    int pontuacao = 0;
    int cont = 0;
    int difi = FACIL;
    char apelido[4];

    // Alocacação da cobra e inicialização dos valores da cobra e do pintinho.
    cobra *elvira = gera_cobra();
    fruta maca = gera_fruta(elvira);

    // Inicio do jogo
    abre_janela(640, 480);
    while(janela_esta_aberta()){

        // Como a variável "tela" foi inicializada com o valor "START_MENU", a unica função
        // chamada inicialmente é a "menu_iniciar()", que desenha o menu na tela até que o
        // valor da variável tela seja alterado. As funções chamadas dentro de cada if são
        // responsáveis por alterar o valor dessa variável.

        if(tela == START_MENU){
            if(!som_esta_tocando("assets/stage1.wav")) toca_som("assets/stage1.wav");
            menu_iniciar(&tela);
        }

        if(tela == ESCOLHE_DIFICULDADE){
            para_som("assets/stage1.wav");
            if(!som_esta_tocando("assets/select.wav")) toca_som("assets/select.wav");
            escolhe_dificuldade(&tela, &difi);
        }

        if(tela == NICK_NAME){
            if(som_esta_tocando("assets/stage1.wav")) para_som("assets/stage1.wav");
            if(!som_esta_tocando("assets/select.wav")) toca_som("assets/select.wav");
            recebe_nick(&tela, apelido);
        }
        if(tela == MAIN_GAME){
            para_som("assets/select.wav");
            if(!som_esta_tocando("assets/main_game.wav")) toca_som("assets/main_game.wav");
            jogar(elvira, difi, &cont, &maca, &pontuacao, &tela);
        }

        if(tela == GAME_OVER){
            para_som("assets/main_game.wav");
            game_over(elvira, &tela, &pontuacao, apelido);
        }

        if(tela == RANKING){
            if(!som_esta_tocando("assets/stage1.wav")) toca_som("assets/stage1.wav");
            ranking(&tela);
        }

    }

    // Ao sair do while principal a cobra precisa ser desalocada.
    destroi_cobra(elvira);

    fecha_janela();
}
