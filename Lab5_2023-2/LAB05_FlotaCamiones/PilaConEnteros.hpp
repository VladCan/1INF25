/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConEnteros.hpp
 * Author: VLADYMIR
 *
 * Created on 2 de mayo de 2024, 9:21
 */

#ifndef PILACONENTEROS_HPP
#define PILACONENTEROS_HPP
#include "Utils.hpp"
enum Nodo{SIGUIENTE,DATO};
void * leenumero(ifstream &arch);
double calculanumero(void *);
int cmpnumero(const void *a,const void *b);
void imprimenumero(ofstream&arch, void *dato);
#endif /* PILACONENTEROS_HPP */

