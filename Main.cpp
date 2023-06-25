/*----------------- File: main.cpp -------------------+
|			    DESCRICAO DO ARQUIVO			      |
| 		      ETAPA 3 - Projeto vanellope Man		  |
| 									                  |
| Implementado por Flora Rosa e Sabrina Guimar�es 	  |
|                                    	    09/06/2023|
+-----------------------------------------------------+*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "allegro5/allegro_acodec.h"

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include "Tijolo.h"
#include "Pirula.h"
#include "Vanellope.h"
#include "Heranca.h"
#include "Viloes.h"
#include "ViloesInteligentes.h"

using namespace std;

void criarMatriz(int matriz[20][20]);

int main()
{
    ALLEGRO_DISPLAY* display = NULL; // Tela
    ALLEGRO_BITMAP* image = NULL;    // Imagem
    ALLEGRO_FONT* fonte = NULL; //Fonte
    ALLEGRO_BITMAP* final = NULL;//Imagem Final
    ALLEGRO_BITMAP* finalPerdeu = NULL;//Imagem Final Perdeu


    if (!al_init())
    {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o Allegro",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    if (!al_init_image_addon())
    {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_init_image_addon!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    if (!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_install_keyboard!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    if (!al_init_font_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_init_font_addon",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    if (!al_init_ttf_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_init_ttf_addon",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    if (!al_install_audio()) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_install_audio",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    if (!al_init_acodec_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_init_acodec_addon",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }


    // Cria uma tela com essas dimensoes
    display = al_create_display(1080, 900);

    if (!display)
    {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o display!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    // Carrega a Imagem
    image = al_load_bitmap("fundo.png");

    if (!image)
    {
        al_show_native_message_box(display, "Error", "Error", "Falha ao carregar a imagem!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return 0;
    }
    fonte = al_load_font("vanellope.ttf", 30, 0);

    if (!fonte)
    {
        al_show_native_message_box(display, "Error", "Error", "Falha ao carregar a fonte!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return 0;
    }

    //Fundo ganhou
    final = al_load_bitmap("fundoP.png");
    if (!final)
    {
        al_show_native_message_box(display, "Error", "Error", "Falha ao carregar a imagem do final!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return 0;
    }

    //Fundo perdeu
    finalPerdeu = al_load_bitmap("fundoPerdeu.png");
    if (!finalPerdeu)
    {
        al_show_native_message_box(display, "Error", "Error", "Falha ao carregar a imagem do final perdeu!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return 0;
    }


    al_clear_to_color(al_map_rgb(255, 255, 255)); // Cor de background da tela (RGB)

   // al_draw_bitmap(image, 0, 0, 0); // Desenha a imagem

    //Variaveis
    int i, j;

    //varaveis do Tijolo
    int qtdtijolo = 0, contT = 0, t = 0;
    //variaveis da Pirula
    int contP = 0, qtdpirula = 0, p = 0;
    //variaveis do Vilao
    int v = 0;

    //variaveis da Vanellope
    int posx, posy, direcao = 0;


    //variaveis do jogo 
    bool finalJogo = false, desenha = true;
    int posAnt = 0, pontuacao = 0;


    int matriz[20][20];

    //chamando a Matriz
    criarMatriz(matriz);

    //contando a quantidade Tijolos e Pirulas
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            if (matriz[i][j] == 1) {
                contT++;
            }
            else if (matriz[i][j] == 0) {
                contP++;
            }
        }
    }

    //Criando os objetos Tijolo e Pirula
    Tijolo* tijolo = new Tijolo[contT];
    Pirula* pirula = new Pirula[contP];
    Vanellope vanellope;
    Viloes viloes[3];
    ViloesInteligentes viloesinteligentes;
  
    
    //instanciando o objeto
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            //Passando a coordenada pro objeto no plano cartesiano
            if (matriz[i][j] == 1) {
                tijolo[qtdtijolo].setPosx(j);//posicao do eixo x sao os valores equivalente as colunas da matriz
                tijolo[qtdtijolo].setPosy(i);//posicao do eixo y sao os valores equivalente as linhas da matriz
                tijolo[qtdtijolo].carregaImagem();
                qtdtijolo++;
            }
            else if (matriz[i][j] == 0) {
                pirula[qtdpirula].setPosx(j);//posicao do eixo x sao os valores equivalente as colunas da matriz
                pirula[qtdpirula].setPosy(i);//posicao do eixo y sao os valores equivalente as linhas da matriz
                pirula[qtdpirula].carregaImagem();
                qtdpirula++;
            }

            //Vanellope
            if (matriz[i][j] == 3) {
                vanellope.setPosx(j);
                vanellope.setPosy(i);
                vanellope.carregaImagem();
            }

            //Violoes
            if (matriz[i][j] == 4) {
                viloes[v].setPosx(j);
                viloes[v].setPosy(i);
                viloes[v].carregaImagem();
                v++;
            }

            if (matriz[i][j] == 5) {
                viloesinteligentes.setPosx(j);
                viloesinteligentes.setPosy(i);
                viloesinteligentes.carregaImagem();
            }

        }
    }
    
    ALLEGRO_TIMER* tempo = al_create_timer(1.0 / 6);
    ALLEGRO_EVENT_QUEUE* fila = al_create_event_queue();
    al_register_event_source(fila, al_get_timer_event_source(tempo));
    al_register_event_source(fila, al_get_keyboard_event_source());
    al_register_event_source(fila, al_get_display_event_source(display));
    al_set_timer_count(tempo, 0);
    al_start_timer(tempo);


    //Deixar o jogo em loop
    while (finalJogo == false) {
        
        //eventos do teclado
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila, &evento);

        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            exit(1);
        }

        if (evento.type == ALLEGRO_EVENT_TIMER) {
            posx = vanellope.getPosx();
            posy = vanellope.getPosy();

            //movimentando os viloes
            for (int v = 0; v < 3; v++) {  
                
                viloes[v].moverViloes(matriz);
            }
            viloesinteligentes.posPacman(posx, posy);
            viloesinteligentes.moverViloes(matriz);
            

            //pra cima
            if ((direcao == 1) && (matriz[posy - 1][posx]) != 1) {
                vanellope.setPosy(posy);
                vanellope.andaVanellope(direcao);
                posAnt = direcao;
            }
            // pra baixo
            else if ((direcao == 2) && (matriz[posy + 1][posx]) != 1)
            {
                vanellope.setPosy(posy);
                vanellope.andaVanellope(direcao);
                posAnt = direcao;
            }
            // pra direita 
            else if ((direcao == 3) && (matriz[posy][posx + 1]) != 1) {
                vanellope.setPosx(posx);
                vanellope.andaVanellope(direcao);
                posAnt = direcao;
            }
            // pra esquerda 
            else if ((direcao == 4) && (matriz[posy][posx - 1]) != 1) {
                vanellope.setPosx(posx);
                vanellope.andaVanellope(direcao);
                posAnt = direcao;
            }
            else {
                switch (posAnt)
                {
                case 1:
                    if ((matriz[posy - 1][posx]) != 1)
                    {
                        vanellope.setPosy(posy);
                        vanellope.andaVanellope(posAnt);

                    }
                    break;
                case 2:
                    if ((matriz[posy + 1][posx]) != 1)
                    {
                        vanellope.setPosy(posy);
                        vanellope.andaVanellope(posAnt);

                    }

                    break;
                case 3:
                    if ((matriz[posy][posx + 1]) != 1)
                    {
                        vanellope.setPosx(posx);
                        vanellope.andaVanellope(posAnt);

                    }
                    break;
                case 4:
                    if ((matriz[posy][posx - 1]) != 1)
                    {
                        vanellope.setPosx(posx);
                        vanellope.andaVanellope(posAnt);

                    }
                    break;
                default:
                    break;
                }
            }
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                finalJogo = true;
                exit(1);
            }
            switch (evento.keyboard.keycode)
            {

                //cima
            case ALLEGRO_KEY_UP:
                direcao = 1;
                break;

                //baixo
            case ALLEGRO_KEY_DOWN:
                direcao = 2;
                break;

                //direita
            case ALLEGRO_KEY_RIGHT:
                direcao = 3;
                break;

                //esquerda
            case ALLEGRO_KEY_LEFT:
                direcao = 4;
                break;
            }
        }

        //colisao 
        for (int p = 0; p < qtdpirula; p++)
        {
            //verifica se vai colidir com a pirula ou nao 

            if (vanellope.getPosy() == pirula[p].getPosy() && vanellope.getPosx() == pirula[p].getPosx())
            {

                if (pirula[p].controle == 1)
                {
                    pontuacao++;
                }

                pirula[p].controle = 0;
            }

        }

        //colisao 
        for (int v = 0; v < 4; v++) {
            if (v == 3) {
                if (vanellope.getPosy() == viloesinteligentes.getPosy() && vanellope.getPosx() == viloesinteligentes.getPosx()) {
                    fonte = al_load_font("vanellope.ttf", 150, 0);
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_draw_bitmap(finalPerdeu, 0, 0, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), 60, 300, 0, "PERDEU");
                    al_flip_display();
                    al_rest(9.0);
                    exit(1);
                }
            }
            
            if (vanellope.getPosy() == viloes[v].getPosy() && vanellope.getPosx() == viloes[v].getPosx()) {
                    fonte = al_load_font("vanellope.ttf", 150, 0);
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_draw_bitmap(finalPerdeu, 0, 0, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), 60, 300, 0, "PERDEU");
                    al_flip_display();
                    al_rest(9.0);
                    exit(1);
            }
            
           
        }

        

        if (pontuacao == qtdpirula)
        {
            //definicao da fonte e seu respectivo tamanho 
            fonte = al_load_font("vanellope.ttf", 150, 0);
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(final, 0, 0, 0);
            al_draw_textf(fonte, al_map_rgb(0, 0, 0), 60, 300, 0, "GANHOU");
            al_flip_display();
            al_rest(9.0);
            exit(1);
        }

        desenha = true;

        //Imprimir os objetos na tela 
        if (desenha && al_is_event_queue_empty(fila))
        {
            desenha = false;
            al_clear_to_color(al_map_rgb(255, 255, 255));
            al_draw_bitmap(image, 0, 0, 0);

            for (p = 0; p < qtdpirula; p++)
            {

                if (pirula[p].controle == 1)
                {
                    pirula[p].imprimePirula();
                }
            }

            //imprimo os tijolos na tela
            for (t = 0; t < qtdtijolo; t++) {
                tijolo[t].imprimeTijolo();
            }

            vanellope.imprimeVanellope(direcao);

            //imprimi os viloes
            for (int v = 0; v < 4; v++) {
                if (v == 3) {
                    viloesinteligentes.imprimeViloes(3);
                }
                viloes[v].imprimeViloes(v);
            }

            al_draw_textf(fonte, al_map_rgb(0, 0, 0), 810, 215, 0, "%d", pontuacao);
            al_flip_display();
        }


    }


    al_rest(30); // Tempo que a tela fica ativa (em segundos)

    al_destroy_bitmap(image);
    al_destroy_bitmap(final);
    al_destroy_bitmap(finalPerdeu);
    al_destroy_display(display);
    al_destroy_event_queue(fila);
    al_destroy_timer(tempo);
    al_destroy_font(fonte);

    //desalocando os objetos 
    delete[]pirula;
    delete[]tijolo;


    return 0;
}


void criarMatriz(int matriz[20][20]) {
    int i, j;

    int  tabuleiro[20][20] = {
         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
         1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,
         1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,1,
         1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,
         1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0,1,
         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
         1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,
         1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,
         1,0,1,0,1,0,0,0,0,0,3,0,0,0,0,1,0,1,0,1,
         1,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,
         1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
         1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,
         1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,
         1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,
         1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,
         1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,
         1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,
         1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
         1,4,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,5,1,
         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    };

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            matriz[i][j] = tabuleiro[i][j];
        }
    }
   
}