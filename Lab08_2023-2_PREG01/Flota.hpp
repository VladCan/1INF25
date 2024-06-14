/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Flota.hpp
 * Author: VLADYMIR
 *
 * Created on 13 de junio de 2024, 10:45
 */

#ifndef FLOTA_HPP
#define FLOTA_HPP
#include "Utils.hpp"
#include "LVehiculos.hpp"
class Flota{
private:
    LVehiculos lista;
public:
    Flota();
    Flota(const class Flota&);
    virtual ~Flota();
    void cargaflota();
    void cargapedidos();
    void muestracarga();
    
};


#endif /* FLOTA_HPP */

