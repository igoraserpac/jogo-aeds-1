#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cobra.h"
#include "telas.h"


int main(){
    int cont = 0;
    cobra elvira;
    elvira.tamanho = 3;
    elvira.direcao = PARA_DIREITA;
    segmento s[3072];
    for(int i=0; i<elvira.tamanho; i++){
        s[i].posix = 200 - (TAMANHO_SEGMENTO * i);
        s[i].posiy = 200;
        elvira.segmentos[i] = s[i];
    }
    abre_janela(640, 480);
    fruta maca = gera_fruta(&elvira);
    while(janela_esta_aberta()){
        jogar(&elvira, FACIL, &cont, &maca);
    }
    fecha_janela();
}
