#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cobra.h"
#include "telas.h"
#include <math.h>

int main(){
    int tela = START_MENU;
    int pontuacao = 0;
    int cont = 0;
    cobra *elvira = gera_cobra();
    abre_janela(640, 480);
    fruta maca = gera_fruta(elvira);
    int difi = FACIL;
    char apelido[4];
    while(janela_esta_aberta()){
        if(tela == START_MENU){
            if(!som_esta_tocando("assets/stage1.wav")) toca_som("assets/stage1.wav");
            menu_iniciar(&tela);
        }
        if(tela == ESCOLHE_DIFICULDADE){
            para_som("assets/stage1.wav");
            if(!som_esta_tocando("assets/select.wav")) toca_som("assets/select.wav");
            escolhe_dificuldade(&tela, &difi);
        }
        if(tela == NICK_NAME) recebe_nick(&tela, apelido);
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
    destroi_cobra(elvira);
    fecha_janela();
}
