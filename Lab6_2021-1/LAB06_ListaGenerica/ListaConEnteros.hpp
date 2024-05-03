/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConEnteros.hpp
 * Author: VLADYMIR
 *
 * Created on 2 de mayo de 2024, 15:23
 */

#ifndef LISTACONENTEROS_HPP
#define LISTACONENTEROS_HPP

#include "Utils.hpp"

enum NODO{DATO,SIG};
void *leenum(ifstream &arch);
int cmpnum(void *,void *);
void imprimenum(ofstream &arch,void *);

#endif /* LISTACONENTEROS_HPP */

