/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: VLADYMIR
 * 
 * Created on 22 de mayo de 2024, 16:18
 */

#include "Tesoreria.hpp"

using namespace std;


int main(int argc, char** argv) {
    Tesoreria caja;
    caja.cargaescalas();
    caja.cargaalumnos();
    caja.actualiza(10.5);
    caja.imprime();
    return 0;
}

