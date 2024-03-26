/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 26 de marzo de 2024, 11:59
 */

#include "Sobrecargandos.hpp"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funciones.hpp"
using namespace std;
int main(int argc, char** argv) {
ifstream archClientes, archProducto, archPedido;
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProducto, "Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedido, "Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "Reporte.txt");

    
    
    struct Cliente cliente,arrClientes[150];
    struct Producto producto,prodTope,arrProductos[170];
    strcpy(prodTope.codigo,"XXXXXXX");
    struct Pedido pedido;
    
    
    arrClientes[0] = cliente;
    int i=0;
    while (archClientes >> cliente) {
        arrClientes[i] = cliente;
        i++;
        arrClientes[i].dni = 0;
    }
    int k = 0;
    while (archProducto >> producto) {
        arrProductos[k] = producto;
        k++;
        arrProductos[k]=prodTope;
    }
    
    
    
    int a=0;
    while (archPedido >> pedido) {
        arrProductos += pedido;
        arrClientes += pedido;

    }
    
    
    cabecera(archReporte);

    
    int j = 0;
    while (true) {
        if (arrClientes[j].dni == 0) break;
        else {
            archReporte << arrClientes[j];
        }
        j++;
    }
    int b=0;
    while (true) {
        if (!strcmp(arrProductos[b].codigo,"XXXXXXX")) break;
        else {
            archReporte << arrProductos[b];
        }
        b++;
    }
    
    
    return 0;
}

