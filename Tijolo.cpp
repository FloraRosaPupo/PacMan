/*---------------- File: Tijolo.cpp ------------------+
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

#include "Tijolo.h"

using namespace std;

Tijolo::Tijolo()
{
    tijolo = NULL;
}

void Tijolo::carregaImagem()
{
    tijolo = al_load_bitmap("tijolo.png");
}

void Tijolo::setPosx(int i)
{
    posx = i;
}
void Tijolo::setPosy(int j)
{
    posy = j;
}

void Tijolo::imprimeTijolo()
{
    al_draw_bitmap(tijolo, posx * 32, posy* 32, 0);
}

Tijolo::~Tijolo()
{
    al_destroy_bitmap(tijolo);
}
