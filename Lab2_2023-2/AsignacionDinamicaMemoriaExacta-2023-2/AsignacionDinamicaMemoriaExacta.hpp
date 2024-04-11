
/* 
 * File:   AsignacionDinamicaMemoriaExacta.hpp
 * Author: VLADYMIR
 *
 * Created on 10 de abril de 2024, 20:07
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_HPP
#define ASIGNACIONDINAMICAMEMORIAEXACTA_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;


void lecturaDeProductos(const char * nombreArch, char ***&productos,int * &stock,double * &precios);
void pruebaDeLecturaDeProductos(const char * nombreArch,char *** productos, int *stock,double *  precios);
void lecturaDePedidos(const char * nombreArch, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos);
void pruebaDeLecturaDePedidos(const char * nombreArch, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos);
void reporteDeEnvioDePedidos(const char * nombreArch, char ***productos, int * stock, double * precios, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos);
    

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_HPP */

