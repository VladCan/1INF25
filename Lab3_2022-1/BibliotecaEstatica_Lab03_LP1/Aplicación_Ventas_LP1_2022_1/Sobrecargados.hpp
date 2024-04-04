/* 
 * File:   Sobrecargados.hpp
 * Author: VLADYMIR
 *
 * Created on 2 de abril de 2024, 8:53
 */

#ifndef SOBRECARGADOS_HPP
#define SOBRECARGADOS_HPP


#include <iostream>
#include <iomanip>
#include <cstring>
#include "Estruturas.h"
#include "AperturaDeArchivos.h"




ifstream & operator >>(ifstream &arch,Estructura_ClienteRegistrado &Cli);

void operator += (Estructura_ClienteRegistrado *arr, const Estructura_ClienteRegistrado Cli);

void operator += (Estructura_ClienteRegistrado &Cli, const Estructura_PedidoRealizado Ped);

void operator += (Estructura_ProductosEnAlmacen *arr, const Estructura_ProductosEnAlmacen Prod);


ofstream & operator <<(ofstream &arch,const Estructura_ClienteRegistrado Cli);
ofstream & operator <<(ofstream &arch,const Estructura_ProductosEnAlmacen *arr);

#endif /* SOBRECARGADOS_HPP */

