/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: VLADYMIR
 * 
 * Created on 13 de junio de 2024, 14:54
 */

#include "Flota.hpp"

using namespace std;

int main(int argc, char** argv) {
    Flota transporte;
    transporte.cargaflota();
    transporte.cargapedidos();
    transporte.muestracarga();

    return 0;
}

