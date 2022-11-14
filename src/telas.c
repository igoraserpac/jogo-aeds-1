#include "telas.h"

void limites(){
    desenha_retangulo(0, 0, 640, 10);
    desenha_retangulo(0, 0, 10, 480);
    desenha_retangulo(0, 470, 640, 10);
    desenha_retangulo(630, 0, 10, 480);
}


void jogar(cobra *elvira, int lvl, int *cont, fruta *maca){
    cor(BRANCO);
    limites();
    dificuldade(cont, lvl, elvira, maca);
    cor(VERDE);
    desenha_retangulo((maca->posix)+4, (maca->posiy), 3, 2);
    cor(220, 20, 60);
    desenha_retangulo((maca->posix)+2, (maca->posiy)+2, 6, 6);
    cor(BRANCO);
    for(int i=0; i<elvira->tamanho; i++){
        cor(34, 139, 34, 255);
        desenha_retangulo((elvira->segmentos[i].posix)+1, (elvira->segmentos[i].posiy)+1, TAMANHO_SEGMENTO-2, TAMANHO_SEGMENTO-2);
        cor(0, 255, 0, 255);
        desenha_retangulo((elvira->segmentos[i].posix)+2, (elvira->segmentos[i].posiy)+2, TAMANHO_SEGMENTO-4, TAMANHO_SEGMENTO-4);
    }
    if(tecla_acabou_de_ser_apertada(CIMA) && elvira->direcao != PARA_BAIXO) elvira->direcao = PARA_CIMA;
    if(tecla_acabou_de_ser_apertada(BAIXO) && elvira->direcao != PARA_CIMA) elvira->direcao = PARA_BAIXO;
    if(tecla_acabou_de_ser_apertada(ESQUERDA) && elvira->direcao != PARA_DIREITA) elvira->direcao = PARA_ESQUERDA;
    if(tecla_acabou_de_ser_apertada(DIREITA) && elvira->direcao != PARA_ESQUERDA) elvira->direcao = PARA_DIREITA;
    (*cont)++;
}