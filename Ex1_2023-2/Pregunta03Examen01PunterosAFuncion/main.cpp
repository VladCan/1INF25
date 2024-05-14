
/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 9 de mayo de 2024, 8:54
 */

#include "Pregunta01Examen01PunterosMultiples.hpp"
#include "Pregunta02Examen01PunterosGenericos.h"
#include "ColaConEnteros.h"
#include "ColaConProductos.h"
#include "ColaGenerica.h"
#include "Utils.hpp"
using namespace std;

int main(int argc, char** argv) {
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    void *productos;
    void *cola;
    cargarPedidos(fechaClienteCantidad, codigoDelProducto, "Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCantidad, codigoDelProducto, "PruebaPedidos.txt");
    cargarProductos(productos, "Productos.csv");
    pruebaDeCargaDeProductos(productos);
    cargaEnteros(cola, leenumero, "numeros.txt");
    mostrarEnteros(cola, imprimenumero, "reporte.txt");
    procesarPedidos(fechaClienteCantidad, codigoDelProducto, productos);
    reporteDePedidos(productos, "reportefinal.txt");
    return 0;
}



