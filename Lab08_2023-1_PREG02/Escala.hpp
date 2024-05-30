/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Escala.hpp
 * Author: VLADYMIR
 *
 * Created on 22 de mayo de 2024, 16:19
 */

#ifndef ESCALA_HPP
#define ESCALA_HPP

class Escala{
private:
    int codigo;
    double precio;
public:
    Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};


#endif /* ESCALA_HPP */

