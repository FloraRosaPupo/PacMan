/*----------------- File: main.cpp -------------------+
|			    DESCRICAO DO ARQUIVO			      |
| 		      ETAPA 4 - Projeto vanellope Man		  |
| 									                  |
| Implementado por Flora Rosa e Sabrina Guimar es 	  |
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
    if (direcao == 4 /*esquerda*/ || matriz[i][j + 1] == 1)
    {
        opc[2] = false;

    }

    //pra esqueda 
    if (direcao == 3 /*direita*/ || matriz[i][j - 1] == 1)
    {
        opc[3] = false;
    }

    //-----------


    //Verifica a posicao da Vanellope
     //pra cima
    if (direcao != 2 && j > posy && matriz[i - 1][j] == 1)
    {
        while (1) {
            desV = rand() % 4;
            if (opc[desV]) {
                direcao = desV + 1;
                break;
            }
        }

    }
    //pra baixo 
    if (direcao != 1 && i < posy && matriz[i + 1][j] == 1)
    {
        while (1) {
            desV = rand() % 4;
            if (opc[desV]) {
                direcao = desV + 1;
                break;
            }
        }
    }
    //pra direita 
    if (direcao != 4 && j < posx && matriz[i][j + 1] == 1)
    {
        while (1) {
            desV = rand() % 4;
            if (opc[desV]) {
                direcao = desV + 1;
                break;
            }
        }
    }
    //pra esquerda
    else if (direcao != 3 && j > posx && matriz[i][j - 1] == 1)
    {
        while (1) {
            desV = rand() % 4;
            if (opc[desV]) {
                direcao = desV + 1;
                break;
            }
        }
    }


    //--------------------------------
    //pra cima
    if (direcao != 2 && j > posy && matriz[i - 1][j] != 1)
    {
        direcao = 1;

    }
    //pra baixo 
    if (direcao != 1 && j < posy && matriz[i + 1][j] != 1)
    {
        direcao = 2;

    }
    //pra direita 
    if (direcao != 4 && j < posx && matriz[i][j + 1] != 1)
    {
        direcao = 3;
    }
    //pra esquerda
    if (direcao != 3 && j > posx && matriz[i][j - 1] != 1)
    {
        direcao = 4;
    }




    //----------------
    //pra cima 
    if (direcao == 1 && matriz[i - 1][j] != 1)
    {
        Heranca::setPosy(i - 1);


    }
    //pra baixo 
    else if (direcao == 2 && matriz[i + 1][j] != 1)
    {
        Heranca::setPosy(i + 1);

    }

    //pra direita
    else if (direcao == 3 && matriz[i][j + 1] != 1)
    {
        Heranca::setPosx(j + 1);

    }

    //pra esquerda
    else if (direcao == 4 && matriz[i][j - 1] != 1)
    {
        Heranca::setPosx(j - 1);
    }

}


ViloesInteligentes::~ViloesInteligentes()
{

}
