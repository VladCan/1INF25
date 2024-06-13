/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Presencial.hpp
 * Author: VLADYMIR
 *
 * Created on 22 de mayo de 2024, 16:25
 */

#ifndef PRESENCIAL_HPP
#define PRESENCIAL_HPP
#include "Alumno.hpp"
#include "Utils.hpp"
using namespace std;
class Presencial: public Alumno{
private:
    double recargo;
    double total;
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void actualizar(double monto);
};
void operator >>(ifstream &,Presencial&);
void operator <<(ofstream &,Presencial);


#endif /* PRESENCIAL_HPP */

