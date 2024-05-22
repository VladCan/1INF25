/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Cliente.hpp
 * Author: VLADYMIR
 *
 * Created on 21 de mayo de 2024, 18:44
 */

#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include "Utils.hpp"
#include "Pedido.hpp"
#include "ProductoEntregado.hpp"

class Cliente {
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[10];
    int cantidad_productos_entregados;
    double monto_total;
public:
    Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *nombre) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator +=(Pedido);
    void encontrarPriducto(int i,ProductoEntregado &ProdE);
};
void operator <<(ofstream &,Cliente);
bool operator >>(ifstream &,Cliente&);


#endif /* CLIENTE_HPP */

