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

#include"Heranca.h"

#ifndef VANELLOPE_H
#define VANELLOPE_H

class Vanellope : public Heranca
{

public:
    Vanellope();
    ~Vanellope();

    void carregaImagem();
    void andaVanellope(int direcao);
    void imprimeVanellope(int direx);

private:

    ALLEGRO_BITMAP* vanellope[2];
};

#endif // VANELLOPE_H