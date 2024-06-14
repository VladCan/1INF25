/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Furgon.hpp
 * Author: VLADYMIR
 *
 * Created on 13 de junio de 2024, 10:35
 */

#ifndef FURGON_HPP
#define FURGON_HPP
#include "Utils.hpp"
#include "Vehiculo.hpp"

class Furgon : public Vehiculo {
private:
    int filas;
    int puertas;
public:
    Furgon();
    Furgon(const class Furgon&);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream&);
    void imprime(ofstream&arch);
};



#endif /* FURGON_HPP */

