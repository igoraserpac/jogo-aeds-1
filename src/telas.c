#include "telas.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "desenhos.h"

void desenha_limites(){
    desenha_retangulo(20, 20, 460, 8);
    desenha_retangulo(20, 20, 8, 410);
    desenha_retangulo(20, 422, 460, 8);
    desenha_retangulo(472, 20, 8, 410);
}

void desenha_cabeca_direita(cobra *elvira){
    cor(VERDE);
    desenha_retangulo((elvira->segmentos[0].posix) + 1, (elvira->segmentos[0].posiy), 5, 10);
    desenha_retangulo((elvira->segmentos[0].posix) + 1, (elvira->segmentos[0].posiy)+3, 8, 4);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+2, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+6, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)+8, (elvira->segmentos[0].posiy)+4, 3, 1);
    preenchimento(false);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix) + 1, (elvira->segmentos[0].posiy), 5, 10);
    desenha_retangulo((elvira->segmentos[0].posix) + 6, (elvira->segmentos[0].posiy)+3, 3, 4);

}

void desenha_cabeca_cima(cobra *elvira){
    cor(VERDE);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy)+4, 10, 5);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy)+1, 4, 8);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+5, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+6, (elvira->segmentos[0].posiy)+5, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)+4, (elvira->segmentos[0].posiy)-1, 1, 3);
    preenchimento(false);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy)+4, 10, 5);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy)+1, 4, 3);
}


void desenha_cabeca_esquerda(cobra *elvira){
    cor(VERDE);
    desenha_retangulo((elvira->segmentos[0].posix)+4, (elvira->segmentos[0].posiy), 5, 10);
    desenha_retangulo((elvira->segmentos[0].posix)+1, (elvira->segmentos[0].posiy)+3, 8, 4);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+5, (elvira->segmentos[0].posiy)+2, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+5, (elvira->segmentos[0].posiy)+6, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)-1, (elvira->segmentos[0].posiy)+4, 3, 1);
    preenchimento(false);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+4, (elvira->segmentos[0].posiy), 5, 10);
    desenha_retangulo((elvira->segmentos[0].posix)+1, (elvira->segmentos[0].posiy)+3, 3, 4);
}

void desenha_cabeca_baixo(cobra *elvira){
    cor(VERDE);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy)+1, 10, 5);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy)+1, 4, 8);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix)+2, (elvira->segmentos[0].posiy)+2, 2, 2);
    desenha_retangulo((elvira->segmentos[0].posix)+6, (elvira->segmentos[0].posiy)+2, 2, 2);
    cor(VERMELHO);
    desenha_retangulo((elvira->segmentos[0].posix)+4, (elvira->segmentos[0].posiy)+8, 1, 3);
    preenchimento(false);
    cor(PRETO);
    desenha_retangulo((elvira->segmentos[0].posix), (elvira->segmentos[0].posiy)+1, 10, 5);
    desenha_retangulo((elvira->segmentos[0].posix)+3, (elvira->segmentos[0].posiy)+6, 4, 3);
}

void desenha_cauda_direita(cobra *elvira, int *cont){
    int posicao = (*cont)%12;
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
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 4);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 4);
    }else if(posicao >= 4 && posicao <= 7){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix);
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy);
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 3);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 3);
    }else if(posicao >= 8 && posicao <= 11){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix);
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 3);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 3);
    }
}

void desenha_cauda_cima(cobra *elvira, int *cont){
    int posicao = (*cont)%12;
    cor(VERDE);
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
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 4);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 4);
    }else if(posicao >= 4 && posicao <= 7){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix);
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 3);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 3);
    }else if(posicao >= 8 && posicao <= 11){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 3);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 3);
    }
}

void desenha_cauda_esquerda(cobra *elvira, int *cont){
    int posicao = (*cont)%12;
    cor(VERDE);
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
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 4);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 4);
    }else if(posicao >= 4 && posicao <= 7){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy);
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 3);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 3);
    }else if(posicao >= 8 && posicao <= 11){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 1;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 3);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 3);
    }
}

void desenha_cauda_baixo(cobra *elvira, int *cont){
    int posicao = (*cont)%12;
    cor(VERDE);
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
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 4);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 4);
    }else if(posicao >= 4 && posicao <= 7){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix);
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy);
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 3);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 3);
    }else if(posicao >= 8 && posicao <= 11){
        ponto cauda[3];
        cauda[0][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 1;
        cauda[0][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cauda[1][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[1][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy);
        cauda[2][0] = (elvira->segmentos[(elvira->tamanho)-1].posix) + 9;
        cauda[2][1] = (elvira->segmentos[(elvira->tamanho)-1].posiy) + 9;
        cor(VERDE);
        preenchimento(true);
        desenha_poligono(cauda, 3);
        cor(PRETO);
        preenchimento(false);
        desenha_poligono(cauda, 3);
    }
}

int opcao = ESCOLHE_DIFICULDADE;


void menu_iniciar(int *tela){
    cor(VERDE);
    fonte("assets/slkscr.ttf", 60);
    desenha_texto(150, 80, "--SNAKE--");
    cor(VERMELHO);
    if(opcao == 2){
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
        if(opcao == 2) opcao = RANKING;
        else opcao = 2;
    }
    if(tecla_acabou_de_ser_apertada(ENTER)){
        *tela = opcao;
        opcao = ESCOLHE_DIFICULDADE;
    };
}


void escolhe_dificuldade(int *tela, int *dif){
    cor(VERDE);
    fonte("assets/slkscr.ttf", 60);
    desenha_texto(150, 80, "--SNAKE--");
    cor(VERMELHO);
    if(*dif == FACIL){
        fonte("assets/slkscr.ttf", 50);
        desenha_texto(70, 210, ">");
    }
    if(*dif == MEDIO){
        fonte("assets/slkscr.ttf", 50);
        desenha_texto(70, 250, ">");
    }
    if(*dif == DIFICIL){
        fonte("assets/slkscr.ttf", 50);
        desenha_texto(70, 290, ">");
    }
    cor(BRANCO);
    fonte("assets/slkscr.ttf", 50);
    desenha_texto(100, 210, "Facil");
    fonte("assets/slkscr.ttf", 50);
    desenha_texto(100, 250, "Medio");
    fonte("assets/slkscr.ttf", 50);
    desenha_texto(100, 290, "Dificil");
    if(tecla_acabou_de_ser_apertada(BAIXO)){
        if(*dif == FACIL) *dif = MEDIO;
        else if(*dif == MEDIO) *dif = DIFICIL;
        else if(*dif == DIFICIL) *dif = FACIL;
    }
    if(tecla_acabou_de_ser_apertada(CIMA)){
        if(*dif == FACIL) *dif = DIFICIL;
        else if(*dif == MEDIO) *dif = FACIL;
        else if(*dif == DIFICIL) *dif = MEDIO;
    }
    if(tecla_acabou_de_ser_apertada(ESPACO)){
        *tela = 3;
    }
}


int primeira = 65;
int segunda = 65;
int terceira = 65;
int letra_sendo_alterada = 1;

void recebe_nick(int *tela, char apelido[4]){
    fonte("assets/slkscr.ttf", 30);
    desenha_texto(100, 200, "escolha um apelido");
    apelido[0] = primeira;
    apelido[1] = segunda;
    apelido[2] = terceira;
    apelido[4] = '\0';
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

    fonte("assets/slkscr.ttf", 50);
    cor(VERDE);
    desenha_texto(70 + (35*letra_sendo_alterada), 280, "-");
    cor(BRANCO);
    desenha_texto(100, 300, apelido);
    if(tecla_acabou_de_ser_apertada(ENTER)){
        *tela = MAIN_GAME;
    }
}

char pontos[5];

void ranking(int *tela){
    FILE *rankingg = fopen("src/ranking.csv", "r");
    int i = 0;
    cor(VERDE);
    fonte("assets/slkscr.ttf", 30);
    desenha_texto(200, 100, "ranking");
    cor(BRANCO);
    if(rankingg != NULL){
        while(i<5){
            char nome[4];
            char pontos[5];
            fscanf(rankingg, "%s %s\n",nome, pontos);
            fonte("assets/slkscr.ttf", 30);
            desenha_texto(100, 200 + (i*30), nome);
            fonte("assets/slkscr.ttf", 30);
            desenha_texto(200, 200 + (i*30), pontos);
            i++;
        }
        fclose(rankingg);
    }
    if(tecla_acabou_de_ser_apertada(ESC)) *tela = START_MENU;
}

int rankeado = 0;

void rankear(char *apelido, int *pontuacao){
    int helper_pont;
    char helper_nick[5];
    char nick[5][6];
    int pont[6];
    FILE *rkg1 = fopen("src/ranking.csv", "a");
    fprintf(rkg1, "%s %d\n", apelido, *pontuacao);
    fclose(rkg1);
    FILE *rkg2 = fopen("src/ranking.csv", "r");
    for(int i=0; i<6; i++){
        fscanf(rkg2, "%s %d\n", nick[i], &pont[i]);
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5-i; j++){
            if(pont[j]>pont[j+1]){
                helper_pont = pont[j];
                strcpy(helper_nick, nick[j]);
                pont[j] = pont[j+1];
                strcpy(nick[j], nick[j+1]);
                pont[j+1] = helper_pont;
                strcpy(nick[j+1], helper_nick);
            }
        }
    }
    fclose(rkg2);
    FILE *rkg3 = fopen("src/ranking.csv", "w");
    for(int i=5; i>0; i--){
        fprintf(rkg3, "%s %d\n", nick[i], pont[i]);
    }
    fclose(rkg3);
    rankeado = 1;
}


void game_over(cobra *elvira, int *tela, int *pontuacao, char *apelido){
    if(!rankeado) rankear(apelido, pontuacao);
    snprintf(pontos, 5, "%d", *pontuacao);
    fonte("assets/slkscr.ttf", 70);
    desenha_texto(100, 200, "GAME OVER");
    fonte("assets/slkscr.ttf", 55);
    desenha_texto(100, 250, "pontos: ");
    fonte("assets/slkscr.ttf", 55);
    desenha_texto(430, 250, pontos);
    fonte("assets/slkscr.ttf", 15);
    desenha_texto(100, 305, "pressione espaco para jogar novamente");
    fonte("assets/slkscr.ttf", 15);
    desenha_texto(100, 325, "ou ESC para voltar ao menu iniciar");
    if(tecla_acabou_de_ser_apertada(ESPACO)){
        *pontuacao = 0;
        elvira->tamanho = 2;
        elvira->direcao = PARA_DIREITA;
        segmento s[3072];
        for(int i=0; i<elvira->tamanho; i++){
            s[i].posix = 200 - (TAMANHO_SEGMENTO * i);
            s[i].posiy = 200;
            elvira->segmentos[i] = s[i];
        }
        *tela = MAIN_GAME;
    }else if(tecla_acabou_de_ser_apertada(ESC)){
        *pontuacao = 0;
        elvira->tamanho = 2;
        elvira->direcao = PARA_DIREITA;
        segmento s[3072];
        for(int i=0; i<elvira->tamanho; i++){
            s[i].posix = 200 - (TAMANHO_SEGMENTO * i);
            s[i].posiy = 200;
            elvira->segmentos[i] = s[i];
        }
        *tela = START_MENU;
    }
}



void jogar(cobra *elvira, int lvl, int *cont, fruta *maca, int *pontuacao, int *tela){
    rankeado = 0;
    cor(244,164,96,255);
    desenha_retangulo(0, 0, 640, 480);
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            desenha_imagem(75+i*100, 75+j*100, "assets/campo.png");
        }
    }
    for(int i=0; i<4; i++) desenha_imagem(435, 75+i*100, "assets/campo.png");
    desenha_retangulo(20, 20, 8, 8);
    cor(MARROM);
    desenha_limites();
    dificuldade(cont, lvl, elvira, maca, pontuacao, tela);
    desenha_imagem(maca->posix+5, maca->posiy+5, "assets/pintinho.gif");
    if(elvira->tamanho == 1){
        if(elvira->direcao == PARA_DIREITA) desenha_cabeca_direita(elvira);
        if(elvira->direcao == PARA_CIMA) desenha_cabeca_cima(elvira);
        if(elvira->direcao == PARA_ESQUERDA) desenha_cabeca_esquerda(elvira);
        if(elvira->direcao == PARA_BAIXO) desenha_cabeca_baixo(elvira);
    }else{
        for(int i=0; i<elvira->tamanho; i++){
            if(i == 0){
                // if(elvira->segmentos[0].posix > elvira->segmentos[1].posix) desenha_cabeca_direita(elvira);
                // if(elvira->segmentos[0].posiy < elvira->segmentos[1].posiy) desenha_cabeca_cima(elvira);
                // if(elvira->segmentos[0].posix < elvira->segmentos[1].posix) desenha_cabeca_esquerda(elvira);
                // if(elvira->segmentos[0].posiy > elvira->segmentos[1].posiy) desenha_cabeca_baixo(elvira);
                desenha_cabeca(elvira);
            }else{
                if(i == (elvira->tamanho)-1){
                    desenha_cauda(elvira);
                    // if(elvira->segmentos[(elvira->tamanho)-1].posix < elvira->segmentos[(elvira->tamanho)-2].posix) desenha_cauda_direita(elvira, cont);
                    // if(elvira->segmentos[(elvira->tamanho)-1].posiy > elvira->segmentos[(elvira->tamanho)-2].posiy) desenha_cauda_cima(elvira, cont);
                    // if(elvira->segmentos[(elvira->tamanho)-1].posix > elvira->segmentos[(elvira->tamanho)-2].posix) desenha_cauda_esquerda(elvira, cont);
                    // if(elvira->segmentos[(elvira->tamanho)-1].posiy < elvira->segmentos[(elvira->tamanho)-2].posiy) desenha_cauda_baixo(elvira, cont);
                }else{
                    desenha_segmento(elvira, i);
                    // preenchimento(true);
                    // cor(VERDE);
                    // desenha_retangulo((elvira->segmentos[i].posix)+1, (elvira->segmentos[i].posiy)+1, TAMANHO_SEGMENTO-2, TAMANHO_SEGMENTO-2);
                    // preenchimento(false);
                    // cor(PRETO);
                    // desenha_retangulo((elvira->segmentos[i].posix)+1, (elvira->segmentos[i].posiy)+1, TAMANHO_SEGMENTO-2, TAMANHO_SEGMENTO-2);
                }
            }
        }
    }
    snprintf(pontos, 5, "%d", *pontuacao);
    cor(PRETO);
    fonte("assets/slkscr.ttf", 70);
    desenha_texto(530, 150, pontos);
    if(tecla_acabou_de_ser_apertada(CIMA) && elvira->segmentos[0].posiy == elvira->segmentos[1].posiy) elvira->direcao = PARA_CIMA;
    if(tecla_acabou_de_ser_apertada(BAIXO) && elvira->segmentos[0].posiy == elvira->segmentos[1].posiy) elvira->direcao = PARA_BAIXO;
    if(tecla_acabou_de_ser_apertada(ESQUERDA) && elvira->segmentos[0].posix == elvira->segmentos[1].posix) elvira->direcao = PARA_ESQUERDA;
    if(tecla_acabou_de_ser_apertada(DIREITA) && elvira->segmentos[0].posix == elvira->segmentos[1].posix) elvira->direcao = PARA_DIREITA;
    (*cont)++;
}