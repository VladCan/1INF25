/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Alumno.hpp
 * Author: VLADYMIR
 *
 * Created on 22 de mayo de 2024, 16:19
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP
#include "Utils.hpp"
#include "Utils.hpp"
using namespace std;
class Alumno{
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
public:
    Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *nombre) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};


#endif /* ALUMNO_HPP */

