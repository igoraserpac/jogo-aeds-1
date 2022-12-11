#include "telas.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "desenhos.h"

int opcao = ESCOLHE_DIFICULDADE;


void menu_iniciar(int *tela){
    cor(VERDE);
    fonte("assets/pixel.otf", 60);
    desenha_texto(150, 80, "--SNAKE--");
    cor(VERMELHO);
    if(opcao == 2){
        fonte("assets/pixel.otf", 50);
        desenha_texto(70, 210, ">");
    }
    if(opcao == RANKING){
        fonte("assets/pixel.otf", 50);
        desenha_texto(70, 250, ">");
    }
    cor(BRANCO);
    fonte("assets/pixel.otf", 50);
    desenha_texto(100, 210, "Iniciar");
    fonte("assets/pixel.otf", 50);
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
    fonte("assets/pixel.otf", 60);
    desenha_texto(150, 80, "--SNAKE--");
    cor(VERMELHO);
    if(*dif == FACIL){
        fonte("assets/pixel.otf", 50);
        desenha_texto(70, 210, ">");
    }
    if(*dif == MEDIO){
        fonte("assets/pixel.otf", 50);
        desenha_texto(70, 250, ">");
    }
    if(*dif == DIFICIL){
        fonte("assets/pixel.otf", 50);
        desenha_texto(70, 290, ">");
    }
    cor(BRANCO);
    fonte("assets/pixel.otf", 50);
    desenha_texto(100, 210, "Facil");
    fonte("assets/pixel.otf", 50);
    desenha_texto(100, 250, "Medio");
    fonte("assets/pixel.otf", 50);
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
char vet_apelido[3][2];

void recebe_nick(int *tela, char apelido[4]){
    fonte("assets/pixel.otf", 30);
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

    fonte("assets/pixel.otf", 50);
    cor(VERDE);
    desenha_texto(70 + (35*letra_sendo_alterada), 340, "^");
    cor(BRANCO);
    vet_apelido[0][0] = primeira;
    vet_apelido[1][0] = segunda;
    vet_apelido[2][0] = terceira;
    for(int i=0; i<3; i++){
        vet_apelido[i][1] = '\0';
    }
    for(int i=0; i<3; i++){
        desenha_texto(70 + (35*(i+1)), 300, vet_apelido[i]);
    }
    if(tecla_acabou_de_ser_apertada(ENTER)){
        *tela = MAIN_GAME;
    }
}

char pontos[5];

void ranking(int *tela){
    FILE *rankingg = fopen("src/ranking.csv", "r");
    int i = 0;
    cor(VERDE);
    fonte("assets/pixel.otf", 30);
    desenha_texto(200, 100, "ranking");
    cor(BRANCO);
    if(rankingg != NULL){
        while(i<5){
            char nome[4];
            char pontos[5];
            fscanf(rankingg, "%s %s\n",nome, pontos);
            fonte("assets/pixel.otf", 30);
            desenha_texto(100, 200 + (i*30), nome);
            fonte("assets/pixel.otf", 30);
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
    fonte("assets/pixel.otf", 70);
    desenha_texto(100, 200, "GAME OVER");
    fonte("assets/pixel.otf", 55);
    desenha_texto(100, 250, "pontos: ");
    fonte("assets/pixel.otf", 55);
    desenha_texto(430, 250, pontos);
    fonte("assets/pixel.otf", 15);
    desenha_texto(100, 305, "pressione espaco para jogar novamente");
    fonte("assets/pixel.otf", 15);
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


int pausado = 0;



void jogar(cobra *elvira, int lvl, int *cont, fruta *maca, int *pontuacao, int *tela){
    rankeado = 0;
    desenha_imagem(320, 240, "assets/fundo.png");
    cor(133,152,122,255);
    preenchimento(false);
    cor(15,19,20,255);
    desenha_retangulo(509, 22, 126, 130);
    preenchimento(true);
    cor(133,152,122,255);
    desenha_retangulo(509, 22, 125, 129);
    if(!pausado) dificuldade(cont, lvl, elvira, maca, pontuacao, tela);
    if(tecla_acabou_de_ser_apertada(ESC)) pausado = 1;
    if(tecla_acabou_de_ser_apertada(ESPACO)) pausado = 0;
    desenha_imagem(maca->posix+5, maca->posiy+5, "assets/pintinho.gif");
    preenchimento(false);
    cor(15,19,20,255);
    desenha_retangulo(526, 24, 92, 82);
    desenha_retangulo(528+((maca->posix - 30)/5), 26+((maca->posiy - 30)/5) ,2, 2);
    for(int i=0; i<elvira->tamanho; i++){
        cor(15,19,20,255);
        desenha_retangulo(528+((elvira->segmentos[i].posix - 30)/5),
                        26+((elvira->segmentos[i].posiy - 30)/5), 2, 2);
        if(i == 0){
            desenha_cabeca(elvira);
        }else{
            if(i == (elvira->tamanho)-1){
                desenha_cauda(elvira);
            }else{
                desenha_segmento(elvira, i);
            }
        }
    }
    snprintf(pontos, 5, "%d", *pontuacao);
    cor(PRETO);
    fonte("assets/pixel.otf", 65);
    desenha_texto(480, 220, pontos);
    cor(15,19,20,255);
    fonte("assets/pixel.otf", 20);
    desenha_texto(548, 130, "SNAKE");
    fonte("assets/pixel.otf", 100);
    if(pausado) desenha_texto(100, 100, "PAUSE");
    if(tecla_acabou_de_ser_apertada(CIMA) && elvira->segmentos[0].posiy == elvira->segmentos[1].posiy) elvira->direcao = PARA_CIMA;
    if(tecla_acabou_de_ser_apertada(BAIXO) && elvira->segmentos[0].posiy == elvira->segmentos[1].posiy) elvira->direcao = PARA_BAIXO;
    if(tecla_acabou_de_ser_apertada(ESQUERDA) && elvira->segmentos[0].posix == elvira->segmentos[1].posix) elvira->direcao = PARA_ESQUERDA;
    if(tecla_acabou_de_ser_apertada(DIREITA) && elvira->segmentos[0].posix == elvira->segmentos[1].posix) elvira->direcao = PARA_DIREITA;
    (*cont)++;
}