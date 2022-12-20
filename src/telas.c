#include "telas.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "desenhos.h"

int opcao = ESCOLHE_DIFICULDADE;


void menu_iniciar(int *tela){

    // Desenhos do menu iniciar
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

    // Trecho responsável por pegar o input do usuário.
    if(tecla_acabou_de_ser_apertada(BAIXO) || tecla_acabou_de_ser_apertada(CIMA)){

        // Caso o usuário aperte para cima ou para baixo, o programa alterna entre as opções do menu.
        if(opcao == 2) opcao = RANKING;
        else opcao = 2;
    }

    if(tecla_acabou_de_ser_apertada(ENTER)){

        // Quando a tecla ENTER é apertada, o valor da variável tela é alterado para a opção selecionada pelo usuário
        *tela = opcao;
        opcao = ESCOLHE_DIFICULDADE;
    };
}


void escolhe_dificuldade(int *tela, int *dif){

    // Desenhos do menu de escolha de dificuldade
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

    // Trecho responsável por pegar o input do usuário.
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

// Variáveis responsáveis por armazenar a primeira, segunda e terceira letra do apelido do usuário.
int primeira = 65;
int segunda = 65;
int terceira = 65;

// Variável que altera qual letra está sendo alterada.
int letra_sendo_alterada = 1;

void recebe_nick(int *tela, char apelido[4]){
    fonte("assets/pixel.otf", 30);
    desenha_texto(100, 200, "escolha um apelido");

    // Inicializa o apelido como 'AAA'.
    apelido[0] = primeira;
    apelido[1] = segunda;
    apelido[2] = terceira;
    apelido[4] = '\0';

    // Confere qual letra está sendo alterada e altera ela de acordo com o input do usuário.
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

    // Altera qual letra está sendo alterada no momento.
    if(tecla_acabou_de_ser_apertada(DIREITA)) letra_sendo_alterada++;
    if(tecla_acabou_de_ser_apertada(ESQUERDA)) letra_sendo_alterada--;
    if(letra_sendo_alterada == 4) letra_sendo_alterada = 1;
    if(letra_sendo_alterada == 0) letra_sendo_alterada = 3;

    // Desenha o apelido na tela.
    fonte("assets/pixel.otf", 50);
    cor(VERDE);
    desenha_texto(80 + (25*letra_sendo_alterada), 340, "^");
    cor(BRANCO);
    desenha_texto(105, 300, apelido);

    if(tecla_acabou_de_ser_apertada(ENTER)){
        *tela = MAIN_GAME;
    }
}

// String que recebe a pontuação do usuário e é utilizada para imprimir a pontuação na tela.
char pontos[5];

void ranking(int *tela){
    // Abre o arquivo "ranking.csv" e imprime as informações dele na tela.
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

// Variáevel utilizada para saber se a pntuação do usuário já foi comparada com o ranking de melhores jogadores.
int rankeado = 0;

void rankear(char *apelido, int *pontuacao){
    // Função responsável por compara a pontuação do usuário com as outras 5 do ranking e conferir se ele está
    // entre os 5 melhores jogadores, caso esteja, reorganiza o arquivo com a pontuação dele na posição correta.
    int helper_pont;
    char helper_nick[5];
    char nick[5][6];
    int pont[6];

    // Abre o arquivo no modo de inserção, escreve na última do arquivo linha o apelido do usuário e sua
    // pontuação e fecha o arquivo.
    FILE *rkg1 = fopen("src/ranking.csv", "a");
    fprintf(rkg1, "%s %d\n", apelido, *pontuacao);
    fclose(rkg1);

    // Abre o arquivo no modo de leitura
    FILE *rkg2 = fopen("src/ranking.csv", "r");
    // Lê as informações contidas nele e armazena em dois vetores, um contendo os apelidos e outro contendo suas
    // respectivas pontuações.
    for(int i=0; i<6; i++){
        fscanf(rkg2, "%s %d\n", nick[i], &pont[i]);
    }
    // Utiliza um bubble sort para ordenar o vetor de pontuações em ordem crescente de pontos e replica todas as
    // alterações no vetor de apelidos.
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
    // Fecha o arquivo.
    fclose(rkg2);

    // Abre o arquivo no modo de escrita, escreve os 5 últimos valores dos dois vetores em ordem decrescente, ou
    // seja, do índice 5 até o índice 1, e fecha o arquivo.
    FILE *rkg3 = fopen("src/ranking.csv", "w");
    for(int i=5; i>0; i--){
        fprintf(rkg3, "%s %d\n", nick[i], pont[i]);
    }
    fclose(rkg3);

    // Altera o valor da variável rankeado para que o programa não chame novamente essa função.
    rankeado = 1;
}

void game_over(cobra *elvira, int *tela, int *pontuacao, char *apelido){
    // chama a função "rankear()" caso não tenha sido rankedo ainda.
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

    // Reinicializa os valores da cobra e a pontuação.
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

// Variável utilizada para pausar o jogo.
int pausado = 0;

void jogar(cobra *elvira, int lvl, int *cont, fruta *maca, int *pontuacao, int *tela){
    // Define como não rankeado enquanto o jogo estiver acontecendo.
    rankeado = 0;

    desenha_imagem(320, 240, "assets/fundo.png");
    desenha_imagem(maca->posix+5, maca->posiy+5, "assets/pintinho.gif");

    // Caso o jogo não estaja pausado, chama a função "dificuldade()", que é responsável por
    // definir o intervalo de tempo que a cobra leva para andar.
    if(!pausado) dificuldade(cont, lvl, elvira, maca, pontuacao, tela);

    if(tecla_acabou_de_ser_apertada(ESC)) pausado = 1;
    if(tecla_acabou_de_ser_apertada(ESPACO)) pausado = 0;

    // Desenha o minimapa.
    cor(133,152,122,255);
    preenchimento(false);
    cor(15,19,20,255);
    desenha_retangulo(509, 22, 126, 130);
    preenchimento(true);
    cor(133,152,122,255);
    desenha_retangulo(509, 22, 125, 129);
    preenchimento(false);
    cor(15,19,20,255);
    desenha_retangulo(526, 24, 92, 82);
    // Desenha o pintinho no minimapa
    desenha_retangulo(528+((maca->posix - 30)/5), 26+((maca->posiy - 30)/5) ,2, 2);
    for(int i=0; i<elvira->tamanho; i++){
        // desenha os segmentos da cobra no minimapa
        cor(15,19,20,255);
        desenha_retangulo(528+((elvira->segmentos[i].posix - 30)/5),
                        26+((elvira->segmentos[i].posiy - 30)/5), 2, 2);

        // Desenha os segmentos da cobra na tela principal de acordo com seu índice.
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

    // Mais alguns desenhos...
    snprintf(pontos, 5, "%d", *pontuacao);
    cor(PRETO);
    fonte("assets/pixel.otf", 65);
    desenha_texto(480, 220, pontos);
    cor(15,19,20,255);
    fonte("assets/pixel.otf", 20);
    desenha_texto(548, 130, "SNAKE");
    fonte("assets/pixel.otf", 100);
    if(pausado) desenha_texto(100, 100, "PAUSE");

    // Altera a direção da cobra conforme o input do usuário.
    if(tecla_acabou_de_ser_apertada(CIMA) && elvira->segmentos[0].posiy == elvira->segmentos[1].posiy) elvira->direcao = PARA_CIMA;
    if(tecla_acabou_de_ser_apertada(BAIXO) && elvira->segmentos[0].posiy == elvira->segmentos[1].posiy) elvira->direcao = PARA_BAIXO;
    if(tecla_acabou_de_ser_apertada(ESQUERDA) && elvira->segmentos[0].posix == elvira->segmentos[1].posix) elvira->direcao = PARA_ESQUERDA;
    if(tecla_acabou_de_ser_apertada(DIREITA) && elvira->segmentos[0].posix == elvira->segmentos[1].posix) elvira->direcao = PARA_DIREITA;

    (*cont)++;
}