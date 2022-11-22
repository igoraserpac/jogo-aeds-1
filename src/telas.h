#ifndef TELAS
#define TELAS
#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "cobra.h"

#define START_MENU 1
#define ESCOLHE_DIFICULDADE 2
#define NICK_NAME 3
#define MAIN_GAME 4
#define GAME_OVER 5
#define RANKING 6

void game_over(cobra *elvira, int *tela, int *pontuacao);

void escolhe_dificuldade(int *tela, int *dif);

void menu_iniciar(int *tela);

void recebe_nick(int *tela, char apelido[4]);

void jogar(cobra *elvira, int lvl, int *cont, fruta *maca, int *pontuacao, int *tela);

void ranking(int *tela);

#endif