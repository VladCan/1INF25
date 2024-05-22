/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ProductoEntregado.hpp
 * Author: VLADYMIR
 *
 * Created on 21 de mayo de 2024, 18:41
 */

#ifndef PRODUCTOENTREGADO_HPP
#define PRODUCTOENTREGADO_HPP
#include "Utils.hpp"
class ProductoEntregado {
private:
    char *codigo;
    double precio;
public:
    ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char* codigo) const;
};


#endif /* PRODUCTOENTREGADO_HPP */

