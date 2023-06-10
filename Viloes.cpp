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

	if (direx == 0)
	{
		al_draw_bitmap_region(viloes[0], 0, 0, 32, 32, posx * 32, posy * 32, 0);
	}
	else if(direx == 1)
	{
		al_draw_bitmap_region(viloes[1], 0, 0, 32, 32, posx * 32, posy * 32, 0);
	}
	else if (direx == 2) {
		al_draw_bitmap_region(viloes[0], 0, 0, 32, 32, posx * 32, posy * 32, 0);
	}
	else {
		al_draw_bitmap_region(viloes[1], 0, 0, 32, 32, posx * 32, posy * 32, 0);
	}
}

Viloes::~Viloes()
{
	al_destroy_bitmap(viloes[0]);
	al_destroy_bitmap(viloes[1]);
}