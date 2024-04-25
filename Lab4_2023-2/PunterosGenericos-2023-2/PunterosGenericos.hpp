
/* 
 * File:   PunterosGenericos.hpp
 * Author: VLADYMIR
 *
 * Created on 22 de abril de 2024, 21:40
 */

#ifndef PUNTEROSGENERICOS_HPP
#define PUNTEROSGENERICOS_HPP

#include "PunterosGenericos.hpp"
#include "funciones.hpp"

void cargaproductos(void *&productos);
void cargaclientes(void *&clientes);
void cargapedidos(void *productos, void *&clientes);
void imprimereporte(void *clientes);

#endif /* PUNTEROSGENERICOS_HPP */

