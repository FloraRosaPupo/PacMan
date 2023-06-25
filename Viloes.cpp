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
    int control[4];
    int s;//deslocamento 
    control[0] = true;
    control[1] = true;
    control[2] = true;
    control[3] = true;


    //Cima 
    if (matriz[Heranca::getPosy() - 1][Heranca::getPosx()] == 1 || direcao == 2)
    {
        control[0] = false;
    }
    //Baixo 
    if (matriz[Heranca::getPosy() + 1][Heranca::getPosx()] == 1 || direcao == 1)
    {
        control[1] = false;
    }

    //Direita
    if (matriz[Heranca::getPosy()][Heranca::getPosx() + 1] == 1 || direcao == 4)
    {
        control[2] = false;

    }

    //Esquerda
    if (matriz[Heranca::getPosy()][Heranca::getPosx() - 1] == 1 || direcao == 3)
    {
        control[3] = false;
    }
    do
    {
        s = rand() % 4;

    } while (!control[s]);
    direcao = s + 1;


    //Cima 
    if (direcao == 1)
    {
        Heranca::setPosy(Heranca::getPosy() - 1);
    }
    //Baixo 
    else if ((direcao == 2))
    {
        Heranca::setPosy(Heranca::getPosy() + 1);
    }

    //Esquerda
    else if ((direcao == 3))
    {
        Heranca::setPosx(Heranca::getPosx() + 1);
    }

    //Direita
    else if ((direcao == 4))
    {
        Heranca::setPosx(Heranca::getPosx() - 1);
    }
   

}

Viloes::~Viloes()
{
	al_destroy_bitmap(viloes[0]);
	al_destroy_bitmap(viloes[1]);
    al_destroy_bitmap(viloes[2]);
    al_destroy_bitmap(viloes[3]);
}