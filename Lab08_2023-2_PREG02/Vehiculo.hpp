/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Vehiculo.hpp
 * Author: VLADYMIR
 *
 * Created on 13 de junio de 2024, 10:25
 */

#ifndef VEHICULO_HPP
#define VEHICULO_HPP
#include "NPedido.hpp"
class Vehiculo{
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
    NPedido *ped;
public:
    Vehiculo();
    Vehiculo(const class Vehiculo&);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char* placa);
    void GetPlaca(char* placa) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    void operator =(const class Vehiculo&);
    virtual void lee(ifstream&);
    virtual void imprime(ofstream&);
    void mostarPedidos(ofstream&);
    void agregarPedido(ifstream&);
    bool pilaVacia();
    void push(NPedido *);
    void imprimePedidos(ofstream&);
    void imprimeRecurcivo(ofstream&,NPedido *);
    void escribeLinea(ofstream&, int , char );
    
};


#endif /* VEHICULO_HPP */

