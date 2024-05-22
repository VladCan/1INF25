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
#include "Utils.hpp"
#include "Cliente.hpp"
#include "Producto.hpp"
#include "Pedido.hpp"
class Almacen{
private:
    Cliente arreglo_clientes[200];
    int cantidad_clientes;
    Producto arreglo_productos[200];
    int cantidad_productos;
public:
    Almacen();
    void setCantidad_productos(int cantidad_productos);
    int getCantidad_productos() const;
    void setCantidad_clientes(int cantidad_clientes);
    int getCantidad_clientes() const;
    void cargar_clientes();
    void cargar_productos();
    void cargar_pedidos();
    void mostrar_datos();
    int indiceCliente(int);
    int iniceProducto(char *);
    void escribirLinea(int ,char ,ofstream&);
};


#endif /* ALMACEN_HPP */

