
/* 
 * File:   Pregunta02Examen01PunterosGenericos.h
 * Author: alulab14
 *
 * Created on 10 de mayo de 2024, 08:14 AM
 */

#ifndef PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H
#define PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H

#include "Utils.hpp"
using namespace std;
enum REGISTRO{DATOS,NUL};
enum PRODUCTO{COD,DESC,PRECIO,STOCK};
void cargarProductos(void *&productos, const char *filename);
void pruebaDeCargaDeProductos(void *productos);
char *leerStr(ifstream &arch);
void *leerRegistro(ifstream &arch);
void incrementarMemoria(void **&productos,int &cantidad,int &capacidad);
void escribirRegisto(ofstream &arch,void *registo);
int cmp(const void *A,const void *B);


#endif /* PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H */

