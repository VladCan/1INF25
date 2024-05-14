/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 9 de mayo de 2024, 8:54
 */

#include "Pregunta02Examen01PunterosGenericos.h"
using namespace std;

int main(int argc, char** argv) {

    void *productos;
    cargarProductos(productos, "Productos.csv");
    pruebaDeCargaDeProductos(productos);
    
    return 0;
}

