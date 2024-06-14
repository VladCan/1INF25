/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   LVehiculos.hpp
 * Author: VLADYMIR
 *
 * Created on 13 de junio de 2024, 10:42
 */

#ifndef LVEHICULOS_HPP
#define LVEHICULOS_HPP
#include "Utils.hpp"
#include "NodoLista.hpp"
class LVehiculos{
private:
    class NodoLista *lini;
    class NodoLista *lfin;
public:
    LVehiculos();
    LVehiculos(const class LVehiculos&);
    virtual ~LVehiculos();
    void leer_inserta(char tipo, ifstream &arch);
    void insertar(Vehiculo *);
    void mostrarLista(ofstream&arch);
    void buscarClienteYagregarPedido(int ,ifstream&);
    Vehiculo* buscar(int);
    void agregarPedido(NodoLista *&,ifstream&);
};



#endif /* LVEHICULOS_HPP */

