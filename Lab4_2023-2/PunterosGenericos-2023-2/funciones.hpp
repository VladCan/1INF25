/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 22 de abril de 2024, 21:40
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define INCREMENTO 5

enum PRODUCTOS {
    CODIGO, DESCRIPCION, PRECIO, TIPO
};

enum CLIENTES {
    DNI, NOMBRE, PEDIDOS, LINEACRED
};
enum PEDIDO  {
    CODPROD, CANTIDADPROD, TOTAL
};
using namespace std;
char *leerCadena(ifstream &arch, char c);
void *leerRegistroProd(ifstream &arch);
void *leerRegistroClien(ifstream &arch);
void actualizarPuntoVoid(void *&punteroGenerico,void **auxiliar,int cantidad);
void incrementarMemoria(void **&p, int n, int c);
int buscarCliente(void *clientes,int dni);
int buscarProducto(void *productos,char *codigo);
void actualizarCliente(void *&cliente,void *&producto,int *cant);
void agregarPedido(void **&datosCliente,void **pedido);
void escribirLinea(ofstream &arch,int n,char c);
void escribirPedidos(ofstream &arch,void *pedido);
int cmp_void_dni(const void *a,const void *b);
int cmp_void_name(const void *a,const void *b);
int calcularCantidad(void *punteroGenerico);
#endif /* FUNCIONES_HPP */

