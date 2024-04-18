/* 
 * File:   AsignacionDinamicaMemoriaExacta.hpp
 * Author: VLADYMIR
 *
 * Created on 16 de abril de 2024, 19:42
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_HPP
#define ASIGNACIONDINAMICAMEMORIAEXACTA_HPP

#include "funciones.hpp"


void lecturaDeProductos(const char *filename, char ***&productos, int *&stock, double *&precios);
void pruebaDeLecturaDeProductos(const char *filename, char ***productos, int *stock, double *precios);
void lecturaDePedidos(const char *filename, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos);
void pruebaDeLecturaDePedidos(const char *filename, int * fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos);
void reporteDeEnvioDePedidos(const char *filename, char ***productos, int *stock, double *precios, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos);
void pruebaDeLecturaDeProductos(const char *filename, char ***productos, int * stock, double * precios);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_HPP */

