/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 24 de marzo de 2024, 20:27
 */

#include "Sobrecargandos.hpp"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"

using namespace std;


int main(int argc, char** argv) {
    
    ifstream archClientes,archProducto, archPedido;
    ofstream archReporteCliente,archReporteProducto;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProducto,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedido,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteCliente,"Reporte_Cliente.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteProducto,"Reporte_Producto.txt");
    
    struct Cliente cliente;
    struct Producto producto;
    struct Pedido pedido;
    archClientes>>cliente;
    archProducto>>producto;
    archPedido>>pedido;
    struct Cliente arrClientes[10];
    struct Producto arrProductos[10];
    arrClientes[0]=cliente;
    //arrClientes+=pedido;
    //arrProductos+=pedido;
    archReporteCliente<<cliente;
    archReporteProducto<<producto;        
    return 0;
}

