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
	posx = NULL;
	posy = NULL;
}
void Heranca::setPosx(int x)
{
	this->posx = x;
}
void Heranca::setPosy(int y)
{
	this->posy = y;
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