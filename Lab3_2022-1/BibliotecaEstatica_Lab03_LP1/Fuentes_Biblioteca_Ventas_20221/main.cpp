/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 2 de abril de 2024, 8:49
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Estruturas.h"
#include "AperturaDeArchivos.h"
#include "Sobrecargados.hpp"

using namespace std;

int main(int argc, char** argv) {
    ifstream archClientes, archPedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Clientes.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "Pedidos.txt");

    Estructura_ClienteRegistrado Cliente, Cliente2, Cliente3, Cliente4, Cliente5, Cliente6, Cliente7;
    Estructura_PedidoRealizado Pedido;
    archClientes >> Cliente >> Cliente2 >> Cliente3 >> Cliente4 >> Cliente5 >> Cliente6>>Cliente7;
    cout << Cliente.categoria << endl;
    cout << Cliente2.categoria << endl;
    cout << Cliente3.nombre << endl;
    cout << Cliente4.nombre << endl;
    cout << Cliente5.nombre << endl;
    cout << Cliente6.nombre << endl;
    cout << Cliente7.nombre << endl;

    struct Estructura_ClienteRegistrado arrClientes[10] = {};




    Pedido.cantidad = 10;
    strcpy(Pedido.codigo, "ABD235");
    Pedido.descuento = 0.3;
    Pedido.fecha = 28082021;
    Pedido.precioUnitario = 50;

    Cliente += Pedido;
    arrClientes += Cliente;
    arrClientes += Cliente2;


    cout << arrClientes[0].pedidosRealizados[0].cantidad << endl;
    cout << arrClientes[0].pedidosRealizados[0].codigo << endl;
    cout << arrClientes[0].pedidosRealizados[0].descuento << endl;
    cout << arrClientes[0].pedidosRealizados[0].fecha << endl;
    cout << arrClientes[0].pedidosRealizados[0].precioUnitario << endl;
    cout << arrClientes[0].montoTotalGastado << endl;
    cout << arrClientes[0].numeroDePedidos << endl;

    Estructura_ProductosEnAlmacen arrProductos[10];
    //Inicializar el arreglo de productos
    
    strcpy(arrProductos[0].codigo,"X");

    Estructura_ProductosEnAlmacen prod, prod2, prod3, prod4, prod5;
    
    strcpy(prod.codigo,"WDW527");
    strcpy(prod.descripcion,"Papaya");
    prod.descuento=3.18;
    prod.precioUnitario=8.23;
    arrProductos += prod;

    ofstream archImprimirCli,archImprimirProd;
    AperturaDeUnArchivoDeTextosParaEscribir(archImprimirCli, "ImprimirClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archImprimirProd, "ImprimirProductos.txt");

    archImprimirCli<<Cliente;
    archImprimirProd<<arrProductos;


    return 0;
}

