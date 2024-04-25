/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 18 de abril de 2024, 16:47
 */

#include "funciones.hpp"
#include "MetodoIncrementoDeMemoria.hpp"

using namespace std;

int main(int argc, char** argv) {

    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    lecturaDeLibros("Libros.csv", libros, stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", libros, stock);
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros, pedidosAtendidos);
//    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", libros, stock);
//    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",pedidosClientes, pedidosLibros, pedidosAtendidos);

    return 0;
}

