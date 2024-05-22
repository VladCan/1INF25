/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pedido.hpp
 * Author: VLADYMIR
 *
 * Created on 21 de mayo de 2024, 18:45
 */

#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include "Utils.hpp"
class Pedido{
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
public:
    Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char *codigo);
    void GetCodigo(char *) const;
};
bool operator >>(ifstream &,Pedido&);
#endif /* PEDIDO_HPP */

