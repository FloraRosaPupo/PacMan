/*---------------- File: Pirula.cpp ------------------+
|			    DESCRICAO DO ARQUIVO			      |
| 		      ETAPA 1 - Projeto Pac Man		          |
| 									                  |
| Implementado por Flora Rosa e Sabrina Guimarães 	  |
|                                    	    30/04/2023|
+-----------------------------------------------------+*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include "Pirula.h"


using namespace std;

Pirula::Pirula()
{
    pirula = NULL;
    sprite = NULL;
    controle = 1;
}
void Pirula::setPosx(int i)
{
    posx = i;
}
void Pirula::setPosy(int j)
{
    posy = j;
}

void Pirula::carregaImagem()
{
    pirula = al_load_bitmap("pilula.png");
}

int Pirula::getPosx()
{
    return posx;
}
int Pirula::getPosy()
{
    return posy;
}

void Pirula::movimentaSprite()
{
    sprite++;
}

void Pirula::imprimePirula()
{

    sprite = sprite == 3 ? 0 : sprite;
    al_draw_bitmap_region(pirula, sprite * 30, 0, 30, 30, posx * 32, posy * 32, 0);
}
Pirula::~Pirula()
{
    al_destroy_bitmap(pirula);
}