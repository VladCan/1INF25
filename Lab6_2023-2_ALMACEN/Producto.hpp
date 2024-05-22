/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Producto.hpp
 * Author: VLADYMIR
 *
 * Created on 21 de mayo de 2024, 18:45
 */

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
#include "Utils.hpp"
#include "Pedido.hpp"
class Producto {
private:
    char *codigo;
    char *descriopcion;
    double precio;
    int stock;
    int clientes_servidos[50];
    int clientes_no_servidos[50];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
public:
    Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescriopcion(const char* descriopcion);
    void GetDescriopcion(char* descriopcion) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char* codigo) const;
    bool operator +=(Pedido&);
    void operator <<(ofstream &);
};
bool operator >>(ifstream &,Producto&);

#endif /* PRODUCTO_HPP */

