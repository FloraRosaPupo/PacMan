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

#include "Heranca.h"

using namespace std;

Heranca::Heranca() {
	posx = 0;
	posy = 0;
}
void Heranca::setPosx(int x)
{
	posx = x;
}
void Heranca::setPosy(int y)
{
	posy = y;
}
int Heranca::getPosx()
{
	return posx;

}
int Heranca::getPosy()
{
	return posy;
}

Heranca::~Heranca() {

}