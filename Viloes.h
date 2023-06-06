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

private:

    ALLEGRO_BITMAP* viloes[4];
};

#endif // VILOES_H
