#include "cobra.h"
#include "telas.h"

int confere_segmentos_para_fruta(fruta *maca, cobra *elvira){
    for(int i=0; i<elvira->tamanho; i++){
        if(maca->posix == elvira->segmentos[i].posix && maca->posiy == elvira->segmentos[i].posiy) return 1;
    }
    return 0;
}


fruta gera_fruta(cobra *elvira){
    srand(time(NULL));
    int x = (rand()%429)+30;
    int y = (rand()%379)+30;
    fruta maca;
    maca.posix = x - x%TAMANHO_SEGMENTO;
    maca.posiy = y - y%TAMANHO_SEGMENTO;
    while(confere_segmentos_para_fruta(&maca, elvira)){
        x = (rand()%429)+30;
        y = (rand()%379)+30;
        maca.posix = x - x%TAMANHO_SEGMENTO;
        maca.posiy = y - y%TAMANHO_SEGMENTO;
    }
    return maca;
}



int colidiu(cobra *elvira){
    for(int i=1; i<elvira->tamanho; i++){
        if(elvira->segmentos[0].posix == elvira->segmentos[i].posix && elvira->segmentos[0].posiy == elvira->segmentos[i].posiy) return 1;
    }
    if(elvira->segmentos[0].posix > 460 || elvira->segmentos[0].posiy > 410) return 1;
    if(elvira->segmentos[0].posix < 30 || elvira->segmentos[0].posiy < 30) return 1;
    return 0;
}

int comeu(cobra *elvira, fruta *maca){
    if(elvira->segmentos[0].posix == maca->posix && elvira->segmentos[0].posiy == maca->posiy) return 1;
    return 0;
}


void dificuldade(int *cont, int lvl, cobra *elvira, fruta *maca, int *pontuacao, int *tela){
    if(*cont % lvl == 0){
        andar(elvira, maca, pontuacao, tela);
    }
    if(*cont >= 180) *cont = 0;
}

void organiza_vetor(cobra *elvira){
    segmento cauda = (elvira->segmentos)[elvira->tamanho-1];
    for(int i=(elvira->tamanho)-1; i>0; i--){
        (elvira->segmentos)[i] = (elvira->segmentos)[i-1];
    }
    (elvira->segmentos)[0] = cauda;
}

void cresce(cobra *elvira){
    toca_som("assets/slime8.wav");
    elvira->tamanho++;
    elvira->segmentos[(elvira->tamanho)-1] = elvira->segmentos[(elvira->tamanho)-2];
}

void andar(cobra *elvira, fruta *maca, int *pontuacao, int *tela){
    switch (elvira->direcao){
    case PARA_DIREITA:
        (elvira->segmentos)[(elvira->tamanho)-1].posix = (elvira->segmentos)[0].posix + TAMANHO_SEGMENTO;
        (elvira->segmentos)[(elvira->tamanho)-1].posiy = (elvira->segmentos)[0].posiy;
        organiza_vetor(elvira);
        if(colidiu(elvira)){
            *tela = GAME_OVER;
        };
        if(comeu(elvira, maca)){
            (*pontuacao)++;
            cresce(elvira);
            *maca = gera_fruta(elvira);
        }
        break;
    case PARA_ESQUERDA:
        (elvira->segmentos)[(elvira->tamanho)-1].posix = (elvira->segmentos)[0].posix - TAMANHO_SEGMENTO;
        (elvira->segmentos)[(elvira->tamanho)-1].posiy = (elvira->segmentos)[0].posiy;
        organiza_vetor(elvira);
        if(colidiu(elvira)){
            *tela = GAME_OVER;
        };
        if(comeu(elvira, maca)){
            (*pontuacao)++;
            cresce(elvira);
            *maca = gera_fruta(elvira);
        }
        break;
    case PARA_CIMA:
        (elvira->segmentos)[(elvira->tamanho)-1].posix = (elvira->segmentos)[0].posix;
        (elvira->segmentos)[(elvira->tamanho)-1].posiy = (elvira->segmentos)[0].posiy - TAMANHO_SEGMENTO;
        organiza_vetor(elvira);
        if(colidiu(elvira)){
            *tela = GAME_OVER;
        };
        if(comeu(elvira, maca)){
            (*pontuacao)++;
            cresce(elvira);
            *maca = gera_fruta(elvira);
        }
        break;
    case PARA_BAIXO:
        (elvira->segmentos)[(elvira->tamanho)-1].posix = (elvira->segmentos)[0].posix;
        (elvira->segmentos)[(elvira->tamanho)-1].posiy = (elvira->segmentos)[0].posiy + TAMANHO_SEGMENTO;
        organiza_vetor(elvira);
        if(colidiu(elvira)){
            *tela = GAME_OVER;
        };
        if(comeu(elvira, maca)){
            (*pontuacao)++;
            cresce(elvira);
            *maca = gera_fruta(elvira);
        }
        break;
    default:
        break;
    }
}