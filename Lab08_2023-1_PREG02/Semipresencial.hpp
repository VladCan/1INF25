/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Semipresencial.hpp
 * Author: VLADYMIR
 *
 * Created on 22 de mayo de 2024, 16:20
 */

#ifndef SEMIPRESENCIAL_HPP
#define SEMIPRESENCIAL_HPP
#include "Alumno.hpp"
#include "Utils.hpp"
using namespace std;
class Semipresencial: public Alumno{
private:
    double descunto;
    double total;
public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescunto(double descunto);
    double GetDescunto() const;
    void actualizar(double monto);
};
void operator >>(ifstream &,Semipresencial&);
void operator <<(ofstream &,Semipresencial);
#endif /* SEMIPRESENCIAL_HPP */

