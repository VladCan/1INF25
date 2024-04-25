/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 18 de abril de 2024, 16:50
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "AperturaDeArchivos.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#define INCREMENTO 5
using namespace std;
void incrementarCapacidadLibros(char ***&libros, int **&stock, int &cantidad, int &capacidad);
void ingresarLibro(ifstream &arch, char **&libros, int *&stock, int &cantidad,char *codigo);
char *leerCadena(ifstream &arch,char c);
void escribirLibro(ofstream &arch,char **libros,int *stock);
void escribirLinea(ofstream &arch,int n,char c);
int buscarCliente(int **pedidosClientes,int dni,int cantidadClientes);
void incrementarMemoriaCliente(int *&pedidosClientes,char **&pedidosLibros,bool *&pedidosAtendidos,int &cantidad,int &capacidad);
void incrementarMemoriaClientes(int **&pedidosClientes,int &cantidadClientes,int &capacidadClientes);
void incrementarMemoriaPedidos(char ***&pedidosLibros,bool **&pedidosAtendidos,int *&cantLibrosPedido,int *&capaLibrosPedido,int &cantidatPedidos,int &capacidadPedidos);
void agregarPedido(ifstream &arch,int *&pedidosClientes,char **&pedidosLibros,bool *&pedidosAtendidos,int &cantidad,int &capacidad,char ***libros,int **&stock,int dni,int pedido);
char * leerCodigo(ifstream &arch);
#endif /* FUNCIONES_HPP */

