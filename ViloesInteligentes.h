﻿/*----------------- File: main.cpp -------------------+
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

#include"Viloes.h"

#ifndef VILOESINTELIGENTES_H
#define VILOESINTELIGENTES_H

class ViloesInteligentes : public Viloes {


public:
	ViloesInteligentes();
	~ViloesInteligentes();
	void posPacman(int posX, int posY);
	int posAnt();

private: 
	int posx;
	int posy;

};
#endif //VILOESINTELIGENTES_H