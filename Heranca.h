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

#ifndef HERANCA_H
#define HERANCA_H

class Heranca {
public:
    Heranca();
    ~Heranca();

    void setPosx(int i);
    void setPosy(int j);
    int getPosx();
    int getPosy();

protected:
    int posx;
    int posy;
};

#endif
