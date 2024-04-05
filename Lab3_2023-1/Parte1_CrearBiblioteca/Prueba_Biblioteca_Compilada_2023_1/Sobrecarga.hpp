/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Sobrecarga.hpp
 * Author: VLADYMIR
 *
 * Created on 4 de abril de 2024, 11:11
 */

#ifndef SOBRECARGA_HPP
#define SOBRECARGA_HPP


#include <iostream>

#include "Estructuras.h"
using namespace std;

bool operator >>(ifstream &arch,StCurso &Curso);

bool operator >>(ifstream &arch,StAlumno &Alum);

bool operator >>(ifstream &arch,StRegistroDeMatricula &Matri);

void operator += (StCurso *arr,const StCurso Cur);
void operator += (StAlumno *arr,const StAlumno Alun);
void operator *= (StCurso *arr,const StRegistroDeMatricula Matri);
void operator *=(StAlumno *arr, const StRegistroDeMatricula Matri);

ofstream &operator <<(ofstream & arch,const StCurso Curso);
ofstream &operator <<(ofstream & arch,const StAlumno Alum);

#endif /* SOBRECARGA_HPP */

