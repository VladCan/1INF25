
/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 16 de abril de 2024, 19:41
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#define INCREMENTO 5

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

void incrementarCapacidadProductos(ifstream &arch,int &n,int &c,char ***&productos,int *&stocks,double *&precios);
void agregaraDatos(ifstream &arch,int &cantidad,char ***&productos,int *&stock,double *&precios);
void liberarMemoriaProducto(char ***&productos, int *&stocks, double *&precios);
void asignarProductos(char ***&productos, int *&stocks, double *&precios,char *** aux_productos,double *aux_precios,int *aux_stocks);
char **escribirDatosProducto(char *codigo,char *nombre);
char *escribir_str(char *buffer);
void leerFecha(ifstream &arch,int &fecha);
void incrementarCapacidadFechas(int &cantidad_fechas,int & capacidad_fechas,int *&fechaPedidos,int fecha,char ***&codigoPedidos,int ***&dniCantPedidos,int *&cantidades_pedidos,int *&capacidades_pedidos);
void agregarFecha(int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos,int *&cantidades_pedidos,int *&capacidades_pedidos,int &cantidad_fechas,int &capacidad_fechas,int fecha,int &pos);
void incrementarCapacidadPedido(char **&codigoPedidos,int **&dniCantPedidos,int &cantidades,int &capacidades,int dni,int cant_solicitada,char *codigo);
int buscarFecha(int *fechaPedidos,int  fecha, int cantidad_fechas);
void liberarMemoriaPedidos(int *&fechaPedidos, int *&cantidades_pedidos, int *&capacidades_pedidos,char ***&codigoPedidos,int ***&dniCantPedidos);
void asignarPedidos(int *&fechaPedidos, int *&cantidades_pedidos, int *&capacidades_pedidos, char ***&codigoPedidos, int ***&dniCantPedidos,
        int * aux_fechas, int *aux_cantidadPedidos, int *aux_capacidadPedidos, char ***aux_codigoPedidos, int ***aux_dniCantPedidos);
 void agregarPedido(char **&codigoPedidos,int **&dniCantPedidos,int &cantidades_pedidos,int &capacidades_pedidos, char *codigo, int dni, int cant_solicitada);

int *escribirDatosDni(int dni,int cantidad);
void obtenerDatos(int *dniCantPedidos, int &dni, int &cantida);
void escribirProductos(ofstream &arch, char **codigoPedidos, int **dniCantPedidos) ;
void escribirProductos(ofstream &arch, char **codigoPedidos, int **dniCantPedidos) ;
void escribirLinea(ofstream &arch, int n, char c);
void escribirFecha(ofstream &arch, int fecha) ;

#endif /* FUNCIONES_HPP */

