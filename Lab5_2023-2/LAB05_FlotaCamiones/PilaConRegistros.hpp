/* 
 * File:   PilaConRegistros.hpp
 * Author: VLADYMIR
 *
 * Created on 2 de mayo de 2024, 9:22
 */

#ifndef PILACONREGISTROS_HPP
#define PILACONREGISTROS_HPP
#include "Utils.hpp"
#include "PilaConRegistros.hpp"
enum RESGISTRO{COD,DNI,CANT,PESO};
void *leeregistro(ifstream &arch);
double calcularegistro(void *dato);
int cmpregistro(const void *a,const void *b);
void imprimeregistro(ofstream &arch,void *dato);


#endif /* PILACONREGISTROS_HPP */

