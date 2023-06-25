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

#include "Vanellope.h"

using namespace std;

Vanellope::Vanellope()
{
	vanellope[0] = NULL;
	vanellope[1] = NULL;
}

void Vanellope::carregaImagem()
{
	vanellope[0] = al_load_bitmap("vanDireita.png");
	vanellope[1] = al_load_bitmap("vanEsquerda.png");
}
void Vanellope::andaVanellope(int direcao)
{
	if (direcao == 1)
	{
		this->posy -= 1;
	}
	else if (direcao == 2)
	{
		this->posy += 1;
	}
	else if (direcao == 3) 
	{
		this->posx += 1;
	}
	else if (direcao == 4)
	{
		this->posx -= 1;
	}
}

void Vanellope::imprimeVanellope(int direx)
{
	//Caso for posição 1 e 3 , ele desenha para direita,caso contrário, esquerda.
	if (direx == 1 || direx == 3)
	{
		al_draw_bitmap_region(vanellope[0], 0, 0, 32, 32,posx * 32, posy * 32, 0);
	}
	else
	{
		al_draw_bitmap_region(vanellope[1], 0, 0, 32, 32, posx * 32, posy * 32, 0);
	}
}



Vanellope::~Vanellope()
{
	al_destroy_bitmap(vanellope[0]);
	al_destroy_bitmap(vanellope[1]);
}