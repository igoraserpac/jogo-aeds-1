#include "telas.h"

void desenha_limites(){
    desenha_retangulo(0, 0, 640, 10);
    desenha_retangulo(0, 0, 10, 480);
    desenha_retangulo(0, 470, 640, 10);
    desenha_retangulo(630, 0, 10, 480);
}

void desenha_cabeca_direita(cobra *elvira){
    cor(VERDE);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy), 5, 10);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy)+3, 9, 4);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+2, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+6, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)+8, (elvira->segmentos[0].posiy)+4, 3, 2);
}

void desenha_cabeca_cima(cobra *elvira){
    cor(VERDE);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy)+5, 10, 5);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy)+1, 4, 9);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+6, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+6, (elvira->segmentos[0].posiy)+6, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)+4, (elvira->segmentos[0].posiy)-1, 2, 3);
}


void desenha_cabeca_esquerda(cobra *elvira){
    cor(VERDE);
    desenha_retangulo((elvira->segmentos[0].posix)+5, (elvira->segmentos[0].posiy), 5, 10);
    desenha_retangulo((elvira->segmentos[0].posix)+1, (elvira->segmentos[0].posiy)+3, 9, 4);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+6, (elvira->segmentos[0].posiy)+2, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+6, (elvira->segmentos[0].posiy)+6, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)-1, (elvira->segmentos[0].posiy)+4, 3, 2);
}

void desenha_cabeca_baixo(cobra *elvira){
    cor(VERDE);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy), 10, 5);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy), 4, 9);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+2, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+6, (elvira->segmentos[0].posiy)+2, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)+4, (elvira->segmentos[0].posiy)+8, 2, 3);
}


void jogar(cobra *elvira, int lvl, int *cont, fruta *maca){
    cor(BRANCO);
    desenha_limites();
    dificuldade(cont, lvl, elvira, maca);
    cor(VERDE);
    desenha_retangulo((maca->posix)+4, (maca->posiy), 3, 2);
    cor(220, 20, 60);
    desenha_retangulo((maca->posix)+2, (maca->posiy)+2, 6, 6);
    cor(BRANCO);
    for(int i=0; i<elvira->tamanho; i++){
        if(i == 0){
            if(elvira->direcao == PARA_DIREITA) desenha_cabeca_direita(elvira);
            if(elvira->direcao == PARA_CIMA) desenha_cabeca_cima(elvira);
            if(elvira->direcao == PARA_ESQUERDA) desenha_cabeca_esquerda(elvira);
            if(elvira->direcao == PARA_BAIXO) desenha_cabeca_baixo(elvira);
        }
        else{
            cor(VERDE_CLARO);
            desenha_retangulo((elvira->segmentos[i].posix)+1, (elvira->segmentos[i].posiy)+1, TAMANHO_SEGMENTO-2, TAMANHO_SEGMENTO-2);
            cor(VERDE);
            desenha_retangulo((elvira->segmentos[i].posix)+2, (elvira->segmentos[i].posiy)+2, TAMANHO_SEGMENTO-4, TAMANHO_SEGMENTO-4);
        }
        // cor(34, 139, 34, 255);
        // desenha_retangulo((elvira->segmentos[i].posix)+1, (elvira->segmentos[i].posiy)+1, TAMANHO_SEGMENTO-2, TAMANHO_SEGMENTO-2);
        // cor(0, 255, 0, 255);
        // desenha_retangulo((elvira->segmentos[i].posix)+2, (elvira->segmentos[i].posiy)+2, TAMANHO_SEGMENTO-4, TAMANHO_SEGMENTO-4);
    }
    if(tecla_acabou_de_ser_apertada(CIMA) && elvira->direcao != PARA_BAIXO) elvira->direcao = PARA_CIMA;
    if(tecla_acabou_de_ser_apertada(BAIXO) && elvira->direcao != PARA_CIMA) elvira->direcao = PARA_BAIXO;
    if(tecla_acabou_de_ser_apertada(ESQUERDA) && elvira->direcao != PARA_DIREITA) elvira->direcao = PARA_ESQUERDA;
    if(tecla_acabou_de_ser_apertada(DIREITA) && elvira->direcao != PARA_ESQUERDA) elvira->direcao = PARA_DIREITA;
    (*cont)++;
}