#ifndef DESENHOS
#define DESENHOS

#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "cobra.h"

void desenha_cauda(cobra *elvira);

void desenha_segmento(cobra *elvira, int posicao);

void desenha_cabeca(cobra *elvira);

#endif