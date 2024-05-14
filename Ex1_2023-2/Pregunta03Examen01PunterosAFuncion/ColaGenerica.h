/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaGenerica.h
 * Author: alulab14
 *
 * Created on 10 de mayo de 2024, 09:22 AM
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H
#include "Utils.hpp"
using namespace std;
enum COLA{CABEZA,COLA,CANT_COLA};
enum NODO{REG,SIG};

void generacola(void *&tad);
void encola(void *&tad,void *dato);
void* desencola(void *&tad);
bool colavacia(void *tad);
int *longitud(void *tad);
#endif /* COLAGENERICA_H */

