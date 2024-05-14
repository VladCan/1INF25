/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta01Examen01PunterosMultiples.hpp
 * Author: VLADYMIR
 *
 * Created on 9 de mayo de 2024, 14:03
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_HPP
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_HPP
#include "AperturaDeArchivos.h"
#include "Utils.hpp"
using namespace std;
enum DATOSFECHA{DNI,CANT,FECHA};
void cargarPedidos(int **&fechaClienteCantidad, char **&codigoDelProducto, const char *filename);
int leerFecha(ifstream &arch);
char *leerCodigo(ifstream &arch);
void incrementrarMemoria(int **&fechaClienteCantidad, char **&codigoDelProducto,int &cantidad,int &capacidad);
void pruebaDeCargaDePedidos(int **fechaClienteCantidad, char **codigoDelProducto, const char *filename);

void ordenarAcendente(int **&fechaClienteCantidad, char **&codigoDelProducto,int izq,int der);
void cambiar(int *&fechaClienteCantidadI,int *&fechaClienteCantidadK, char *&codigoDelProductoI,char *&codigoDelProductoK);
void escribirFecha(ofstream &arch,int fecha);
void escribirLiena(ofstream &arch,int n,char c);
#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_HPP */

