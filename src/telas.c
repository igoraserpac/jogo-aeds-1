#include "telas.h"

void desenha_limites(){
    desenha_retangulo(0, 0, 640, 10);
    desenha_retangulo(0, 0, 10, 480);
    desenha_retangulo(0, 470, 640, 10);
    desenha_retangulo(630, 0, 10, 480);
}

void desenha_cabeca_direita(cobra *elvira){
    cor(34,139,34,255);
    desenha_retangulo((elvira->segmentos[0].posix) + 1, (elvira->segmentos[0].posiy), 5, 10);
    desenha_retangulo((elvira->segmentos[0].posix) + 1, (elvira->segmentos[0].posiy)+3, 8, 4);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy)+2, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy)+6, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)+8, (elvira->segmentos[0].posiy)+4, 3, 2);
}

void desenha_cabeca_cima(cobra *elvira){
    cor(34,139,34,255);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy)+4, 10, 5);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy)+1, 4, 8);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+5, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+6, (elvira->segmentos[0].posiy)+5, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)+4, (elvira->segmentos[0].posiy)-1, 2, 3);
}


void desenha_cabeca_esquerda(cobra *elvira){
    cor(34,139,34,255);
    desenha_retangulo((elvira->segmentos[0].posix)+4, (elvira->segmentos[0].posiy), 5, 10);
    desenha_retangulo((elvira->segmentos[0].posix)+1, (elvira->segmentos[0].posiy)+3, 8, 4);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+5, (elvira->segmentos[0].posiy)+2, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+5, (elvira->segmentos[0].posiy)+6, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)-1, (elvira->segmentos[0].posiy)+4, 3, 2);
}

void desenha_cabeca_baixo(cobra *elvira){
    cor(34,139,34,255);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy)+1, 10, 5);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy)+1, 4, 8);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+3, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+6, (elvira->segmentos[0].posiy)+3, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)+4, (elvira->segmentos[0].posiy)+8, 2, 3);
}

void desenha_cauda_direita(cobra *elvira, int *cont){
    int posicao = (*cont)%12;
    cor(34,139,34,255);
    if(posicao >= 0 && posicao <= 3){
        ponto cauda[4];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) - 1;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 4;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) - 1;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 5;
        cauda[3][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[3][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        desenha_poligono(cauda, 4);
    }else if(posicao >= 4 && posicao <= 7){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix);
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy);
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        desenha_poligono(cauda, 3);
    }else if(posicao >= 8 && posicao <= 11){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix);
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        desenha_poligono(cauda, 3);
    }
}

void desenha_cauda_cima(cobra *elvira, int *cont){
    int posicao = (*cont)%12;
    cor(34,139,34,255);
    if(posicao >= 0 && posicao <= 3){
        ponto cauda[4];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 4;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 10;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 5;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 10;
        cauda[3][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[3][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        desenha_poligono(cauda, 4);
    }else if(posicao >= 4 && posicao <= 7){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix);
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        desenha_poligono(cauda, 3);
    }else if(posicao >= 8 && posicao <= 11){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        desenha_poligono(cauda, 3);
    }
}

void desenha_cauda_esquerda(cobra *elvira, int *cont){
    int posicao = (*cont)%12;
    cor(34,139,34,255);
    if(posicao >= 0 && posicao <= 3){
        ponto cauda[4];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 10;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 4;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 10;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 5;
        cauda[3][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[3][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        desenha_poligono(cauda, 4);
    }else if(posicao >= 4 && posicao <= 7){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy);
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        desenha_poligono(cauda, 3);
    }else if(posicao >= 8 && posicao <= 11){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        desenha_poligono(cauda, 3);
    }
}

void desenha_cauda_baixo(cobra *elvira, int *cont){
    int posicao = (*cont)%12;
    cor(34,139,34,255);
    if(posicao >= 0 && posicao <= 3){
        ponto cauda[4];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 4;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) - 1;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 5;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) - 1;
        cauda[3][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[3][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        desenha_poligono(cauda, 4);
    }else if(posicao >= 4 && posicao <= 7){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix);
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy);
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        desenha_poligono(cauda, 3);
    }else if(posicao >= 8 && posicao <= 11){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy);
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        desenha_poligono(cauda, 3);
    }
}

int opcao = NICK_NAME;


void menu_iniciar(int *tela){
    cor(VERDE);
    fonte("assets/slkscr.ttf", 60);
    desenha_texto(150, 80, "--SNAKE--");
    cor(VERMELHO);
    if(opcao == NICK_NAME){
        fonte("assets/slkscr.ttf", 50);
        desenha_texto(70, 210, ">");
    }
    if(opcao == RANKING){
        fonte("assets/slkscr.ttf", 50);
        desenha_texto(70, 250, ">");
    }
    cor(BRANCO);
    fonte("assets/slkscr.ttf", 50);
    desenha_texto(100, 210, "Iniciar");
    fonte("assets/slkscr.ttf", 50);
    desenha_texto(100, 250, "Ranking");
    if(tecla_acabou_de_ser_apertada(BAIXO) || tecla_acabou_de_ser_apertada(CIMA)){
        if(opcao == NICK_NAME) opcao = RANKING;
        else opcao = NICK_NAME;
    }
    if(tecla_acabou_de_ser_apertada(ESPACO)){
        *tela = opcao;
        opcao = 1;
    };
}

int primeira = 65;
int segunda = 65;
int terceira = 65;
int letra_sendo_alterada = 1;

void recebe_nick(int *tela){
    char string[4];
    string[0] = primeira;
    string[1] = segunda;
    string[2] = terceira;
    string[4] = '\0';

    if(letra_sendo_alterada == 1){
        if(tecla_acabou_de_ser_apertada(CIMA)) primeira++;
        if(tecla_acabou_de_ser_apertada(BAIXO)) primeira--;
        if(primeira<65) primeira = 90;
        if(primeira>90) primeira = 65;
    }
    if(letra_sendo_alterada == 2){
        if(tecla_acabou_de_ser_apertada(CIMA)) segunda++;
        if(tecla_acabou_de_ser_apertada(BAIXO)) segunda--;
        if(segunda<65) segunda = 90;
        if(segunda>90) segunda = 65;
    }
    if(letra_sendo_alterada == 3){
        if(tecla_acabou_de_ser_apertada(CIMA)) terceira++;
        if(tecla_acabou_de_ser_apertada(BAIXO)) terceira--;
        if(terceira<65) terceira = 90;
        if(terceira>90) terceira = 65;
    }
    if(tecla_acabou_de_ser_apertada(DIREITA)) letra_sendo_alterada++;
    if(tecla_acabou_de_ser_apertada(ESQUERDA)) letra_sendo_alterada--;
    if(letra_sendo_alterada == 4) letra_sendo_alterada = 1;
    if(letra_sendo_alterada == 0) letra_sendo_alterada = 3;
    desenha_texto(70 + (35*letra_sendo_alterada), 170, "-");
    desenha_texto(100, 200, string);
    if(tecla_acabou_de_ser_apertada(ENTER)) *tela = MAIN_GAME;
}



void jogar(cobra *elvira, int lvl, int *cont, fruta *maca){
    cor(255,239,219,255);
    desenha_retangulo(0, 0, 640, 480);
    cor(CINZA_ESCURO);
    desenha_limites();
    dificuldade(cont, lvl, elvira, maca);
    cor(VERDE);
    desenha_retangulo((maca->posix)+4, (maca->posiy), 3, 2);
    cor(220, 20, 60);
    desenha_retangulo((maca->posix)+2, (maca->posiy)+2, 6, 6);
    if(elvira->tamanho == 1){
        if(elvira->direcao == PARA_DIREITA) desenha_cabeca_direita(elvira);
        if(elvira->direcao == PARA_CIMA) desenha_cabeca_cima(elvira);
        if(elvira->direcao == PARA_ESQUERDA) desenha_cabeca_esquerda(elvira);
        if(elvira->direcao == PARA_BAIXO) desenha_cabeca_baixo(elvira);
    }else{
        for(int i=0; i<elvira->tamanho; i++){
            if(i == 0){
                if(elvira->segmentos[0].posix > elvira->segmentos[1].posix) desenha_cabeca_direita(elvira);
                if(elvira->segmentos[0].posiy < elvira->segmentos[1].posiy) desenha_cabeca_cima(elvira);
                if(elvira->segmentos[0].posix < elvira->segmentos[1].posix) desenha_cabeca_esquerda(elvira);
                if(elvira->segmentos[0].posiy > elvira->segmentos[1].posiy) desenha_cabeca_baixo(elvira);
            }else{
                if(i == (elvira->tamanho)-1){
                    if(elvira->segmentos[(elvira->tamanho)-1].posix < elvira->segmentos[(elvira->tamanho)-2].posix) desenha_cauda_direita(elvira, cont);
                    if(elvira->segmentos[(elvira->tamanho)-1].posiy > elvira->segmentos[(elvira->tamanho)-2].posiy) desenha_cauda_cima(elvira, cont);
                    if(elvira->segmentos[(elvira->tamanho)-1].posix > elvira->segmentos[(elvira->tamanho)-2].posix) desenha_cauda_esquerda(elvira, cont);
                    if(elvira->segmentos[(elvira->tamanho)-1].posiy < elvira->segmentos[(elvira->tamanho)-2].posiy) desenha_cauda_baixo(elvira, cont);
                }else{
                    cor(34,139,34,255);
                    desenha_retangulo((elvira->segmentos[i].posix)+1, (elvira->segmentos[i].posiy)+1, TAMANHO_SEGMENTO-2, TAMANHO_SEGMENTO-2);
                }
            }
        }
    }
    if(tecla_acabou_de_ser_apertada(CIMA) && elvira->direcao != PARA_BAIXO) elvira->direcao = PARA_CIMA;
    if(tecla_acabou_de_ser_apertada(BAIXO) && elvira->direcao != PARA_CIMA) elvira->direcao = PARA_BAIXO;
    if(tecla_acabou_de_ser_apertada(ESQUERDA) && elvira->direcao != PARA_DIREITA) elvira->direcao = PARA_ESQUERDA;
    if(tecla_acabou_de_ser_apertada(DIREITA) && elvira->direcao != PARA_ESQUERDA) elvira->direcao = PARA_DIREITA;
    (*cont)++;
}