/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Almacen.hpp
 * Author: VLADYMIR
 *
 * Created on 21 de mayo de 2024, 18:45
 */
#ifndef ALMACEN_HPP
#define ALMACEN_HPP
#include "Cliente.hpp"
#include "Producto.hpp"
class Almacen{
private:
    Cliente arreglo_clientes[20];
    int cantidad_clientes;
    Producto arreglo_productos[20];
    int cantidad_productos;
};


#endif /* ALMACEN_HPP */

