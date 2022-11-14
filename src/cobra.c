#include "cobra.h"
#include "telas.h"

fruta gera_fruta(cobra *elvira){
    srand(time(NULL));
    int x = (rand()%611)+10;
    int y = (rand()%451)+10;
    for(int i=0; i<elvira->tamanho; i++){
        if(x == elvira->segmentos[i].posix && y == elvira->segmentos[i].posiy) return gera_fruta(elvira);
    }
    fruta maca;
    maca.posix = x - x%TAMANHO_SEGMENTO;
    maca.posiy = y - y%TAMANHO_SEGMENTO;
    return maca;
}



int colidiu(cobra *elvira){
    for(int i=1; i<elvira->tamanho; i++){
        if(elvira->segmentos[0].posix == elvira->segmentos[i].posix && elvira->segmentos[0].posiy == elvira->segmentos[i].posiy) return 1;
    }
    if(elvira->segmentos[0].posix >= 630 || elvira->segmentos[0].posiy >=470) return 1;
    if(elvira->segmentos[0].posix <= 0 || elvira->segmentos[0].posiy <= 0) return 1;
    return 0;
}

int comeu(cobra *elvira, fruta *maca){
    if(elvira->segmentos[0].posix == maca->posix && elvira->segmentos[0].posiy == maca->posiy) return 1;
    return 0;
}


void dificuldade(int *cont, int lvl, cobra *elvira, fruta *maca){
    if(*cont % lvl == 0){
        andar(elvira, maca);
        *cont = 0;
    }
}

void organiza_vetor(cobra *elvira){
    segmento cauda = (elvira->segmentos)[elvira->tamanho-1];
    for(int i=(elvira->tamanho)-1; i>0; i--){
        (elvira->segmentos)[i] = (elvira->segmentos)[i-1];
    }
    (elvira->segmentos)[0] = cauda;
}

void cresce(cobra *elvira){
    elvira->tamanho++;
    elvira->segmentos[(elvira->tamanho)-1] = elvira->segmentos[(elvira->tamanho)-2];
}

void andar(cobra *elvira, fruta *maca){
    switch (elvira->direcao){
    case PARA_DIREITA:
        (elvira->segmentos)[(elvira->tamanho)-1].posix = (elvira->segmentos)[0].posix + TAMANHO_SEGMENTO;
        (elvira->segmentos)[(elvira->tamanho)-1].posiy = (elvira->segmentos)[0].posiy;
        organiza_vetor(elvira);
        if(colidiu(elvira)) fecha_janela();
        if(comeu(elvira, maca)){
            cresce(elvira);
            *maca = gera_fruta(elvira);
        }
        break;
    case PARA_ESQUERDA:
        (elvira->segmentos)[(elvira->tamanho)-1].posix = (elvira->segmentos)[0].posix - TAMANHO_SEGMENTO;
        (elvira->segmentos)[(elvira->tamanho)-1].posiy = (elvira->segmentos)[0].posiy;
        organiza_vetor(elvira);
        if(colidiu(elvira)) fecha_janela();
        if(comeu(elvira, maca)){
            cresce(elvira);
            *maca = gera_fruta(elvira);
        }
        break;
    case PARA_CIMA:
        (elvira->segmentos)[(elvira->tamanho)-1].posix = (elvira->segmentos)[0].posix;
        (elvira->segmentos)[(elvira->tamanho)-1].posiy = (elvira->segmentos)[0].posiy - TAMANHO_SEGMENTO;
        organiza_vetor(elvira);
        if(colidiu(elvira)) fecha_janela();
        if(comeu(elvira, maca)){
            cresce(elvira);
            *maca = gera_fruta(elvira);
        }
        break;
    case PARA_BAIXO:
        (elvira->segmentos)[(elvira->tamanho)-1].posix = (elvira->segmentos)[0].posix;
        (elvira->segmentos)[(elvira->tamanho)-1].posiy = (elvira->segmentos)[0].posiy + TAMANHO_SEGMENTO;
        organiza_vetor(elvira);
        if(colidiu(elvira)) fecha_janela();
        if(comeu(elvira, maca)){
            cresce(elvira);
            *maca = gera_fruta(elvira);
        }
        break;
    default:
        break;
    }
}