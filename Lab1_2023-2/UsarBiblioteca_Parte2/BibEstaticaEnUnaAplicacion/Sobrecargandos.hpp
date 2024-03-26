
/* 
 * File:   Sobrecargandos.hpp
 * Author: VLADYMIR
 *
 * Created on 24 de marzo de 2024, 20:42
 */

#ifndef SOBRECARGANDOS_HPP
#define SOBRECARGANDOS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructuras.h"
using namespace std;

bool operator >> (ifstream &arch, struct Cliente &cli);
bool operator >> (ifstream &arch, struct Producto &prod);
bool operator >> (ifstream &arch, struct Pedido &ped);
void operator += (struct Cliente *arrCli, const struct Pedido &ped );
bool operator += (struct Producto *arrProd, struct Pedido &ped );
ofstream & operator << (ofstream &arch, const struct Cliente &cli);
ofstream & operator << (ofstream &arch, const struct Producto &prod);


#endif /* SOBRECARGANDOS_HPP */

