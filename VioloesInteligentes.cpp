/*----------------- File: main.cpp -------------------+
|			    DESCRICAO DO ARQUIVO			      |
| 		      ETAPA 4 - Projeto vanellope Man		  |
| 									                  |
| Implementado por Flora Rosa e Sabrina Guimar�es 	  |
|                                    	    26/06/2023|
+-----------------------------------------------------+*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include "ViloesInteligentes.h"

using namespace std;

ViloesInteligentes::ViloesInteligentes()
{
    posx = NULL;
    posy = NULL;
}

void ViloesInteligentes::posPacman(int x, int y)
{
    posx = x;
    posy = y;

}

void ViloesInteligentes::moverViloes(int matriz[20][20])
{
    int control[4];
    int s;
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


    if (Heranca::getPosx() < posx && direcao != 4 && matriz[Heranca::getPosy()][Heranca::getPosx() + 1] == 1)
    {
        do
        {
            s = rand() % 4;

        } while (!control[s]);
        direcao = s + 1;
    }

    //pra esquerda
    else if (Heranca::getPosx() > posx && direcao != 3 && matriz[Heranca::getPosy()][Heranca::getPosx() - 1] == 1)
    {
        do
        {
            s = rand() % 4;

        } while (!control[s]);
        direcao = s + 1;
    }
    //pra baixo 
    else if (Heranca::getPosx() < posy && direcao != 1 && matriz[Heranca::getPosy() + 1][Heranca::getPosx()] == 1)
    {
        do
        {
            s = rand() % 4;

        } while (!control[s]);
        direcao = s + 1;

    }
    //pra cima
    else if (Heranca::getPosx() > posy && direcao != 2 && matriz[Heranca::getPosy() - 1][Heranca::getPosx()] == 1)
    {
        do
        {
            s = rand() % 4;

        } while (!control[s]);
        direcao = s + 1;

    }


    if (Heranca::getPosx() < posx && direcao != 4 && matriz[Heranca::getPosy()][Heranca::getPosx() + 1] != 1)
    {
        direcao = 3;
    }

    //pra esquerda
    else if (Heranca::getPosx() > posx && direcao != 3 && matriz[Heranca::getPosy()][Heranca::getPosx() - 1] != 1)
    {
        direcao = 4;
    }
    //pra baixo 
    else if (Heranca::getPosx() < posy && direcao != 1 && matriz[Heranca::getPosy() + 1][Heranca::getPosx()] != 1)
    {
        direcao = 2;

    }
    //pra cima
    else if (Heranca::getPosx() > posy && direcao != 2 && matriz[Heranca::getPosy() - 1][Heranca::getPosx()] != 1)
    {
        direcao = 1;

    }
    //Cima 
    if (direcao == 1 && matriz[Heranca::getPosy() - 1][Heranca::getPosx()] != 1)
    {
        Heranca::setPosy(Heranca::getPosy() - 1);


    }
    //Baixo 
    else if (direcao == 2 && matriz[Heranca::getPosy() + 1][Heranca::getPosx()] != 1)
    {
        Heranca::setPosy(Heranca::getPosy() + 1);

    }

    //Esquerda
    else if (direcao == 3 && matriz[Heranca::getPosy()][Heranca::getPosx() + 1] != 1)
    {
        Heranca::setPosx(Heranca::getPosx() + 1);

    }

    //Direita
    else if (direcao == 4 && matriz[Heranca::getPosy()][Heranca::getPosx() - 1] != 1)
    {
        Heranca::setPosx(Heranca::getPosx() - 1);

    }

}


ViloesInteligentes::~ViloesInteligentes()
{

}
