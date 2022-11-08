#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

int desenha_cabeca(int x, int y){
    desenha_retangulo(x, y, 10, 10);
}


int main() {
    abre_janela(640, 480);
    toca_som_em_loop("assets/awesomeness.wav");

    double fator_zoom = 1;

    int x_cabeca = 1;
    int y_cabeca = 1;
    int sobe = 0;
    int desce = 0;
    int direita = 1;
    int esquerda = 0;
    int ult_apertada = -1;
    while (janela_esta_aberta()) {

        long int i = 0;

        if(ult_apertada == CIMA && !desce){
            sobe = 1;
            desce = 0;
            direita = 0;
            esquerda = 0;
        }
        if(ult_apertada == BAIXO && !sobe){
            sobe = 0;
            desce = 1;
            direita = 0;
            esquerda = 0;
        }
        if(ult_apertada == DIREITA && ! esquerda){
            sobe = 0;
            desce = 0;
            direita = 1;
            esquerda = 0;
        }
        if(ult_apertada == ESQUERDA  && !direita){
            sobe = 0;
            desce = 0;
            direita = 0;
            esquerda = 1;
        }

        if(esquerda) x_cabeca -= 10;
        if(direita) x_cabeca += 10;
        if(sobe) y_cabeca -= 10;
        if(desce) y_cabeca += 10;
        if(x_cabeca > 640) x_cabeca = 0;
        if(y_cabeca > 480) y_cabeca = 0;
        if(x_cabeca < 0) x_cabeca = 640;
        if(y_cabeca < 0) y_cabeca = 480;
        desenha_cabeca(x_cabeca, y_cabeca);

        ult_apertada = -1;


        while(i<30000000){
            if(tecla_acabou_de_ser_apertada('W')){
                ult_apertada = CIMA;
                break;
            }
            if(tecla_acabou_de_ser_apertada('S')) {
                ult_apertada = BAIXO;
                break;
            }
            if(tecla_acabou_de_ser_apertada('A')) {
                ult_apertada = ESQUERDA;
                break;
            }
            if(tecla_acabou_de_ser_apertada('D')) {
                ult_apertada = DIREITA;
                break;
                }
            i++;
        }
        printf("%d\n", ult_apertada);
        fflush(stdin);


        // cor(AMARELO);
        // preenchimento(false);

        // desenha_retangulo(0, 0, 320, 240);

        // zoom(mouse_x, mouse_y, fator_zoom);
        // desenha_imagem(mouse_x, mouse_y, "assets/tux.png");
        // reseta_zoom();

        // cor(VERMELHO);
        // preenchimento(true);
        // desenha_circulo(200, 200, 10);

        // fonte("assets/ubuntu.ttf", 32);
        // desenha_texto(20, 20, "Esse é um teste!");

        // desenha_imagem(320, 240, "assets/guy.gif");

        // if (tecla_acabou_de_ser_apertada(ESC))
        //     janela_deve_fechar();

        // if (botao_mouse_acabou_de_ser_apertado(BOTAO_ESQUERDO))
        //     toca_som("assets/jump.wav");

        // fator_zoom += roda_do_mouse * 0.1;
    }
    fecha_janela();

}