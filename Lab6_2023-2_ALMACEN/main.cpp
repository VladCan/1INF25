/* 
 * File:   main.cpp
 * Author: VLADYMIR
 * 
 * Created on 21 de mayo de 2024, 21:43
 */

#include "Almacen.hpp"

using namespace std;

int main(int argc, char** argv) {
    Almacen almacen;
    almacen.cargar_clientes();
    almacen.cargar_productos();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();
    return 0;
}

