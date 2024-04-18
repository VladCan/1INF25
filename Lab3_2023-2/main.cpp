/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 16 de abril de 2024, 19:35
 */


#include "AsignacionDinamicaMemoriaExacta.hpp"
#include "AperturaDeArchivos.h"
#include "funciones.hpp"

using namespace std;

int main(int argc, char** argv) {
    
    char ***productos,***codigoPedidos; 
    int *stock, *fechaPedidos, ***dniCantPedidos; 
    double *precios;
    
    lecturaDeProductos ("Productos.csv",productos, stock, precios); 
    pruebaDeLecturaDeProductos ("ReporteDeProductos.txt" ,productos, stock, precios);
    lecturaDePedidos ("Pedidos.csv", fechaPedidos, codigoPedidos, dniCantPedidos); 
    pruebaDeLecturaDePedidos ("ReporteDePedidos.txt", fechaPedidos, codigoPedidos, dniCantPedidos); 
  //  reporteDeEnvioDePedidos ("ReporteDeEntregaDePedisos.txt", productos, stock, precios, fechaPedidos, codigoPedidos, dniCantPedidos);
   // pruebaDeLecturaDeProductos ("ReporteDeProductosFinal.txt" ,productos, stock, precios);
    

    return 0;
}

