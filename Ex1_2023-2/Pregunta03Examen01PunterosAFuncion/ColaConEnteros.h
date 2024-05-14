/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaConEnteros.h
 * Author: alulab14
 *
 * Created on 10 de mayo de 2024, 09:21 AM
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H

#include "ColaGenerica.h"

void cargaEnteros(void *&cola,void *(*leenumero)(ifstream &arch), const char *filename);
void *leenumero(ifstream &arch);
void mostrarEnteros(void *&cola,void (*imprimenumero)(ofstream &arch,void *dato), const char *filename);
void imprimenumero(ofstream &arch,void *dato);
#endif /* COLACONENTEROS_H */

