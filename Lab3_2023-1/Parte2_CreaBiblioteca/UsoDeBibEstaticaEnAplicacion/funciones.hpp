
/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 4 de abril de 2024, 15:13
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Sobrecarga.hpp"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void leerCursos(StCurso * arrCursos);
void leerAlumnos(StAlumno *arrAlumnos);
void leerMatriculaYcompletar(StCurso *arrCursos,StAlumno *arrAlumnos);
int buscarAlumno(StAlumno *arrAlum, int codigo);
void calculoDeCostos(StCurso *arrCursos, StAlumno *arrAlumnos);
double buscarEscala(ifstream &archEscala,int escala);
void emitirReporte(ofstream &Reporte,StCurso *arrCursos,StAlumno *arrAlumnos);
void escribirLinea(ofstream &arch,int n,char c);
#endif /* FUNCIONES_HPP */

