#ifndef COBRA
#define COBRA
#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define PARA_DIREITA 1
#define PARA_ESQUERDA 2
#define PARA_CIMA 3
#define PARA_BAIXO 4

#define TAMANHO_SEGMENTO 10

#define FACIL 18
#define MEDIO 10
#define DIFICIL 5



typedef struct{
    int posix;
    int posiy;
}segmento;

typedef struct{
    int tamanho;
    int direcao;
    segmento *segmentos;
}cobra;

typedef struct{
    int posix;
    int posiy;
}fruta;

cobra *gera_cobra();
// Aloca a cobra dinamicamente

void destroi_cobra(cobra *elvira);
// Libera a memória alocada

void dificuldade(int *cont, int lvl, cobra *elvira, fruta *maca, int *pontuacao, int *tela);
// Seta a dificuldade do jogo.


fruta gera_fruta(cobra *elvira);
// Gera a maçã em um lugar aleatório toda vez que é comida;


void andar(cobra *elvira, fruta *maca, int *pontuacao, int *tela);
// Anda com a cobra:
//     - Copia a posição da cabeça para a última posição do vetor;
//     - Soma o tamanho do segmento em px na direção do movimento;
//     - Chama @organiza_vetor().


void organiza_vetor(cobra *elvira);
// Organiza o vetor de posições dos segmentos da cobra:
//     - Salva o valor da ultima posição do vetor;
//     - Copia todas os valores para a posição seguinte;
//     - Copia o valor salvo para a posição zero.

#endif
