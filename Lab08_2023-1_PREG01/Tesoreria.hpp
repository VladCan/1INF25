/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Tesoreria.hpp
 * Author: VLADYMIR
 *
 * Created on 22 de mayo de 2024, 16:20
 */

#ifndef TESORERIA_HPP
#define TESORERIA_HPP
#include "Presencial.hpp"
#include "Semipresencial.hpp"
#include "Virtual.hpp"
#include "Escala.hpp"
#include "Utils.hpp"
using namespace std;
class Tesoreria{
private:
    Presencial lpresencial[50];
    Semipresencial lsemipresencial[50];
    Virtual lvirtual[50];
    Escala lescala[50];
public:
    Tesoreria();
    void cargaescalas();
    void cargaalumnos();
    void actualiza(double creditos);
    void imprime();
    double buscarPrecioEscala(int escala);
};
void ecribirLinea(ofstream &,int ,char);
#endif /* TESORERIA_HPP */

