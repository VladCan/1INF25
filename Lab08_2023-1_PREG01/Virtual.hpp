/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Virtual.hpp
 * Author: VLADYMIR
 *
 * Created on 22 de mayo de 2024, 16:20
 */

#ifndef VIRTUAL_HPP
#define VIRTUAL_HPP
#include "Alumno.hpp"
#include "Utils.hpp"
using namespace std;
class Virtual: public Alumno{
private:
    char *licencia;
    double total;
public:
    Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* licencia);
    void GetLicencia(char* licencia) const;
    void actualizar(double monto);
};
void operator >>(ifstream &,Virtual&);
void operator <<(ofstream &,Virtual);
#endif /* VIRTUAL_HPP */

