/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Camion.hpp
 * Author: VLADYMIR
 *
 * Created on 13 de junio de 2024, 10:31
 */

#ifndef CAMION_HPP
#define CAMION_HPP
#include "Utils.hpp"
#include "Vehiculo.hpp"
class Camion: public Vehiculo {
private:
    int ejes;
    int llantas;
public:
    Camion();
    Camion(const class Camion&);
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream&);
    void imprime(ofstream&arch);
};




#endif /* CAMION_HPP */

