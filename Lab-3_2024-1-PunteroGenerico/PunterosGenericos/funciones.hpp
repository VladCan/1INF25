/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 25 de abril de 2024, 22:17
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "AperturaDeArchivos.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

enum LIBRO{COD,TITULO,AUTOR,CANT,PRECIO};
using namespace std;
void *leerRegistroLibro(ifstream &arch);
char * leerCadena(ifstream &arch,int c);


#endif /* FUNCIONES_HPP */

