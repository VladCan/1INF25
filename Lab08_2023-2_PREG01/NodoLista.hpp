/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoLista.hpp
 * Author: VLADYMIR
 *
 * Created on 13 de junio de 2024, 10:40
 */

#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Utils.hpp"
#include "Vehiculo.hpp"
#include "LVehiculos.hpp"

class NodoLista {
private:
    Vehiculo *unidad;
    NodoLista *sig;
public:
    NodoLista();
    NodoLista(const class NodoLista&);
    virtual ~NodoLista();
    friend class LVehiculos;
    void asignarMemoriaUnidad(char);
};


#endif /* NODOLISTA_HPP */

