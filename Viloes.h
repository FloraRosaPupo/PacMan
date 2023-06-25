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

#ifndef VILOES_H
#define VILOES_H

class Viloes : public Heranca
{

public:
    Viloes();
    ~Viloes();

    void carregaImagem();
    void imprimeViloes(int direx);

    //poliformismo 

    virtual void moverViloes(int matriz[20][20]);
    int direcao;
   

private:

    ALLEGRO_BITMAP* viloes[4];
};

#endif // VILOES_H
