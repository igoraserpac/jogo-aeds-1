#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cobra.h"
#include "telas.h"

// dudutcampossm1204@gmail.com

int main(){
    int tela = START_MENU;
    int pontuacao = 0;
    int cont = 0;
    cobra elvira;
    elvira.tamanho = 2;
    elvira.direcao = PARA_DIREITA;
    segmento s[3072];
    for(int i=0; i<elvira.tamanho; i++){
        s[i].posix = 310 - (TAMANHO_SEGMENTO * i);
        s[i].posiy = 230;
        elvira.segmentos[i] = s[i];
    }
    abre_janela(640, 480);
    fruta maca = gera_fruta(&elvira);
    int difi = FACIL;
    char apelido[4];
    while(janela_esta_aberta()){
        if(tela == START_MENU) menu_iniciar(&tela);
        if(tela == ESCOLHE_DIFICULDADE) escolhe_dificuldade(&tela, &difi);
        if(tela == NICK_NAME) recebe_nick(&tela, apelido);
        if(tela == MAIN_GAME) jogar(&elvira, difi, &cont, &maca, &pontuacao, &tela);
        if(tela == GAME_OVER) game_over(&elvira, &tela, &pontuacao);
        if(tela == RANKING) ranking(&tela);
    }
    fecha_janela();
}
