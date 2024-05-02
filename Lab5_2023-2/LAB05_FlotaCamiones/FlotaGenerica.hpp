/* 
 * File:   FlotaGenerica.hpp
 * Author: VLADYMIR
 *
 * Created on 2 de mayo de 2024, 9:22
 */

#ifndef FLOTAGENERICA_HPP
#define FLOTAGENERICA_HPP
#include "Utils.hpp"
enum Pila{CIMA,TOTAL};

void cargacamiones(void *&flota, int numcamiones, double pesomaximo, void * (*lee)(ifstream&arch), double (*calcula)(void *), const char *filename);
void muestracamiones(void *flota, int numcamiones,void (*imprime)(ofstream&,void *), const char *filename);
void push(void **&camiones,int &i,void *dato,double (*calcula)(void *),int pesomaximo,int numcamiones);
bool pilaVacia(void **pila);
void insertarDato(void **&pila,void *nuevoNodo);
#endif /* FLOTAGENERICA_HPP */

