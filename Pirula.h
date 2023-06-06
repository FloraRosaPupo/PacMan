/*---------------- File: Pirula.h ------------------+
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

#ifndef MOEDA_H
#define MOEDA_H

class Pirula
{

public:
    Pirula();
    ~Pirula();

    void setPosx (int i);
    void setPosy (int j);
    int getPosx();
    int getPosy();
    void carregaImagem();
    void imprimePirula();
    void movimentaSprite();

    int controle;

private:

    ALLEGRO_BITMAP* pirula;
    int sprite;
    int posx;
    int posy;

};

#endif