/*----------------- File: Tijolo.h -------------------+
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

#ifndef TIJOLO_H
#define TIJOLO_H

class Tijolo
{

public:
    Tijolo();
    ~Tijolo();
    void setPosx(int i);
    void setPosy(int j);
    void carregaImagem();
    void imprimeTijolo();

private:

    ALLEGRO_BITMAP* tijolo;
    int posx;
    int posy;
};

#endif 
