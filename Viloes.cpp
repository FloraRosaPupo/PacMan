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
    viloes[2] = NULL;
    viloes[3] = NULL;
}


void Viloes::carregaImagem()
{
	viloes[0] = al_load_bitmap("vilao1.png");
	viloes[1] = al_load_bitmap("vilao2.png");
    viloes[2] = al_load_bitmap("vilao3.png");
    viloes[3] = al_load_bitmap("vilao4.png");
}
	

void Viloes::imprimeViloes(int direx)
{

	if (direx == 0)
	{
		al_draw_bitmap_region(viloes[0], 0, 0, 32, 32, posx * 32, posy * 32, 0);
	}
	else if(direx == 1)
	{
		al_draw_bitmap_region(viloes[1], 0, 0, 32, 32, posx * 32, posy * 32, 0);
    }
    else if (direx == 2) {
        al_draw_bitmap_region(viloes[2], 0, 0, 32, 32, posx * 32, posy * 32, 0);
    }
    else if (direx == 3) {
        al_draw_bitmap_region(viloes[3], 0, 0, 32, 32, posx * 32, posy * 32, 0);
    }
}


//poliformismo 

void Viloes::moverViloes(int matriz[20][20]) {
    int opc[4], i, j, desV;//deslocamento 
 
    for (int i = 0; i < 4; i++) {
        opc[i] = true;
    }

    j = Heranca::getPosx();
    i = Heranca::getPosy();


    //pra cima 
    if (direcao == 2 /*baixo*/ || matriz[i - 1][j] == 1)
    {
        opc[0] = false;
    }
    //pra baixo 
    if (direcao == 1 /*cima*/ || matriz[i + 1][j] == 1)
    {
        opc[1] = false;
    }

    //pra direita
    if (direcao == 4 /*esquerda*/|| matriz[i][j + 1] == 1)
    {
        opc[2] = false;

    }

    //pra esqueda 
    if (direcao == 3 /*direita*/ || matriz[i][j - 1] == 1)
    {
        opc[3] = false;
    }

    while (1) {
        desV = rand() % 4;
        if (opc[desV]) {
            direcao = desV + 1;
            break;
        }
    }


    //pra cima 
    if (direcao == 1)
    {
        Heranca::setPosy(i- 1);
    }
    //pra baixo 
    else if ((direcao == 2))
    {
        Heranca::setPosy(i + 1);
    }

    //pra direita
    else if ((direcao == 3))
    {
        Heranca::setPosx(j + 1);
    }

    //pra esquerda 
    else if ((direcao == 4))
    {
        Heranca::setPosx(j - 1);
    }

}

Viloes::~Viloes()
{
	al_destroy_bitmap(viloes[0]);
	al_destroy_bitmap(viloes[1]);
    al_destroy_bitmap(viloes[2]);
    al_destroy_bitmap(viloes[3]);
}