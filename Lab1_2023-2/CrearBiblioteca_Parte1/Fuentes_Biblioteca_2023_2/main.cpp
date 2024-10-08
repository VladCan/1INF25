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

    ifstream archClientes, archProducto, archPedido;
    ofstream archReporteCliente, archReporteProducto;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProducto, "Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedido, "Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteCliente, "Reporte_Cliente.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteProducto, "Reporte_Producto.txt");

    struct Cliente cliente;
    struct Producto producto,prodTope;
    strcpy(prodTope.codigo,"XXXXXXX");
    struct Pedido pedido;
    int i = 0;
    struct Cliente arrClientes[150];
    struct Producto arrProductos[170];
    arrClientes[0] = cliente;
    
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
        cout<<a<<endl;
        a++;
        if (a==58)
            cout<<"Hola"<<endl;
        arrProductos += pedido;
        arrClientes += pedido;

    }






    int j = 0;
    while (true) {
        if (arrClientes[j].dni == 0) break;
        else {
            archReporteCliente << arrClientes[j];
        }
        j++;
    }
    int b=0;
    while (true) {
        if (!strcmp(arrProductos[b].codigo,"XXXXXXX")) break;
        else {
            archReporteProducto << arrProductos[b];
        }
        b++;
    }

    return 0;
}

