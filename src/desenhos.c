#include "desenhos.h"
#include "cobra.h"


void desenha_cabeca(cobra *elvira){
    if(elvira->segmentos[0].posix > elvira->segmentos[1].posix)
        desenha_imagem(elvira->segmentos[0].posix + 5, elvira->segmentos[0].posiy + 5, "assets/cabeca_direita.png");
    if(elvira->segmentos[0].posiy < elvira->segmentos[1].posiy)
        desenha_imagem(elvira->segmentos[0].posix + 5, elvira->segmentos[0].posiy + 5, "assets/cabeca_cima.png");
    if(elvira->segmentos[0].posix < elvira->segmentos[1].posix)
        desenha_imagem(elvira->segmentos[0].posix + 5, elvira->segmentos[0].posiy + 5, "assets/cabeca_esquerda.png");
    if(elvira->segmentos[0].posiy > elvira->segmentos[1].posiy)
        desenha_imagem(elvira->segmentos[0].posix + 5, elvira->segmentos[0].posiy + 5, "assets/cabeca_baixo.png");
}

void desenha_segmento(cobra *elvira, int i){
    if(
        elvira->segmentos[i].posix == elvira->segmentos[i-1].posix &&
        elvira->segmentos[i].posix == elvira->segmentos[i+1].posix
    ) desenha_imagem(elvira->segmentos[i].posix + 5, elvira->segmentos[i].posiy + 5, "assets/seg_v.png");
    else if(
        elvira->segmentos[i].posiy == elvira->segmentos[i-1].posiy &&
        elvira->segmentos[i].posiy == elvira->segmentos[i+1].posiy
    ) desenha_imagem(elvira->segmentos[i].posix + 5, elvira->segmentos[i].posiy + 5, "assets/seg_h.png");
    else if(
        (
            elvira->segmentos[i].posix < elvira->segmentos[i-1].posix &&
            elvira->segmentos[i].posix == elvira->segmentos[i+1].posix &&
            elvira->segmentos[i].posiy == elvira->segmentos[i-1].posiy &&
            elvira->segmentos[i].posiy > elvira->segmentos[i+1].posiy
        )||(
            elvira->segmentos[i].posix == elvira->segmentos[i-1].posix &&
            elvira->segmentos[i].posix < elvira->segmentos[i+1].posix &&
            elvira->segmentos[i].posiy > elvira->segmentos[i-1].posiy &&
            elvira->segmentos[i].posiy == elvira->segmentos[i+1].posiy
        )
    )desenha_imagem(elvira->segmentos[i].posix + 5, elvira->segmentos[i].posiy + 5, "assets/seg_ur.png");
    else if(
        (
            elvira->segmentos[i].posix == elvira->segmentos[i-1].posix &&
            elvira->segmentos[i].posix > elvira->segmentos[i+1].posix &&
            elvira->segmentos[i].posiy > elvira->segmentos[i-1].posiy &&
            elvira->segmentos[i].posiy == elvira->segmentos[i+1].posiy
        )||(
            elvira->segmentos[i].posix > elvira->segmentos[i-1].posix &&
            elvira->segmentos[i].posix == elvira->segmentos[i+1].posix &&
            elvira->segmentos[i].posiy == elvira->segmentos[i-1].posiy &&
            elvira->segmentos[i].posiy > elvira->segmentos[i+1].posiy
        )
    )desenha_imagem(elvira->segmentos[i].posix + 5, elvira->segmentos[i].posiy + 5, "assets/seg_ul.png");
    else if(
        (
            elvira->segmentos[i].posix < elvira->segmentos[i-1].posix &&
            elvira->segmentos[i].posix == elvira->segmentos[i+1].posix &&
            elvira->segmentos[i].posiy == elvira->segmentos[i-1].posiy &&
            elvira->segmentos[i].posiy < elvira->segmentos[i+1].posiy
        )||(
            elvira->segmentos[i].posix == elvira->segmentos[i-1].posix &&
            elvira->segmentos[i].posix < elvira->segmentos[i+1].posix &&
            elvira->segmentos[i].posiy < elvira->segmentos[i-1].posiy &&
            elvira->segmentos[i].posiy == elvira->segmentos[i+1].posiy
        )
    )desenha_imagem(elvira->segmentos[i].posix + 5, elvira->segmentos[i].posiy + 5, "assets/seg_dr.png");
    else if(
        (
            elvira->segmentos[i].posix == elvira->segmentos[i-1].posix &&
            elvira->segmentos[i].posix > elvira->segmentos[i+1].posix &&
            elvira->segmentos[i].posiy < elvira->segmentos[i-1].posiy &&
            elvira->segmentos[i].posiy == elvira->segmentos[i+1].posiy
        )||(
            elvira->segmentos[i].posix > elvira->segmentos[i-1].posix &&
            elvira->segmentos[i].posix == elvira->segmentos[i+1].posix &&
            elvira->segmentos[i].posiy == elvira->segmentos[i-1].posiy &&
            elvira->segmentos[i].posiy < elvira->segmentos[i+1].posiy
        )
    )desenha_imagem(elvira->segmentos[i].posix + 5, elvira->segmentos[i].posiy + 5, "assets/seg_dl.png");
}

void desenha_cauda(cobra *elvira){
    if(elvira->segmentos[(elvira->tamanho)-1].posix < elvira->segmentos[(elvira->tamanho)-2].posix)
        desenha_imagem(elvira->segmentos[(elvira->tamanho)-1].posix + 5, elvira->segmentos[(elvira->tamanho)-1].posiy + 5, "assets/cauda_direita.gif");
    if(elvira->segmentos[(elvira->tamanho)-1].posiy > elvira->segmentos[(elvira->tamanho)-2].posiy)
        desenha_imagem(elvira->segmentos[(elvira->tamanho)-1].posix + 5, elvira->segmentos[(elvira->tamanho)-1].posiy + 5, "assets/cauda_cima.gif");
    if(elvira->segmentos[(elvira->tamanho)-1].posix > elvira->segmentos[(elvira->tamanho)-2].posix)
        desenha_imagem(elvira->segmentos[(elvira->tamanho)-1].posix + 5, elvira->segmentos[(elvira->tamanho)-1].posiy + 5, "assets/cauda_esquerda.gif");
    if(elvira->segmentos[(elvira->tamanho)-1].posiy < elvira->segmentos[(elvira->tamanho)-2].posiy)
        desenha_imagem(elvira->segmentos[(elvira->tamanho)-1].posix + 5, elvira->segmentos[(elvira->tamanho)-1].posiy + 5, "assets/cauda_baixo.gif");
}