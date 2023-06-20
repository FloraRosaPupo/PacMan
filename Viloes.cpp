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
#include <stdio.h>

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include "Viloes.h"

using namespace std;

Viloes::Viloes()
{
	viloes[0] = NULL;
	viloes[1] = NULL;
}

void Viloes::carregaImagem()
{
	viloes[0] = al_load_bitmap("vilao1.png");
	viloes[1] = al_load_bitmap("vilao2.png");
}
	

void Viloes::imprimeViloes(int direx)
{

	if (direx == 0 || direx == 2)
	{
		al_draw_bitmap_region(viloes[0], 0, 0, 32, 32, posx * 32, posy * 32, 0);
	}
	else//direx ==1 || direx == 4 
	{
		al_draw_bitmap_region(viloes[1], 0, 0, 32, 32, posx * 32, posy * 32, 0);
	}
}


//poliformismo 

void Viloes::moverViloes(int matriz[20][20]) {

    int x, y, dirVilao, desVilao;

    //poliformismo
    x = Heranca::posx;
    y = Heranca::posy;

    //Pra cima
    if (/*(dirVilao == 1) && */ matriz[y - 1][x] != 1) {
        /*viloesPy[v] -= 1;
        viloes[v].setPosy(viloesPy[v]);

        //passando uma direcao aleatoria
        if (matriz[viloesPy[v] - 1][viloesPx[v]] == 1) {
            dirVilao = rand() % 4;
            printf("Entrou aqui %i\n", dirVilao);//teste
        }*/

    }//Pra baixo
    else if (/*(dirVilao == 2) && */matriz[y + 1][x] != 1) {
        viloesPy[v] += 1;
        viloes[v].setPosy(viloesPy[v]);

        //passando uma direcao aleatoria
        if (matriz[viloesPy[v] + 1][viloesPx[v]] == 1) {
            dirVilao = rand() % 4;
            while (dirVilao == 2) {
                dirVilao = rand() % 4;
                //  printf("Entrou aqui %i\n", dirVilao);//teste
            }
        }
    }//Pra Direita
    else if (/*(dirVilao == 3) &&*/ matriz[y][x + 1] != 1) {
        viloesPx[v] += 1;
        viloes[v].setPosx(viloesPx[v]);

        if (matriz[viloesPy[v]][viloesPx[v] + 1] == 1) {
            dirVilao = rand() % 4;
            while (dirVilao == 3) {
                dirVilao = rand() % 4;
                //printf("Entrou aqui %i\n", dirVilao);//teste
            }
        }
    }//Pra Esquerda
    else if (/*(dirVilao == 3) &&*/ matriz[y][x - 1] != 1) {
        viloesPx[v] -= 1;
        viloes[v].setPosx(viloesPx[v]);

        if (matriz[viloesPy[v]][viloesPx[v] - 1] == 1) {
            dirVilao = rand() % 4;
            while (dirVilao == 3) {
                dirVilao = rand() % 4;
                // printf("Entrou aqui %i\n", dirVilao);//teste
            }
        }
}

Viloes::~Viloes()
{
	al_destroy_bitmap(viloes[0]);
	al_destroy_bitmap(viloes[1]);
}