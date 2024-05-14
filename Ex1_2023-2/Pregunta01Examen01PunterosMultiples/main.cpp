/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 9 de mayo de 2024, 8:53
 */

#include "Pregunta01Examen01PunterosMultiples.hpp"
using namespace std;

int main(int argc, char** argv) {
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    cargarPedidos(fechaClienteCantidad, codigoDelProducto, "Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCantidad, codigoDelProducto, "PruebaPedidos.txt");
    
    return 0;
}

