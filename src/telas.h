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
#define NICK_NAME 2
#define MAIN_GAME 3
#define GAME_OVER 4
#define RANKING 5

void menu_iniciar(int *tela);

void recebe_nick(int *tela);

void jogar(cobra *elvira, int lvl, int *cont, fruta *maca);

#endif