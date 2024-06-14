/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NPedido.hpp
 * Author: VLADYMIR
 *
 * Created on 13 de junio de 2024, 10:19
 */

#ifndef NPEDIDO_HPP
#define NPEDIDO_HPP
#include "Utils.hpp"
class NPedido{
private:
    char *codigo;
    int cantidad;
    double peso;
    NPedido *sig;
public:
    NPedido();
    NPedido(const class NPedido&);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char* codigo) const;
};


#endif /* NPEDIDO_HPP */

