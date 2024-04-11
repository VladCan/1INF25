/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 10 de abril de 2024, 20:27
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
void comprobarApertura(ifstream &arch,const char*nombreArch);
void comprobarApertura(ofstream &arch,const char*nombreArch);
void llenarProductos(char **&productos,char *codigo,char *nombre);
void llenarAuxilaresProductos(ifstream &arch,char **codigos,char **nombres,int *stocks,double *aux_precios,int &cantidad);
void escribirDatosPedido(char **&codigos,int **&pedidos,int &num,char *buffer,int dni,int catidad);
void escribirDatosPedido(char **&codigoPedidos,char **codigos);
void escribirDatosPedido(int **&dniCantPedidos,int **pedidos);
char *escribir_str(const char *buffer);
int *escribir_int(int dni,int cantidad);
void escribirLinea(ofstream &arch,int n,char c);
void escribirProducto(ofstream &arch,char **producto);
void leerFecha(ifstream &arch,int &fecha);
int buscarFecha(int *fechas,int fecha);
void completarPedidos(char **&codigoPedidos,char *codigo,int **&dniCantPedidos,int dni,int cantidad);
void escribirFecha(ofstream &arch,int fecha);
void escribirProductos(ofstream &arch,char **codigoPedidos,int **dniCantPedidos);
void obtenerDatos(int *dniCantPedidos,int &dni,int &cantida);
void escribirProductos(ofstream &arch,char **codigoPedidos,int **dniCantPedidos,char ***productos,int *&stock,double *precios,double &ingresado,double &perdido);
int buscarProducto(char ***productos,char *codigoPedidos);
int compararCodigoProducto(char **producto,char *codigoPedidos);
#endif /* FUNCIONES_HPP */

